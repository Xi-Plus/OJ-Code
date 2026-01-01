// AI generated
#include <iostream>
#include <vector>
#include <numeric>
#include <queue>
#include <algorithm>

using namespace std;

// 根據題目限制的最大節點數
const int MAXN = 200005;

// 全域變數儲存圖和狀態
int N, Q;
int A[MAXN];                // Functional Graph: i -> A[i]
vector<int> rev_adj[MAXN];  // 反向圖: A[i] -> {i, ...}
int in_degree[MAXN];        // 入度 (用於拓撲排序)
bool on_cycle[MAXN];        // 標記節點是否在環上

// 環的資料結構
// cycles[id] 依序儲存環上的節點
vector<vector<int>> cycles;
// cycle_pref[id] 儲存環節點的前綴和
vector<vector<long long>> cycle_pref;
// node_cycle_info[u] = {環ID, 環內索引}
pair<int, int> node_cycle_info[MAXN];

// 查詢結構
struct Query {
    int id;      // 原始查詢的索引
    long long T; // 操作次數
};
vector<Query> queries[MAXN]; // queries[u] 儲存從桶子 u 出發的查詢
long long answers[MAXN];     // 儲存答案

// DFS 路徑堆疊 (儲存節點編號)
// 我們同時維護堆疊的前綴和，以便 O(1) 計算區間和
vector<long long> path_sum_stack;

// 計算從 start_idx 之後開始走 steps 步在環上的總和
// 注意：桶子到達環節點 C，加入 C 的水，然後移動到 next(C)。
// 如果我們需要在環上模擬 'steps' 步，第一個加入的水量來自 next(start_idx)。
long long get_cycle_sum(int cycle_id, int start_idx, long long steps) {
    if (steps <= 0) return 0;

    const vector<int>& nodes = cycles[cycle_id];
    const vector<long long>& pref = cycle_pref[cycle_id];
    long long len = nodes.size();
    long long total_cycle_sum = pref[len];

    // 環繞的完整圈數
    long long laps = steps / len;
    long long rem = steps % len;

    long long result = laps * total_cycle_sum;

    if (rem > 0) {
        // 我們需要從 (start_idx + 1) 開始計算 'rem' 個節點的總和
        // 因為 'start_idx' 是樹部分的最後一個節點 (或前一步的環節點)
        int current_idx = (start_idx + 1) % len;

        // 計算環狀陣列的區間和
        // 區間: [current_idx, current_idx + rem - 1] (循環)

        int end_idx = (current_idx + rem - 1) % len;

        if (end_idx >= current_idx) {
            // 沒有跨越前綴和陣列的尾部
            // sum[current ... end] = pref[end+1] - pref[current]
            result += (pref[end_idx + 1] - pref[current_idx]);
        } else {
            // 跨越尾部
            // sum[current ... len-1] + sum[0 ... end]
            result += (pref[len] - pref[current_idx]);
            result += (pref[end_idx + 1]);
        }
    }

    return result;
}

// DFS 處理樹上的查詢
// u: 當前節點
// c_id: 這棵樹所連接的環 ID
// c_idx: 這棵樹的根 (環上節點) 在環中的索引
void dfs(int u, int c_id, int c_idx) {
    // 將當前節點推入堆疊並更新前綴和
    long long current_val = u;
    long long prev_sum = path_sum_stack.empty() ? 0 : path_sum_stack.back();
    path_sum_stack.push_back(prev_sum + current_val);

    // 處理所有從桶子 u 出發的查詢
    for (const auto& q : queries[u]) {
        long long T = q.T;
        long long depth = path_sum_stack.size(); // 包含 u 在內的樹路徑節點數

        if (T < depth) {
            // 桶子還在樹的路徑上
            // 我們需要堆疊中最後 T 個節點的總和
            // 堆疊: [ ... (start), ... (end=u) ]
            // 我們需要區間 [depth - T, depth - 1] 的和 (0-based index)
            // 公式: pref[depth] - pref[depth - T]

            long long val = path_sum_stack.back();
            // 注意: path_sum_stack 大小為 'depth'。
            // 索引 i 的元素是前 i+1 個元素的和。
            // 最後 T 個元素的和 = stack[last] - stack[last - T]

            // 調整 0-based vector 存取:
            // stack[depth-1] 是總和。
            // stack[depth-1-T] 是我們需要的片段之前的和。

            long long total_now = path_sum_stack.back();
            long long sub = 0;
            if (depth - 1 - T >= 0) {
                sub = path_sum_stack[depth - 1 - T];
            }
            answers[q.id] = total_now - sub;
        } else {
            // 桶子進入了環
            // 1. 取樹路徑的完整總和
            long long tree_sum = path_sum_stack.back();

            // 2. 計算環上剩餘的步數
            long long rem_steps = T - depth;

            // 3. 加上環部分的總和
            // 樹路徑結束於環節點 (也就是我們 DFS 的根)。
            // 該環節點在環中的索引為 'c_idx'。
            // 下一步將會移動到 c_idx 之後的節點。
            long long cycle_part = get_cycle_sum(c_id, c_idx, rem_steps);

            answers[q.id] = tree_sum + cycle_part;
        }
    }

    // 遞迴到反向圖的子節點 (在原圖中是往樹上爬)
    for (int v : rev_adj[u]) {
        if (!on_cycle[v]) { // 只移動到樹節點
            dfs(v, c_id, c_idx);
        }
    }

    // 回溯 (Backtrack)
    path_sum_stack.pop_back();
}

int main() {
    // 優化 I/O 操作
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> N >> Q)) return 0;

    // 1. 讀取圖並建立反向圖
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
        rev_adj[A[i]].push_back(i);
        in_degree[A[i]]++;
    }

    // 2. 讀取查詢
    // 格式: T B (求 T 次操作後桶子 B 中的水量)
    for (int i = 0; i < Q; ++i) {
        long long t;
        int b;
        cin >> t >> b;
        queries[b].push_back({i, t});
    }

    // 3. 拓撲排序識別環
    queue<int> q;
    for (int i = 1; i <= N; ++i) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }

    // 剝離樹節點
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        int v = A[u];
        in_degree[v]--;
        if (in_degree[v] == 0) {
            q.push(v);
        }
    }

    // 4. 提取環並預處理
    // 入度 > 0 的節點即在環上
    fill(on_cycle, on_cycle + N + 1, false);

    for (int i = 1; i <= N; ++i) {
        if (in_degree[i] > 0 && !on_cycle[i]) {
            int curr = i;
            vector<int> cycle_nodes;

            // 遍歷環
            while (!on_cycle[curr]) {
                on_cycle[curr] = true;
                cycle_nodes.push_back(curr);
                curr = A[curr];
            }

            // 註冊環資訊
            int c_id = cycles.size();
            for (int k = 0; k < cycle_nodes.size(); ++k) {
                int node = cycle_nodes[k];
                node_cycle_info[node] = {c_id, k};
            }

            // 計算該環的前綴和
            vector<long long> pref;
            pref.push_back(0);
            long long current_sum = 0;
            for (int node : cycle_nodes) {
                current_sum += node;
                pref.push_back(current_sum);
            }

            cycles.push_back(cycle_nodes);
            cycle_pref.push_back(pref);
        }
    }

    // 5. 從環節點開始 DFS 進入樹
    // 我們遍歷所有節點。如果一個節點在環上，它就作為 DFS 的根。
    for (int i = 1; i <= N; ++i) {
        if (on_cycle[i]) {
            // 確定該節點屬於哪個環以及索引
            int c_id = node_cycle_info[i].first;
            int c_idx = node_cycle_info[i].second;

            // 開始 DFS
            // 注意: 環節點本身也是路徑的一部分，所以我們在 DFS 中處理它。
            // 但是，我們必須確保不會通過 rev_adj 遍歷回其他環節點。

            // 為了安全起見清空堆疊 (雖然在前一次 DFS 後它應該是空的)
            path_sum_stack.clear();
            dfs(i, c_id, c_idx);
        }
    }

    // 6. 輸出答案
    for (int i = 0; i < Q; ++i) {
        cout << answers[i] << "\n";
    }

    return 0;
}
