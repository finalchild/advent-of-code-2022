#include <algorithm>
#include <array>
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 score = 0;
    while (cin.peek() != char_traits<char>::eof()) {
        char c1, c2; cin >> c1 >> c2;
        i32 a = c1 - 'A'; i32 b = c2 - 'X';
        score += b + 1 + (
                a == b ? 3 :
                a == (b + 1) % 3 ? 0 : 6
                );
        if (cin.peek() == '\n') cin.get();
    }

    cout << score << '\n';
    return 0;
}
