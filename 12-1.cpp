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

    vector<vector<i8>> board;
    pair<i8, i8> s, e;
    while (cin.peek() != char_traits<char>::eof()) {
        board.emplace_back();
        while (cin.peek() != char_traits<char>::eof() && cin.peek() != '\n') {
            char c = cin.get();
            if (c == 'S') {
                s = {board.size() - 1, board.back().size()};
                c = 'a';
            } else if (c == 'E'){
                e = {board.size() - 1, board.back().size()};
                c = 'z';
            }
            board.back().push_back(c - 'a');
        }
        cin >> ws;
    }

    constexpr array<pair<i8, i8>, 4> movements{
        make_pair(-1, 0),
        make_pair(1, 0),
        make_pair(0, -1),
        make_pair(0, 1)
    };

    vector<pair<i8, i8>> cur;
    vector<pair<i8, i8>> nxt;
    vector<vector<bool>> added(board.size(), vector<bool>(board.front().size()));
    added[s.first][s.second] = true;
    cur.push_back(s);
    i32 round = 0;
    while (!cur.empty()) {
        nxt.clear();
        for (const auto& point : cur) {
            if (point == e) {
                cout << round << '\n';
                return 0;
            }
            for (const auto& movement : movements) {
                pair<i8, i8> new_point(point.first + movement.first, point.second + movement.second);
                if (
                        new_point.first >= 0 && new_point.first < board.size() &&
                        new_point.second >= 0 && new_point.second < board.front().size() &&
                        !added[new_point.first][new_point.second] &&
                        board[new_point.first][new_point.second] <= board[point.first][point.second] + 1
                ) {
                    added[new_point.first][new_point.second] = true;
                    nxt.push_back(new_point);
                }
            }
        }
        swap(cur, nxt);
        round++;
    }
    assert(false);
}
