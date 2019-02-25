#include <iostream>
#include <vector>
#include <array>
using namespace std;

/*
 * 1. Write a program, which given a text T and a word W,
 * finds the word, which is most often seen around word W.
 * 2. We define “seen around word W” as a word,
 * which is within the N words before and after an occurrence of the word W.
 * 3. For example if we have the text
 * “It is a nice day today, the sun is shining.” and our
 * word W is “day” and N=3, then the words around W are “is”, “a”, “nice”,
 * “today”, “the” and “sun”. These are the words that come immediately
 * before or after “day” within the distance of 3.
 * 4.The goal is for all occurrences of W in T to consider the words that are
 * around these occurrences and to return the one that is most often seen.
 * If there are more than one such words return the one that comes first lexicographically.
 * 5. Don’t count the occurrences of the word W around other occurrences of it.
 * Also, don’t count the same word more than once even if it’s around
 * more than one occurrence of W.
 * 6. If the text has no occurrences of the word W, return the string “N/A”
 * 7. The text T will contain words consisting of only
 * lower-case and upper-case latin letters and numbers.
 * 	SAMPLE INPUT
	It is a nice day today, the sun is shining.
	However, the weather is expected to get worse the following few days.
	Nice day by day weather forecasts can be found literally everywhere on the “Internet”.
	So, it is quite easy to know what to expect tomorrow.
		day
		3
	SAMPLE OUTPUT
	nice
 * */

// Read input from stdin, write output to stdout
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

vector<string> parseString(string s) {
    vector<string> v;
    string cur = "";
    s.push_back('$');
    for (auto x: s) {
        if (isalpha(x)) {
            cur.push_back(tolower(x));
        }
        else if (isdigit(x)) {
            cur.push_back(tolower(x));
        } else if (cur != "") {
            v.push_back(cur);
            cur = "";
        }
    }
    return v;
}

int main() {
    string s;
    getline(cin, s);
    string t;
    cin >> t;
    int k;
    cin >> k;

    vector<string> v = parseString(s);
    map<string, int> mp;
    for (int i = 0, p = -1; i < v.size(); i++) {
        if (v[i] != t) {
            continue;
        }
        for (int j = -k; j <= k && i + j < v.size(); j++) {
            if (i + j < 0 || i + j <= p || v[i + j] == t) {
                continue;
            }
            mp[v[i + j]]++;
        }
        p = max(p, i + k - 1);
    }
    string best = "N/A";
    int besti = 0;
    for (auto p: mp) {
        if (p.second > besti) {
            best = p.first;
            besti = p.second;
        }
    }
    cout << best;
}
