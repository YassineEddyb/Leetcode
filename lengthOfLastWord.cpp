#include <iostream>
#include <vector>

using namespace std;

/*
	- Problem: 

	- Difficulty:

	- Subject: 
		
	- Example: 
		
	- Algorithem: 

	- Time complixity: 
	- Space complixity:

	- Approach:
*/

int lengthOfLastWord(string s) {
    int i = s.size() - 1;

    while(i >= 0 && s[i] == ' ')
        i--;

    int n = i;
    while(i >= 0) {
        if (s[i] == ' ')
            break;
        i--;
    }
    return n - i;
}

int main () {
    string s = "sfsfsf sss";

    int ret = lengthOfLastWord(s);

	cout << "Expected: " << "5" << endl;

	cout << "Output:   " << ret << endl;
}