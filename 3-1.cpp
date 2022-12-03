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
        string s; cin >> s;
        i64 first_half = 0; i64 second_half = 0;
        repeat(i, s.size() / 2) {
            first_half |= 1UL << (s[i] >= 'a' ? s[i] - 'a' : s[i] - 'A' + 26);
        }
        for (i32 i = s.size() / 2; i < s.size(); i++) {
            second_half |= 1UL << (s[i] >= 'a' ? s[i] - 'a' : s[i] - 'A' + 26);
        }
        u64 common = first_half & second_half;
        sum += countr_zero(common) + 1;
        cin.ignore();
    }

    cout << sum << '\n';
    return 0;
}
