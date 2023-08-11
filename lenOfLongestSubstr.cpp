#include <iostream>
#include <vector>
#include <map>

using namespace std;

/*
	- Problem: Longest Substring Without Repeating Characters

	- Difficulty: Meduim

	- Subject: 
        Given a string s, find the length of the longest 
        substring without repeating characters.
		
	- Example: 
        Input: s = "abcabcbb"
        Output: 3
        Explanation: The answer is "abc", with the length of 3.
		
	- Algorithem: Sliding Window

	- Time complixity: O(n)
	- Space complixity: O(n)

	- Approach:
*/

int lengthOfLongestSubstring(string s) {
    map<char, int> m;
    int l = 0, maxSubStr = 0;

    // iterate over s
    for (int r = 0; r < s.size(); r++) {

        /* if (s[r]) is found in map (l) moves to of max
           (l) and m[s[r]] so that (l) never goes back */
        if (m.find(s[r]) != m.end()) {
            l = max(l, m[s[r]]);
        }

        // update the max Sub string length
        maxSubStr = max(maxSubStr, r - l + 1);

        /* map s[r] to r + 1 so if next time we encounter 
           it we will move l to r + 1 */
        m[s[r]] = r + 1;
    }

    return maxSubStr;
}

int main () {
    string s = "abcabcbb";

    int ret = lengthOfLongestSubstring(s);

	cout << "Expected: " << "3" << endl;
	cout << "Output:   " << ret << endl;
}