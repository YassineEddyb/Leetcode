#include <iostream>
#include <vector>

using namespace std;

/*
	- Problem: Find the Index of the First Occurrence in a String

	- Difficulty: Easy

	- Subject: 
        Given two strings needle and haystack, return the index
        of the first occurrence of needle in haystack, or -1
        if needle is not part of haystack.
		
	- Example: 
        Input: haystack = "sadbutsad", needle = "sad"
        Output: 0
        Explanation: "sad" occurs at index 0 and 6.
        The first occurrence is at index 0, so we return 0.
		
	- Algorithem: Two Pointer

	- Time complixity: O(n * m) m is the length of needle
	- Space complixity: O(1)

	- Approach: 
        I iterate with (i) over haystack and (j) over needle
        and I save (i) in (k) if haystach[i] matches needle[j]
        I increment (j) if not (i = k) and k advance with one
        and j get's reseted with 0, k is return if occrence found
        (j == needle.size()), -1 if not found.

*/

int strStr(string haystack, string needle) {
    int k = 0;
    int j = 0;

    // loop over haystack
    for(int i = 0; i < haystack.size(); i++) {
        // if haystack[i] != needle[j] reset variables else advance (j)
        if (haystack[i] != needle[j]) {
            i = k;
            k++;
            j = 0;
        } else {
            j++;
        }
        // if j reaches needle.size() a match found return (k)
        if (j == needle.size())
            return k;
    }

    // return -1 if no match found
    return -1;
}

int main () {
	string haystack = "sadbutsad";
	string needle = "sad";

    int ret = strStr(haystack, needle);

	cout << "Expected: " << "0" << endl;
	cout << "Output:   " << ret << endl;
}