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

    i64 cnt = 0;
    while (cin.peek() != char_traits<char>::eof()) {
        i32 a; cin >> a; cin.get(); i32 b; cin >> b; cin.get();
        i32 c; cin >> c; cin.get(); i32 d; cin >> d;
        if (a <= c && b >= d || c <= a && d >= b) cnt++;
        cin.ignore();
    }

    cout << cnt << '\n';
    return 0;
}
