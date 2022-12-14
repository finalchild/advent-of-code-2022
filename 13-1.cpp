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

    i32 sum = 0;
    i32 pair_idx = 1;
    vector<char> left, right;
    vector<char> tmp;
    while (cin.peek() != char_traits<char>::eof()) {
        left.clear(); right.clear();
        while (cin.peek() != '\n') left.push_back(cin.get());
        cin.ignore();
        while (cin.peek() != char_traits<char>::eof() && cin.peek() != '\n') right.push_back(cin.get());
        cin >> ws;
        ranges::reverse(left); ranges::reverse(right);

        while (true) {
            if (left.empty()) {
                sum += pair_idx;
                goto next_pair;
            }
            char l = left.back(), r = right.back();

            if (l == ']' && r == ']' || l == '[' && r == ']') {
                left.pop_back(); right.pop_back();
            } else if (l == ']') {
                sum += pair_idx;
                goto next_pair;
            } else if (r == ']') {
                goto next_pair;
            } else if (l == '[') {
                tmp.clear();
                while (right.back() >= '0' && right.back() <= '9') {
                    tmp.push_back(right.back());
                    right.pop_back();
                }
                right.push_back(']');
                right.insert(right.cend(), tmp.crbegin(), tmp.crend());
                left.pop_back();
            } else if (r == '[') {
                tmp.clear();
                while (left.back() >= '0' && left.back() <= '9') {
                    tmp.push_back(left.back());
                    left.pop_back();
                }
                left.push_back(']');
                left.insert(left.cend(), tmp.crbegin(), tmp.crend());
                right.pop_back();
            } else {
                i32 l_num = 0, r_num = 0;
                while (left.back() >= '0' && left.back() <= '9') {
                    l_num = l_num * 10 + left.back() - '0';
                    left.pop_back();
                }
                while (right.back() >= '0' && right.back() <= '9') {
                    r_num = r_num * 10 + right.back() - '0';
                    right.pop_back();
                }
                if (l_num < r_num) {
                    sum += pair_idx;
                    goto next_pair;
                } else if (l_num > r_num) {
                    goto next_pair;
                }
                // else do nothing
            }

            if (left.back() == ',') left.pop_back();
            if (right.back() == ',') right.pop_back();
        }

        next_pair:;
        pair_idx++;
    }
    cout << sum << '\n';
    return 0;
}
