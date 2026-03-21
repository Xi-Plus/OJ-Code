// AI generated
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 優化輸入輸出速度
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n;
    if (!(cin >> m >> n)) return 0;

    // 為了安全涵蓋 0-indexed 到可能的 1-indexed，陣列開到 m + 5
    int max_val = m + 2;
    vector<vector<int>> C(max_val, vector<int>(max_val, 0));
    vector<vector<int>> dp(max_val, vector<int>(max_val, 0));
    vector<vector<int>> ends_at(max_val);

    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        // 紀錄右端點為 r 的所有「不重複」左端點
        if (C[l][r] == 0) {
            ends_at[r].push_back(l);
        }
        // 累加完全相同區間的括號數量
        C[l][r]++;
    }

    // 動態規劃：L 由大到小，R 由小到大
    for (int L = m; L >= 0; --L) {
        for (int R = L; R <= m; ++R) {
            // Base case: 如果 R > 0，至少可以繼承 [L, R-1] 的答案
            int best = (R > 0) ? dp[L][R - 1] : 0;

            // 嘗試將現有的區間 [K, R] 作為右側的最外層組合
            for (int K : ends_at[R]) {
                if (K > L) {
                    best = max(best, dp[L][K - 1] + dp[K][R]);
                }
            }
            // 加上剛好等於 [L, R] 的括號總數
            dp[L][R] = best + C[L][R];
        }
    }

    // 輸出整個範圍 [0, m] 內能放入的最大括號數
    cout << dp[0][m] << "\n";

    return 0;
}
