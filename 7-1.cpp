#include <algorithm>
#include <array>
#include <cassert>
#include <bit>
#include <functional>
#include <iostream>
#include <limits>
#include <memory>
#include <optional>
#include <set>
#include <string>
#include <vector>
#include <numeric>
#define repeat(i, n) for (decay_t<decltype(n)> i = 0; i < (n); i++)
using namespace std;
using i16 = int16_t;
using i32 = int32_t;
using i64 = int64_t;
using u64 = uint64_t;

struct string_hash {
    using hash_type = std::hash<std::string_view>;
    using is_transparent = void;

    std::size_t operator()(const char* str) const        { return hash_type{}(str); }
    std::size_t operator()(std::string_view str) const   { return hash_type{}(str); }
    std::size_t operator()(std::string const& str) const { return hash_type{}(str); }
};

struct Directory {
    unordered_map<string, unique_ptr<Directory>, string_hash, equal_to<>> subdirs;
    optional<reference_wrapper<Directory>> parent;
    i64 file_sz = -1;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Directory root;
    reference_wrapper<Directory> cwd = root;

    while (cin.peek() != char_traits<char>::eof()) {
        string line; getline(cin, line);
        if (line == "$ cd /") {
            cwd = root;
        } else if (line == "$ cd ..") {
            cwd = cwd.get().parent.value();
        } else if (line.starts_with("$ cd ")) {
            string_view subdir_name(line.cbegin() + "$ cd "sv.length(), line.cend());
            auto it = cwd.get().subdirs.find(subdir_name);
            if (it != cwd.get().subdirs.cend()) {
                cwd = ref(*it->second);
            } else {
                it = cwd.get().subdirs.emplace_hint(it, subdir_name, make_unique<Directory>());
                it->second->parent = cwd;
            }
            cwd = *it->second;
        } else if (line.starts_with("$ ls")){
            cwd.get().file_sz = 0;
            while (true) {
                if (cin.peek() == char_traits<char>::eof() || cin.peek() == '$') break;
                if (cin.peek() != 'd') {
                    i64 sz; cin >> sz;
                    cwd.get().file_sz += sz;
                }
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } else {
            assert(false);
        }
        cin >> ws;
    }

    i64 sum = 0;
    function<i64(const Directory&)> dfs = [&](const Directory& dir) -> i64 {
        i64 total_sz = dir.file_sz;
        for (const auto& [_, subdir] : dir.subdirs) {
            total_sz += dfs(*subdir);
        }
        if (total_sz <= 100000) sum += total_sz;
        return total_sz;
    };
    dfs(root);
    cout << sum << '\n';

    return 0;
}
