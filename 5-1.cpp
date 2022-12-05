#include <algorithm>
#include <array>
#include <bit>
#include <functional>
#include <iostream>
#include <limits>
#include <set>
#include <vector>
#include <numeric>
#define repeat(i, n) for (decay_t<decltype(n)> i = 0; i < (n); i++)
using namespace std;
using i16 = int16_t;
using i32 = int32_t;
using i64 = int64_t;
using u64 = uint64_t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<char>> stacks;
    while (true) {
        string line; getline(cin, line);
        if (line[1] == '1') break;
        i32 stack_cnt = (line.length() + 3) / 4;
        if (stacks.size() < stack_cnt) stacks.resize(stack_cnt);
        repeat(i, stacks.size()) {
            i32 idx = i * 4 + 1;
            if (idx < line.size() && line[idx] != ' ') {
                stacks[i].push_back(line[idx]);
            }
        }
    }
    for (auto& stack : stacks) ranges::reverse(stack);
    while (true) {
        cin >> ws;
        if (cin.peek() == char_traits<char>::eof()) break;
        cin.ignore(5);
        i32 cnt; cin >> cnt;
        cin.ignore(6);
        i32 src; cin >> src; src--;
        cin.ignore(4);
        i32 dst; cin >> dst; dst--;
        if (src == dst) continue;
        repeat(_, cnt) {
            stacks[dst].push_back(stacks[src].back());
            stacks[src].pop_back();
        }
    }
    for (const auto& stack : stacks) cout << stack.back();
    cout << '\n';

    return 0;
}
