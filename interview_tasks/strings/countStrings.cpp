#include <iostream>
#include <vector>
#include <array>
using namespace std;

/*
 * 1. You are given two strings T and P.
 * Write a program, which counts how many time P is found in T.
 * 2. If different occurrences of P in T overlap count each one of them.
 * 3. T = babalabalabalatheend P = alabala
	The string P is found twice in T
 * 4. Both strings will contain only lower-case latin letters (‘a’-’z’)
 *  and will have at least one letter.
 *  The maximum possible length for T is 100,000 and for P - 10,000.
 * */

struct ANode {
    std::array<size_t,'z'-'a'> next;
    size_t suffix;
};

int main() {
    std::string haystack, needle;
    cin >> haystack >> needle;
    const size_t n = needle.size();
    vector<ANode> automata(n+1);
    for (size_t i = 1; i <= n; ++i) {
        automata[i-1].next[needle[i-1]-'a'] = i;
        automata[i].suffix = i==1 ? 0 : automata[automata[i-1].suffix].next[needle[i-1]-'a'];
        automata[i].next = automata[automata[i].suffix].next;
    }
    size_t state = 0;
    int count = 0;
    for (char c: haystack) {
        state = automata[state].next[c-'a'];
        count += state == n;
    }
    cout << count << endl;
    return 0;
}
