#include <iostream>
#include <vector>

using namespace std;

/*
	- Problem: Is Subsequence

	- Difficulty: Easy

	- Subject: 
        Given two strings s and t, return true if s is a
        subsequence of t, or false otherwise.

        A subsequence of a string is a new string that is
        formed from the original string by deleting some
        (can be none) of the characters without disturbing
        the relative positions of the remaining characters.
        (i.e., "ace" is a subsequence of "abcde" while
        "aec"is not).
		
	- Example: 
        Input: s = "abc", t = "ahbgdc"
        Output: true
		
	- Algorithem: Two Pointer

	- Time complixity: O(n)
	- Space complixity: O(1)

	- Approach:
        I used two pointers (i) which iterate's over t
        and (j) over s, if (j) reache's s.size() a
        subsequence found true is returned otherwise
        return false.
*/

bool isSubsequence(string s, string t) {
    int j = 0;

    // if s and t are empty return true
    if (!s.size() && !t.size())
        return true;

    // iterate over t with (i)
    for(int i = 0; i < t.size(); i++) {
        // t[i] == s[j] advance (j);
        if (t[i] == s[j])
            j++;
        // if (j) reach s.size() subsequence if found
        if (j == s.size())
            return true;
    }

    // if not found return false
    return false;
}

int main () {
	string s = "";
	string t = "";

    bool ret = isSubsequence(s, t);

	cout << "Expected: " << "1" << endl;
	cout << "Output:   " << ret << endl;
}