// AI generated
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// 定義區間結構
struct Interval {
    int l, r, weight;
};

int main() {
    // 優化 I/O 速度
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n;
    if (!(cin >> m >> n)) return 0;

    // 步驟 1: 讀取並合併相同的區間，統計權重 (出現次數)
    map<pair<int, int>, int> counts;
    int max_r = m; // 記錄最大的座標點
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        counts[{l, r}]++;
        max_r = max(max_r, r);
    }

    vector<Interval> U;
    for (auto const& [range, c] : counts) {
        U.push_back({range.first, range.second, c});
    }

    // 依照區間長度由小到大排序 (長度小的子區間先計算)
    sort(U.begin(), U.end(), [](const Interval& a, const Interval& b) {
        return (a.r - a.l) < (b.r - b.l);
    });

    int k = U.size();
    vector<int> dp(k, 0); // dp[i] 記錄第 i 個唯一區間本身+內部可以選出的最多括號數

    // ends_at[x] 記錄「右端點剛好在 x」的所有唯一區間的索引
    vector<vector<int>> ends_at(max_r + 1);
    for (int i = 0; i < k; ++i) {
        ends_at[U[i].r].push_back(i);
    }

    // 步驟 2: 計算每個區間內部的最佳解
    for (int i = 0; i < k; ++i) {
        int L = U[i].l;
        int R = U[i].r;

        // 1D DP 陣列，計算範圍 [L, R] 內不重疊子區間的最大權重
        vector<int> g(R + 1, 0);

        for (int x = L; x <= R; ++x) {
            if (x > L) {
                g[x] = g[x - 1]; // 預設繼承前一個位置的最佳解
            }

            // 檢查所有在 x 結束的區間
            for (int j : ends_at[x]) {
                // j 必須嚴格落在當前區間 i 內部，且 j 不能是 i 本身
                if (j != i && U[j].l >= L) {
                    int prev = (U[j].l > 0) ? g[U[j].l - 1] : 0;
                    g[x] = max(g[x], prev + dp[j]);
                }
            }
        }
        // 當前區間的最佳解 = 自己本身的數量 + 內部能塞下的最大合法組合數
        dp[i] = U[i].weight + g[R];
    }

    // 步驟 3: 對全域範圍 [1, max_r] 再做一次 DP，找出最終答案
    vector<int> global_g(max_r + 1, 0);
    for (int x = 1; x <= max_r; ++x) {
        global_g[x] = global_g[x - 1];

        for (int j : ends_at[x]) {
            int prev = (U[j].l > 0) ? global_g[U[j].l - 1] : 0;
            global_g[x] = max(global_g[x], prev + dp[j]);
        }
    }

    // 輸出全域的最大可能括號數
    cout << global_g[max_r] << "\n";

    return 0;
}
