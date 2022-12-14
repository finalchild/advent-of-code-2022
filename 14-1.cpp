#include <algorithm>
#include <array>
#include <cassert>
#include <bit>
#include <deque>
#include <functional>
#include <iostream>
#include <limits>
#include <memory>
#include <numeric>
#include <optional>
#include <set>
#include <sstream>
#include <string>
#include <type_traits>
#include <unordered_set>
#include <vector>
#define repeat(i, n) for (decay_t<decltype(n)> i = 0; i < (n); i++)
#define repeat_rev(i, n) for (conditional_t<is_unsigned_v<decay_t<decltype(n)>>, make_signed_t<decay_t<decltype(n)>>, decay_t<decltype(n)>> i = (n) - 1; i >= 0; i--)
using namespace std;
using i8 = int8_t;
using i16 = int16_t;
using i32 = int32_t;
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<pair<pair<i32, i32>, pair<i32, i32>>> lines;
    i32 max_y = 0;
    while (cin.peek() != char_traits<char>::eof()) {
        pair<i32, i32> p1; cin >> p1.first; cin.ignore(); cin >> p1.second;
        if (p1.second > max_y) max_y = p1.second;
        while (cin.peek() == ' ') {
            cin.ignore(" -> "sv.size());
            pair<i32, i32> p2; cin >> p2.first; cin.ignore(); cin >> p2.second;
            if (p2.second > max_y) max_y = p2.second;
            lines.emplace_back(p1, p2);
            p1 = p2;
        }
        cin >> ws;
    }
    max_y++;
    i32 min_x = 500 - max_y;
    vector<vector<bool>> board(max_y * 2 + 1, vector<bool>(max_y + 1));
    for (auto& [p1, p2] : lines) {
        p1.first -= min_x;
        p2.first -= min_x;

        if (p1.first > p2.first) swap(p1.first, p2.first);
        if (p1.second > p2.second) swap(p1.second, p2.second);

        for (i32 i = max(0, p1.first); i <= min(max_y * 2, p2.first); i++) {
            for (i32 j = p1.second; j <= p2.second; j++) {
                board[i][j] = true;
            }
        }
    }

    i32 cnt = 0;
    function<bool(i32, i32)> dfs = [&](i32 x, i32 y) -> bool {
        if (y > max_y) return true;
        if (board[x][y]) return false;
        if (dfs(x, y + 1) || dfs(x - 1, y + 1) || dfs(x + 1, y + 1)) return true;
        board[x][y] = true;
        cnt++;
        return false;
    };
    dfs(max_y, 0);
    cout << cnt << '\n';
}
