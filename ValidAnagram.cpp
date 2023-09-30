#include <iostream>
#include <unordered_map>

using namespace std;

/*
	- Problem: Valid Anagram

	- Difficulty: Easy

	- Subject: 
        Given two strings s and t, return true if t is an anagram
        of s, and false otherwise.

        An Anagram is a word or phrase formed by rearranging the
        letters of a different word or phrase, typically using all\
        the original letters exactly once.
		
    - Example 1:
        Input: s = "anagram", t = "nagaram"
        Output: true

    - Example 2:
        Input: s = "rat", t = "car"
        Output: false

		
	- Technique: hash map

	- Time complixity: O(n)
	- Space complixity: O(n)
*/

bool isAnagram(string s, string t) {
    unordered_map<char, int> map;

    // if they sizes differ they are not anagram
    if(s.size() != t.size())
        return false;

    // loop over one of the string
    for(int i = 0; i < s.size(); i++) {
        // increase one
        map[s[i]]++;
        // decrease one
        map[t[i]]--;
    }

    // loop over map keys
    for( auto i : map) {
        // if the value of this key is not 0 they are not anagram
        if (i.second) return false;
    }

    return true;
}

int main () {
	std::string s = "anagram";
    std::string t1 = "nagaram";
    std::string t2 = "foo";

    bool ret1 = isAnagram(s, t1);
    bool ret2 = isAnagram(s, t2);

	cout << "Expected: " << 1 << " " << 0 << endl;
	cout << "Output:   " << ret1 << " " << ret2 << endl;
}
