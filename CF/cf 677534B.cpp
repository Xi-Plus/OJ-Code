// AI generated
#include <iostream>
#include <vector>

using namespace std;

// 記錄每個圓盤初始所在的柱子 (0:A, 1:B, 2:C)
int pos[25];

// 用來儲存所有移動步驟的陣列
vector<pair<char, char>> moves;

// 標準河內塔遞迴：將 disk 個圓盤從 source 移到 target
void move_standard(int disk, int source, int target) {
    if (disk == 0) return;
    int aux = 3 - source - target;

    move_standard(disk - 1, source, aux);
    // 將步驟存入 vector 中，取代直接 cout
    moves.push_back({(char)('A' + source), (char)('A' + target)});
    move_standard(disk - 1, aux, target);
}

// 散落狀態河內塔遞迴：將 1~disk 號圓盤移到 target
void move_scattered(int disk, int target) {
    if (disk == 0) return;

    if (pos[disk] == target) {
        // 最大圓盤已在目標，直接處理剩下的
        move_scattered(disk - 1, target);
    } else {
        // 最大圓盤不在目標，需借助輔助柱
        int aux = 3 - pos[disk] - target;
        move_scattered(disk - 1, aux);

        // 將自己歸位的步驟存入 vector
        moves.push_back({(char)('A' + pos[disk]), (char)('A' + target)});

        move_standard(disk - 1, aux, target);
    }
}

int main() {
    // 效能優化：加速 I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m;
    if (!(cin >> m)) return 0;

    // 讀取初始狀態
    for (int p = 0; p < 3; ++p) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            int disk;
            cin >> disk;
            pos[disk] = p;
        }
    }

    // 效能優化：預先配置最大可能的記憶體空間 (2^m)
    // 避免 vector 擴充時不斷複製舊資料導致 TLE
    moves.reserve(1 << m);

    // 執行遞迴，將所有步驟存入 moves
    int target_peg = 1; // 目標是柱子 B (代號 1)
    move_scattered(m, target_peg);

    // 1. 直接用 vector 的大小作為總步數 k 輸出
    cout << moves.size() << '\n';

    // 2. 跑迴圈一口氣印出所有儲存的步驟
    for (const auto& step : moves) {
        cout << step.first << " " << step.second << '\n';
    }

    return 0;
}
