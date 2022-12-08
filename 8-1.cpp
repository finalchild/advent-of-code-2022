#include <algorithm>
#include <array>
#include <cassert>
#include <bit>
#include <functional>
#include <iostream>
#include <limits>
#include <memory>
#include <numeric>
#include <optional>
#include <set>
#include <string>
#include <type_traits>
#include <vector>
#define repeat(i, n) for (decay_t<decltype(n)> i = 0; i < (n); i++)
#define repeat_rev(i, n) for (conditional_t<is_unsigned_v<decay_t<decltype(n)>>, make_signed_t<decay_t<decltype(n)>>, decay_t<decltype(n)>> i = (n) - 1; i >= 0; i--)
using namespace std;
using i8 = int8_t;
using i16 = int16_t;
using i32 = int32_t;
using i64 = int64_t;
using u64 = uint64_t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<i8>> board;
    vector<vector<bool>> visible;
    while (cin.peek() != char_traits<char>::eof()) {
        string s; cin >> s >> ws;
        board.emplace_back();
        board.back().reserve(s.size());
        for (char c : s) {
            board.back().push_back(c - '0');
        }
        visible.emplace_back(s.size());
    }

    repeat(i, board.size()) {
        i64 mx = -1;
        repeat(j, board[i].size()) {
            if (board[i][j] > mx) {
                mx = board[i][j];
                visible[i][j] = true;
            }
        }
        mx = -1;
        repeat_rev(j, board[i].size()) {
            if (board[i][j] > mx) {
                mx = board[i][j];
                visible[i][j] = true;
            }
        }
    }
    repeat(j, board[0].size()) {
        i64 mx = -1;
        repeat(i, board.size()) {
            if (board[i][j] > mx) {
                mx = board[i][j];
                visible[i][j] = true;
            }
        }
        mx = -1;
        repeat_rev(i, board.size()) {
            if (board[i][j] > mx) {
                mx = board[i][j];
                visible[i][j] = true;
            }
        }
    }

    i64 cnt = 0;
    for (const auto& row : visible) for (bool vis : row) {
        if (vis) cnt++;
    }
    cout << cnt << '\n';

    return 0;
}
