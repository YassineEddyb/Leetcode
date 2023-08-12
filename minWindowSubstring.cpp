#include <iostream>
#include <vector>
#include <map>

using namespace std;

/*
	- Problem: Minimum Window Substring

	- Difficulty: Hard

    - Subject: 
        Given two strings s and t of lengths m and n respectively,
        return the minimum window 
        substring
        of s such that every character in t (including duplicates)
        is included in the window. If there is no such substring,
        return the empty string "".

        The testcases will be generated such that the
        answer isunique.
		
	- Example: 
        Input: s = "ADOBECODEBANC", t = "ABC"
        Output: "BANC"
        Explanation: The minimum window substring "BANC"
        includes 'A', 'B', and 'C' from string t.
		
	- Algorithem: Sliding Window

	- Time complixity: 
	- Space complixity:

	- Approach:
*/

// bool checkEqualMaps(map<char, int> m1, map<char, int> m2) {
//     for (auto i : m1) {
//         if (m2[i.first] < i.second)
//             return false;
//     }
//     return true;
// }

string minWindow(string s, string t) {
    map<char, int> chars_map;
    map<char, int> map;
    int have = 0, need = 0;
    int l = 0, r = 0;
    vector<int> c = {0, -1};

    if (t.size() == 0)
        return "";

    for(int i = 0; i < t.size(); i++) {
        if (++chars_map[t[i]] == 1)
            need++;
    }

    while (l < s.size() && r < s.size() + 1) {
        if (chars_map.find(s[r]) != chars_map.end()) {
            map[s[r]]++;
            if (map[s[r]] == chars_map[s[r]])
                have++;
        }

        while (r - l + 1 >= t.size() && have == need) {
            if (c[1] < 0 || c[1] - c[0] + 1 > r - l + 1)
                c = {l, r};

            if (chars_map.find(s[l]) != chars_map.end()) {
                map[s[l]]--;
                if (map[s[l]] < chars_map[s[l]])
                    have--;
            }
            l++;
        }
        r++;
    }

    string res(s, c[0], c[1] - c[0] + 1);
    return res;
}

int main () {
    string s = "aaaaaaaaaaaabbbbbcdd";
    string t = "abcdd";

    string ret = minWindow(s, t);

	cout << "Expected: " << "BANC" << endl;
	cout << "Output:   " << ret << endl;
}