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

	- Time complixity: O(n logn)
	- Space complixity: O(n)

	- Approach: 
        I used Sliding Window tecknique to loop over (s) and 
        two hash maps first (chars_map) to cound the chars in
        (t) and (map) to count the chars in the current window
        and I keep the size of the smallest window that contains
        all chars of in a vector (c).
*/

string minWindow(string s, string t) {
    map<char, int> chars_map;
    map<char, int> map;
    int have = 0, need = 0;
    int l = 0, r = 0;
    vector<int> c = {0, -1};

    // if t is empty return empty string
    if (t.size() == 0)
        return "";

    // get the cound of chars in t and store them in chars_map
    for(int i = 0; i < t.size(); i++) {
        if (++chars_map[t[i]] == 1)
            // update need if the char is not already in chars_map
            need++;
    }

    // loop until l or r are bigger than s.size()
    while (l < s.size() && r < s.size() + 1) {
        // check if s[r] is not in chars_map
        if (chars_map.find(s[r]) != chars_map.end()) {
            // increment the count of s[r] in map
            map[s[r]]++;
            // if the amount of s[r] in map is the same in chars_map
            if (map[s[r]] == chars_map[s[r]])
                // increment (have)
                have++;
        }

        // have is the same as need shrink from the left
        while (r - l + 1 >= t.size() && have == need) {
            // if current window length is smaller update (c)
            if (c[1] < 0 || c[1] - c[0] + 1 > r - l + 1)
                c = {l, r};

            // check if s[l] is not in chars_map
            if (chars_map.find(s[l]) != chars_map.end()) {
                // decrement the count of s[l] in map
                map[s[l]]--;

                // check if s[l] count is no longer equal in map and chars_mpa
                if (map[s[l]] < chars_map[s[l]])
                    // decrease (have)
                    have--;
            }
            l++;
        }
        r++;
    }

    // get the sub string and put it in res
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