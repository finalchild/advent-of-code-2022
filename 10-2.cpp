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

    i32 cycle = 1;
    i32 reg = 1;
    optional<i32> v;
    while (cycle <= 240) {
        i32 pos = (cycle - 1) % 40;
        cout << (abs(pos - reg) <= 1 ? '#' : '.');
        if (pos == 39) cout << '\n';

        if (v.has_value()) {
            reg += *v;
            v = nullopt;
        } else if (cin.peek() == 'a') {
            cin.ignore(4);
            i32 new_v; cin >> new_v; v = new_v;
        } else if (cin.peek() == 'n'){
            cin.ignore(4);
        } else {
            break;
        }
        cycle++;
        cin >> ws;
    }

    return 0;
}
