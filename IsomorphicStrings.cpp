#include <iostream>
#include <map>
#include <string>

using namespace std;

/*
	- Problem:  Isomorphic Strings

	- Difficulty: Easy

	- Subject: 
        Given two strings s and t, determine if they are isomorphic.

        Two strings s and t are isomorphic if the characters in s
        can be replaced to get t.

        All occurrences of a character must be replaced with another
        character while preserving the order of characters. No two
        characters may map to the same character, but a character
        may map to itself.
		
	- Example 1:
        Input: s = "egg", t = "add"
        Output: true

    - Example 2:
        Input: s = "foo", t = "bar"
        Output: false
		
	- Algorithem: hash map

	- Time complixity: O(n)
	- Space complixity: O(n)
*/

bool isIsomorphic(string s, string t) {
    map<char, char> s_map;
    map<char, int> t_map;

    // if the sizes differs then they are not isomorphic
    if (s.size() != t.size())
        return false;

    // loop over one of the strings
    for (int i = 0; i < s.size(); i++) {
        // if the characters are not mapped
        if (!s_map[s[i]] && !t_map[t[i]]) {
            // map them
            s_map[s[i]] = t[i];
            t_map[t[i]] = s[i];
        }
        /*  if one of the characters is mapped and the other
            character not equal to the value of the first character 
            in the map the they are not isomorphic  */
        else if (s_map[s[i]] != t[i])
            return false;
    }

    return true;
}

int main () {
    std::string t = "egg";
    std::string s1 = "bar";
    std::string s2 = "foo";

    bool ret1 = isIsomorphic(s1, t);
    bool ret2 = isIsomorphic(s2, t);

	cout << "Expected: " << 0 << " " << 1 << endl;
	cout << "Output:   " << ret1 << " " << ret2 << endl;
}