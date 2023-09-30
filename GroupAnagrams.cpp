#include <iostream>
#include <vector>
#include <unordered_map>
#include<bits/stdc++.h>

using namespace std;

/*
	- Problem: Group Anagrams

	- Difficulty: Medium

	- Subject: 
        Given an array of strings strs, group the anagrams together.
        You can return the answer in any order.

        An Anagram is a word or phrase formed by rearranging the
        letters of a different word or phrase, typically using all
        the original letters exactly once.
		
	- Example:
        Input: strs = ["eat","tea","tan","ate","nat","bat"]
        Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

	- Technique: hash map, soring

	- Time complixity: O(n^2), O(n)
	- Space complixity: O(n)
*/

// brute force appraoch
vector<vector<string>> groupAnagrams1(vector<string>& strs) {
    vector<vector<string>> anagrams;
    vector<string> sorted_strs = strs;
    vector< string> unique_strs;

    for (int i = 0; i < strs.size(); i++) {
        sort(sorted_strs[i].begin(), sorted_strs[i].end());
    }

    unique_strs.push_back(sorted_strs[0]);
    anagrams.push_back({strs[0]});


    for (int i = 1; i < strs.size(); i++) {
        for (int j = 0; j < unique_strs.size(); j++) {
            if (sorted_strs[i] ==  unique_strs[j]) {
                anagrams[j].push_back(strs[i]);
                break;
            }
            if (j == unique_strs.size() - 1) {
                anagrams.push_back({strs[i]});
                unique_strs.push_back(sorted_strs[i]);
                break;
            }
        }
    }

    return anagrams;
}

// hash map solution
vector<vector<string>> groupAnagrams2(vector<string>& strs) {
    unordered_map<string, vector<string>> map;
    vector<vector<string>> anagrams;

    // loop over the strings
    for (auto s: strs) {
        string sorted_s = s;
        // sort the copy
        sort(sorted_s.begin(), sorted_s.end());
        // push to the map with sorted key
        map[sorted_s].push_back(s);
    }

    // get all vectors inside the map
    for (auto i: map) {
        anagrams.push_back(i.second);
    }

    return anagrams;
}


int main () {
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};

    vector<vector<string>> vec = groupAnagrams2(strs);

    std::cout << vec.size() << std::endl;

	cout << "Expected: " << "bat | tan nat | eat tea ate |" << endl;

	cout << "Output:   ";
	for(int i = 0; i < vec.size(); i++) {
    	for(int j = 0; j < vec[i].size(); j++)
		    cout << vec[i][j] << " ";
		cout << "| ";
	}
	cout << endl;
}