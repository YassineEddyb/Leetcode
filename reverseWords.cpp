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
    string res;
    s = "  " + s;
    int j = s.size() - 1;

    for (int i = s.size() - 1; i >= 0; i--) {
        if ((s[i] == ' ' || i == 0) && i < j) {
            int start = i ? i + 1: i;
            string tmp(s, start, j - start + 1);
            res += res.size() ? " " + tmp : "" + tmp;
            j = i - 1;
        } else if (s[i] == ' ') {
            j--;
        }
    }

    return res;
}

int main () {
    string s = "a";

    string ret = reverseWords(s);

	cout << "Expected: " << "World Hello" << endl;

	cout << "Output:   " << ret << endl;
}