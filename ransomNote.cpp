#include <iostream>
#include <vector>
#include <map>

using namespace std;

/*
	- Problem: Ransom Note 

	- Difficulty: Easy

	- Subject: 
		Given two strings ransomNote and magazine, return true i
        ransomNote can be constructed by using the letters from
        magazine and false otherwise.

        Each letter in magazine can only be used once in ransomNote.

    - Example 1:
        Input: ransomNote = "aa", magazine = "ab"
        Output: false

    - Example 2:
        Input: ransomNote = "aa", magazine = "aab"
        Output: true

		
	- Algorithem: hash map

	- Time complixity: o(n)
	- Space complixity: o(n)
*/

bool canConstruct(string ransomNote, string magazine) {
    map<char, int> magazine_map;

    // loop store the magazine letters in the a map
    for (int i = 0; i < magazine.size(); i++) {
        magazine_map[ransomNote[i]]--;
    }

    // loop over ransomeNote
    for (int i = 0; i < ransomNote.size(); i++) {
        // check if current character is inside magazine_map
        if (magazine_map[ransomNote[i]]) {
            // if exist decrease it and continue
            magazine_map[ransomNote[i]]--;
            continue;
        }
        // esle not found return false
        else
            return false;
    }

    return true;
}

int main () {
    string ransomNote = "aa";
    string magazine = "aab";

    int ret = canConstruct(ransomNote, magazine);

	cout << "Expected: " << "1" << endl;

	cout << "Output:   " << ret << endl;
}