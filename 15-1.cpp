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

    vector<pair<i32, bool>> events; // (x, is_end)
    i32 result = 0;
    while (cin.peek() != char_traits<char>::eof()) {
        cin.ignore("Sensor at x="sv.size());
        i32 x; cin >> x;
        cin.ignore(", y="sv.size());
        i32 y; cin >> y;
        cin.ignore(": closest beacon is at x="sv.size());
        i32 bx; cin >> bx;
        cin.ignore(", y="sv.size());
        i32 by; cin >> by;
        cin.ignore("\n"sv.size());

        i32 d = abs(bx - x) + abs(by - y);
        i32 dx = d - abs(2000000 - y);
        if (dx < 0) continue;
        if (by != 2000000) {
            events.emplace_back(x - dx, false);
            events.emplace_back(x + dx + 1, true);
        } else if (bx < x) {
            events.emplace_back(x - dx + 1, false);
            events.emplace_back(x + dx + 1, true);
        } else if (bx > x) {
            events.emplace_back(x - dx, false);
            events.emplace_back(x + dx, true);
        }
    }
    ranges::sort(events);

    i32 overlap = 0;
    i32 begin = 0;
    for (auto [x, is_end] : events) {
        if (!is_end) {
            if (overlap == 0) {
                begin = x;
            }
            overlap++;
        } else {
            overlap--;
            if (overlap == 0) {
                result += x - begin;
            }
        }
    }
    cout << result << '\n';

    return 0;
}
