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
#define self (*this)
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

    vector<tuple<i32, bool, i32, i32>> events_odd; // (xmy, is_end, xpy1, xpy2)
    vector<tuple<i32, bool, i32, i32>> events_even; // (xmy, is_end, xpy1, xpy2)
    vector<i32> xpys{0, 4000000, 8000000};
    while (cin.peek() != char_traits<char>::eof()) {
        cin.ignore("Sensor at x="sv.size());
        i32 cx; cin >> cx;
        cin.ignore(", y="sv.size());
        i32 cy; cin >> cy;
        cin.ignore(": closest beacon is at x="sv.size());
        i32 bx; cin >> bx;
        cin.ignore(", y="sv.size());
        i32 by; cin >> by;
        cin.ignore("\n"sv.size());

        i32 d = abs(bx - cx) + abs(by - cy);
        i32 xpy1 = cx + cy - d, xpy2 = cx + cy + d + 1, xmy1 = cx - cy - d, xmy2 = cx - cy + d + 1;
        events_odd.emplace_back(xmy1 | 1, false, xpy1, xpy2);
        events_odd.emplace_back(xmy2 | 1, true, xpy1, xpy2);
        events_even.emplace_back(xmy1 + 1 & -2, false, xpy1, xpy2);
        events_even.emplace_back(xmy2 + 1 & -2, true, xpy1, xpy2);
        if (xpy1 - 1 > 0 && xpy1 - 1 < 8000000) xpys.push_back(xpy1 - 1);
        if (xpy2 > 0 && xpy2 < 8000000) xpys.push_back(xpy2);
    }
    ranges::sort(events_odd);
    ranges::sort(events_even);
    ranges::sort(xpys);
    {auto [begin, end] = ranges::unique(xpys); xpys.erase(begin, end);}

    i32 result_x, result_y;
    for (i32 xpy : xpys) {
        i32 xmy_begin = -min(xpy, 8000000 - xpy), xmy_end = min(xpy, 8000000 - xpy) + 1;

        i32 overlap = 0;
        for (auto [xmy, is_end, xpy1, xpy2] : xpy % 2 == 0 ? events_even : events_odd) {
            if (xpy < xpy1 || xpy >= xpy2) continue;
            if (!is_end) {
                if (overlap == 0 && xmy - 2 >= xmy_begin && xmy - 2 < xmy_end) {
                    result_x = (xpy + xmy) / 2 - 1;
                    result_y = (xpy - xmy) / 2 + 1;
                    goto break_loop;
                }
                overlap++;
            } else {
                overlap--;
                if (overlap == 0 && xmy >= xmy_begin && xmy < xmy_end) {
                    result_x = (xpy + xmy) / 2;
                    result_y = (xpy - xmy) / 2;
                    goto break_loop;
                }
            }
        }
    }
    break_loop:;
    cout << result_x * 4000000ll + result_y << '\n';

    return 0;
}
