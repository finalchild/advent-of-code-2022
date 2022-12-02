#include <algorithm>
#include <array>
#include <functional>
#include <iostream>
#include <limits>
#include <set>
#include <vector>
#include <numeric>
#include <fstream>

#define repeat(i, n) for (decay_t<decltype(n)> i = 0; i < (n); i++)
using namespace std;
using i16 = int16_t;
using i32 = int32_t;
using i64 = int64_t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 mx = 0;
    while (cin.peek() != char_traits<char>::eof()) {
        i64 sum = 0;
        while (cin.peek() != char_traits<char>::eof() && cin.peek() != '\n') {
            i64 n; cin >> n;
            sum += n;
            if (cin.peek() == '\n') cin.get();
        }
        if (sum > mx) mx = sum;
        if (cin.peek() == '\n') cin.get();
    }

    cout << mx << '\n';
    return 0;
}
