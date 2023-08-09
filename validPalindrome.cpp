#include <iostream>
#include <vector>

using namespace std;

/*
	- Problem: Valid Palindrome

	- Difficulty: Easy

	- Subject: 
        A phrase is a palindrome if, after converting all uppercase
        letters into lowercase letters and removing all non-alphanumeric
        characters, it reads the same forward and backward. Alphanumeric
        characters include letters and numbers.

        Given a string s, return true if it is a palindrome,
        or false otherwise.
		
	- Example: 
        Input: s = "A man, a plan, a canal: Panama"
        Output: true
        Explanation: "amanaplanacanalpanama" is a palindrome.
		
	- Algorithem: Two Pointer

	- Time complixity: O(n)
	- Space complixity: O(1)

	- Approach:
        I used Two pointers (l = 0) and (r = s.size()) to iterate
        over s, if any difference found false returned,
        true otherwise

*/

bool isPalindrome(string s) {
    int l = 0, r = s.size() - 1;

    while(l < s.size() && r >= 0) {
        // s[l] and s[r] are both alphanumric and don't match false is returned
        if (isalnum(s[l]) && isalnum(s[r]) 
        && tolower(s[l]) != tolower(s[r]))
            return false;
        // if both are characters l advance's and r decrease's
        if (isalnum(s[l]) && isalnum(s[r])) {
            l++; r--; continue;
        }
        // if only s[l] is not a char l advance's 
        if (!isalnum(s[l]))
            l++;
        // if only s[r] is not a char r decrease's 
        if (!isalnum(s[r]))
            r--;
    }

    return true;
}

int main () {
    string s = "A man, a plan, a canal: Panama";

    bool ret = isPalindrome(s);

	cout << "Expected: " << "1" << endl;
	cout << "Output:   " << ret << endl;
}