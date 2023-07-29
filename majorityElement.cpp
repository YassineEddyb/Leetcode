#include <iostream>
#include <vector>
#include <map>

using namespace std;

/*
    - Problem: Majority Element

    - Difficulty: Easy

	- Subject: 
        Given an array nums of size n, return the majority element.

        The majority element is the element that appears more than
        ⌊n / 2⌋ times. You may assume that the majority element
        always exists in the array.
		
	- Example: 
		Input: nums = [2,2,1,1,1,2,2]
        Output: 2

	- Algorithem: Hash Map

	- Time complixity: O(n)
    - Space complixity: O(n)

	- Approach:

*/

int majorityElement(vector<int>& nums) {
    map<int, int> m;
    int maxKey = 0, key;
    for (int i = 0; i < nums.size(); i++) {
        m[nums[i]]++;
        if (m[nums[i]] > maxKey) {
            maxKey = m[nums[i]];
            key = nums[i];
        }
    }

    return key;
}

int main () {
    vector<int> vec = {2,2,1,1,1,2,2};

    int ret = majorityElement(vec);

	cout << "Expected: " << "2" << endl;
	cout << "Output:   " << ret << endl;
}