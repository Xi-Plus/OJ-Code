// AI generated
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

// 檢查給定的 R 所產生的總獎金是否不超過 L
bool check(int R, int n, long long L, const vector<long long>& p, const vector<int>& prev_ge) {
    long long total_bonus = 0;

    // 從第 2 秒開始檢查，因為第 1 秒不可能成為任何過去時間的新高價
    for (int t = 2; t <= n; ++t) {
        // 計算參賽者 i 的合法區間 [start_i, end_i]
        int start_i = max(prev_ge[t] + 1, t - R);
        int end_i = t - 1;

        if (start_i <= end_i) {
            long long count = end_i - start_i + 1;
            total_bonus += count * p[t];

            // 如果加總過程中已經超過預算 L，提早結束回傳 false
            if (total_bonus > L) {
                return false;
            }
        }
    }
    return total_bonus <= L;
}

int main() {
    // 優化輸入輸出速度
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long L;
    if (!(cin >> n >> L)) return 0;

    vector<long long> p(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
    }

    // prev_ge[t] 記錄在 t 左邊第一個 >= p[t] 的位置
    vector<int> prev_ge(n + 1, 0);
    stack<int> st; // 單調遞減疊代，儲存 index

    for (int t = 1; t <= n; ++t) {
        // 將疊代中比當前價格小的元素全部彈出
        while (!st.empty() && p[st.top()] < p[t]) {
            st.pop();
        }

        if (st.empty()) {
            prev_ge[t] = 0; // 左邊沒有任何元素 >= p[t]
        } else {
            prev_ge[t] = st.top();
        }
        st.push(t);
    }

    // 對 R 進行二分搜尋，範圍從 0 到 n - 1
    int left = 0, right = n - 1;
    int ans = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (check(mid, n, L, p, prev_ge)) {
            ans = mid;         // 記錄當前合法的最大 R
            left = mid + 1;    // 繼續往更大的 R 尋找
        } else {
            right = mid - 1;   // 超出預算 L，必須縮小 R
        }
    }

    // 輸出最大的合法 R
    cout << ans << "\n";

    return 0;
}
