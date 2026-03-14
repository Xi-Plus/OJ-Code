// AI generated
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 500005;

// dp[u][0]: u 不開店
// dp[u][1]: u 開店，且父節點不開 (最多選 m 個子節點開店)
// dp[u][2]: u 開店，且父節點有開 (最多選 m-1 個子節點開店)
long long dp[MAXN][3];
long long w[MAXN];
vector<int> adj[MAXN];
int n, m;

void dfs(int u, int p) {
    long long sum_not_chosen = 0;
    vector<long long> diffs;

    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u); // 遞迴計算子節點

        // 累積 u 不開店時，子樹的最大收益
        sum_not_chosen += max(dp[v][0], dp[v][1]);

        // 計算子節點 v 從「不開」變成「開」的收益差額
        diffs.push_back(dp[v][2] - dp[v][0]);
    }

    // --- 狀態 0：u 不開店 ---
    dp[u][0] = sum_not_chosen;

    // 將收益差額由大到小排序，準備進行貪婪選擇
    sort(diffs.rbegin(), diffs.rend());

    // 假設一開始所有子節點都不開店，這是 u 開店的基本收益
    long long base_chosen = w[u];
    for(int v : adj[u]) {
        if (v != p) {
            base_chosen += dp[v][0];
        }
    }

    // --- 狀態 1：u 開店，父節點不開 (限額 m) ---
    long long add1 = 0;
    int limit1 = min((int)diffs.size(), m);
    for (int i = 0; i < limit1; ++i) {
        if (diffs[i] > 0) add1 += diffs[i];
        else break; // 排序過，若小於等於 0，後面的也不用看了
    }
    dp[u][1] = base_chosen + add1;

    // --- 狀態 2：u 開店，父節點有開 (限額 m - 1) ---
    long long add2 = 0;
    int limit2 = min((int)diffs.size(), m - 1);
    for (int i = 0; i < limit2; ++i) {
        if (diffs[i] > 0) add2 += diffs[i];
        else break;
    }
    dp[u][2] = base_chosen + add2;
}

int main() {
    // 優化輸入輸出速度 (對於 5x10^5 級別的測資非常重要)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> n >> m)) return 0;

    for (int i = 1; i <= n; ++i) {
        cin >> w[i];
    }

    // 建立樹的雙向邊
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // 以節點 1 為根節點 (0 為虛擬父節點) 開始 DFS
    dfs(1, 0);

    // 最終答案為：根節點「不開」或「開且無父節點(等同狀態1)」兩者取最大值
    cout << max(dp[1][0], dp[1][1]) << "\n";

    return 0;
}
