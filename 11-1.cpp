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

struct Monkey {
    vector<i64> items;
    char op;
    optional<i64> lhs;
    optional<i64> rhs;
    i32 test_div;
    i32 next_true;
    i32 next_false;
    i32 inspected = 0;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<Monkey> monkeys;
    i32 mod = 1;
    while (cin.peek() != char_traits<char>::eof()) {
        Monkey& monkey = monkeys.emplace_back();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cin.ignore(numeric_limits<streamsize>::max(), ':');
        while (cin.peek() != char_traits<char>::eof() && cin.peek() != '\n') {
            i32 item; cin >> item;
            monkey.items.push_back(item);
            if (cin.peek() == ',') cin.ignore();
        }

        cin.ignore(numeric_limits<streamsize>::max(), '='); cin >> ws;
        if (cin.peek() == 'o') {
            cin.ignore(3);
        } else {
            i32 lhs; cin >> lhs; monkey.lhs = lhs;
        }
        cin >> ws;
        monkey.op = cin.get();
        cin >> ws;
        if (cin.peek() == 'o') {
            cin.ignore(3);
        } else {
            i32 rhs; cin >> rhs; monkey.rhs = rhs;
        }

        cin.ignore(numeric_limits<streamsize>::max(), 'y');
        cin >> monkey.test_div;
        cin.ignore(numeric_limits<streamsize>::max(), 'y');
        cin >> monkey.next_true;
        cin.ignore(numeric_limits<streamsize>::max(), 'y');
        cin >> monkey.next_false;

        cin >> ws;
        mod = lcm(mod, monkey.test_div);
    }

    repeat(_, 20) {
        repeat(i, monkeys.size()) {
            Monkey& monkey = monkeys[i];

            for (i64 item : monkey.items) {
                i64 lhs = monkey.lhs.value_or(item), rhs = monkey.rhs.value_or(item);
                switch (monkey.op) {
                    case '+':
                        item = lhs + rhs % mod;
                        break;
                    case '*':
                        item = lhs * rhs % mod;
                        break;
                    default:
                        assert(false);
                }
                item /= 3;
                i32 next_monkey = item % monkey.test_div == 0 ? monkey.next_true : monkey.next_false;
                monkeys[next_monkey].items.push_back(item);
            }
            monkey.inspected += monkey.items.size();
            monkey.items.clear();
        }
    }

    array<i32, 2> mx{};
    for (const Monkey& monkey : monkeys) {
        i32 cnt = monkey.inspected;
        repeat(i, 2) {
            if (cnt > mx[i]) swap(cnt, mx[i]);
        }
    }
    cout << mx[0] * mx[1] << '\n';

    return 0;
}
