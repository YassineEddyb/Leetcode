#include <iostream>
#include <vector>

using namespace std;

/*
	- Problem: Longest Common Prefix

	- Difficulty:

	- Subject: 
		
	- Example: 
		
	- Algorithem: 

	- Time complixity: 
	- Space complixity:

	- Approach:
*/

string longestCommonPrefix(vector<string>& strs) {
    int p = strs[0].size();

    for(int i = 1; i < strs.size(); i++) {
        for(int j = 0; j < p; j++)
            if (strs[i][j] != strs[0][j])
                p = j;
    }

    string s(strs[0], 0, p);
    return s;
}

int main () {
    vector<string> strs = {"s", "s", "s"};

    string ret = longestCommonPrefix(strs);

	cout << "Expected: " << "fl" << endl;
	cout << "Output:   " << ret << endl;
}