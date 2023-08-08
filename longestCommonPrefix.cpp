#include <iostream>
#include <vector>

using namespace std;

/*
	- Problem: Longest Common Prefix

	- Difficulty: Easy

	- Subject: 
        Write a function to find the longest common prefix
        string amongst an array of strings.

        If there is no common prefix, return an empty string "".
		
	- Example:
        Input: strs = ["flower","flow","flight"]
        Output: "fl"
		
	- Algorithem: Brute Force

	- Time complixity: O(n * k) k is length of the longest prefix.
	- Space complixity: O(1)

	- Approach:
        I used k to keep truck of the longest common 
        prefix index, I loop over strs and I loop 
        from j = 0 to k once diff found k become's j,
        At the end 0 to k from strs[0] is returned.
*/

string longestCommonPrefix(vector<string>& strs) {
    // we initialize p with the length of the first string
    int k = strs[0].size();

    // loop over strs
    for(int i = 1; i < strs.size(); i++) {
        // loop from 0 to k
        for(int j = 0; j < k; j++)
            // if diff between first and current string found k become's j;
            if (strs[i][j] != strs[0][j])
                k = j;
    }

    // get common preffix from 0 to k
    string s(strs[0], 0, k);

    return s;
}

int main () {
    vector<string> strs = {"flower", "flow", "flight"};

    string ret = longestCommonPrefix(strs);

	cout << "Expected: " << "fl" << endl;
	cout << "Output:   " << ret << endl;
}