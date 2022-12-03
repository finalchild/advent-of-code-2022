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

    i64 sum = 0;
    while (cin.peek() != char_traits<char>::eof()) {
        array<string, 3> s{}; repeat(i, 3) cin >> s[i];
        array<u64, 3> bit{};
        repeat(i, 3) {
            for (char c : s[i]) {
                bit[i] |= 1UL << (c >= 'a' ? c - 'a' : c - 'A' + 26);
            }
        }
        u64 common = bit[0] & bit[1] & bit[2];
        sum += countr_zero(common) + 1;
        cin.ignore();
    }

    cout << sum << '\n';
    return 0;
}
