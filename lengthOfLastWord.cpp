#include <iostream>
#include <vector>

using namespace std;

/*
	- Problem: Length of Last Word

	- Difficulty: Easy

	- Subject: 
        Given a string s consisting of words and spaces,
        return the length of the last word in the string.

        A word is a maximal 
        substring
        consisting of non-space characters only.
		
	- Example: 
        Input: s = "Hello World"
        Output: 5
        Explanation: The last word is "World" with length 5.
		
	- Algorithem: _____

	- Time complixity: O(n)
	- Space complixity: O(1)

	- Approach: 
        First we skip spaces and then calculate the length
        of the last word.
*/

int lengthOfLastWord(string s) {
    int i = s.size() - 1;

    // skip spaces
    while(i >= 0 && s[i] == ' ')
        i--;

    int n = i;
    
    // loop until you counter a space
    while(i >= 0) {
        if (s[i] == ' ')
            break;
        i--;
    }

    // return n - i which is the size of longest last word
    return n - i;
}

int main () {
    string s = "Hello World";

    int ret = lengthOfLastWord(s);

	cout << "Expected: " << "5" << endl;

	cout << "Output:   " << ret << endl;
}