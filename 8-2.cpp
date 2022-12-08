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
    while (cin.peek() != char_traits<char>::eof()) {
        string s; cin >> s >> ws;
        board.emplace_back();
        board.back().reserve(s.size());
        for (char c : s) {
            board.back().push_back(c - '0');
        }
    }

    i64 mx = 0;
    repeat(i, board.size()) repeat(j, board[i].size()) {
        i32 u = 0;
        for (i32 i2 = i - 1; i2 >= 0; i2--) {
            u++;
            if (board[i2][j] >= board[i][j]) break;
        }
        i32 d = 0;
        for (i32 i2 = i + 1; i2 < board.size(); i2++) {
            d++;
            if (board[i2][j] >= board[i][j]) break;
        }
        i32 l = 0;
        for (i32 j2 = j - 1; j2 >= 0; j2--) {
            l++;
            if (board[i][j2] >= board[i][j]) break;
        }
        i32 r = 0;
        for (i32 j2 = j + 1; j2 < board[i].size(); j2++) {
            r++;
            if (board[i][j2] >= board[i][j]) break;
        }
        i64 score = static_cast<i64>(u) * d * l * r;
        if (score > mx) mx = score;
    }
    cout << mx << '\n';

    return 0;
}
