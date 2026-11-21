---
name: atcoder
description: 把根目錄剛寫完的 AtCoder 解答（cph 依題名產生的檔名，如 Same_Side.cpp）改名移進 AtCoder/、刪除 .cph 對應的 .prob，並 commit。使用者貼上 AtCoder 比賽的題目表（Task / Task Name / Time Limit…）並給比賽 id（如 abc485、arc190）時使用。
---

# AtCoder 比賽解答歸檔

輸入：使用者貼的題目表 + 比賽 id（例如 `abc485`）。

## 1. 解析

- 比賽 id 拆成前綴與編號：`abc485` → 前綴 `abc`、編號 `485`。前綴一律小寫。
- 題目表每列取「題號字母」與「題名」，例如 `A	Same Side` → (`A`, `Same Side`)。

## 2. 對應檔名

cph 產生的檔名 = 題名中每個非英數字元換成 `_`，再加 `.cpp`：

- `Same Side` → `Same_Side.cpp`
- `ABC|ABC|ABC` → `ABC_ABC_ABC.cpp`

若算出的名字在根目錄找不到，用 `ls *.cpp` 比對看看（可能有連續 `_` 或結尾差異），找到最接近的再用；仍找不到就視為該題沒寫。

目標檔名：`AtCoder/<前綴> <編號><字母>.cpp`，例如 `AtCoder/abc 485A.cpp`（前綴與編號之間有一個空格，字母大寫）。

## 3. 執行（Bash，在 repo 根目錄）

對每一題：

1. 根目錄有對應 `.cpp` → `mv` 到目標檔名。目標已存在就停下來問使用者，不要覆蓋。
2. 刪除 `.cph/.<cph檔名>_*.prob`（例如 `.cph/.Same_Side.cpp_*.prob`）。**表中每一題都刪**，包含沒寫 `.cpp` 的題目（例如沒解出的 F）。
3. 根目錄若有同名 `.exe`，一起刪掉。

不在題目表內的根目錄檔案（例如其他 OJ 的題目）不要動，`.cph` 中它們的 `.prob` 也不要動。

## 4. Commit

```bash
git add "AtCoder/<前綴> <編號>"*.cpp
git commit -m "Add <前綴> <編號>"
```

例如 `Add abc 485`。只 add 這次移進去的檔案，不要 `git add -A`。不要 push。

`.cph/` 已被 `.gitignore` 忽略，刪除它不會出現在 commit。

## 5. 回報

列出：移動了哪些檔（舊名 → 新名）、刪了哪些 `.prob`、沒寫的題號、commit hash。
