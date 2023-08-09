#include <iostream>
#include <vector>

using namespace std;

/*
	- Problem: Reverse Words in a String

	- Difficulty:

	- Subject: 
		
	- Example: 
		
	- Algorithem: 

	- Time complixity: 
	- Space complixity:

	- Approach:
*/

void reverse(string& s, int start, int end) {
    char tmp;
    while(start < end) {
        tmp = s[start];
        s[start] = s[end];
        s[end] = tmp;
        end--;
        start++;
    }
}

string reverseWords(string s) {
    reverse(s, 0 , s.size() - 1);
    int j = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            reverse(s, j, i - 1);
            j = i + 1;
        }
    }

    return s;
}

int main () {
    string s = "Hello World";

    string ret = reverseWords(s);

	cout << "Expected: " << "5" << endl;

	cout << "Output:   " << ret << endl;
}