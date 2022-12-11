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

    pair<i32, i32> h, t;
    unordered_set<pair<i32, i32>, decltype([](const pair<i32, i32>& p) -> size_t {
        return hash<u64>()((static_cast<u64>(static_cast<u32>(p.first)) << 32) + static_cast<u32>(p.second));
    })> visited;
    visited.insert(t);
    while (cin.peek() != char_traits<char>::eof()) {
        char cmd; i32 cnt; cin >> cmd >> cnt >> ws;
        switch (cmd) {
            case 'L': h.first -= cnt; break;
            case 'R': h.first += cnt; break;
            case 'U': h.second -= cnt; break;
            case 'D': h.second += cnt; break;
            default: assert(false);
        }
        while (abs(h.first - t.first) > 1 || abs(h.second - t.second) > 1) {
            if (t.first < h.first) t.first++; else if (t.first > h.first) t.first--;
            if (t.second < h.second) t.second++; else if (t.second > h.second) t.second--;
            visited.insert(t);
        }
    }
    cout << visited.size() << '\n';

    return 0;
}
