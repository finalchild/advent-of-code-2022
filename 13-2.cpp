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

    array<i32, 2> cnt{1, 2};
    while (cin.peek() != char_traits<char>::eof()) {
        while (cin.peek() == '[') { cin.ignore(); }
        char c = cin.get();
        if (c == ']' || (cin.peek() == ',' || cin.peek() == ']') && c < '2') {
            cnt[0]++;
            cnt[1]++;
        } else if ((cin.peek() == ',' || cin.peek() == ']') && c < '6') {
            cnt[1]++;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> ws;
    }
    cout << cnt[0] * cnt[1] << '\n';
    return 0;
}
