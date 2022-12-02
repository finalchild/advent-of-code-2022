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

    array<i64, 3> mx {0};
    while (cin.peek() != char_traits<char>::eof()) {
        i64 sum = 0;
        while (cin.peek() != char_traits<char>::eof() && cin.peek() != '\n') {
            i64 n; cin >> n; sum += n;
            if (cin.peek() == '\n') cin.get();
        }
        for (i32 i = 0; i < 3; i++) {
            if (sum > mx[i]) {
                swap(sum, mx[i]);
            }
        }
        if (cin.peek() == '\n') cin.get();

    }

    cout << reduce(mx.begin(), mx.end()) << '\n';
    return 0;
}
