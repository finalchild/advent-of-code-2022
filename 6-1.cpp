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

    array<i32, 26> last_idx_of_char;
    ranges::fill(last_idx_of_char, -1);
    i32 dup_until = 3;
    for (i32 idx = 0; cin.peek() != char_traits<char>::eof() && cin.peek() != '\n'; idx++) {
        i32 c = cin.get() - 'a';
        dup_until = max(dup_until, last_idx_of_char[c] + 4);
        if (idx >= dup_until) {
            cout << idx + 1 << '\n';
            return 0;
        }
        last_idx_of_char[c] = idx;
    }

    return 0;
}
