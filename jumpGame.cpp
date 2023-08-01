#include <iostream>
#include <vector>

using namespace std;

/*
    - Problem: Jump Game

    - Difficulty: Meduim

	- Subject: 
        You are given an integer array nums. You are initially
        positioned at the array's first index, and each element
        in the array represents your maximum jump length at
        that position.

        Return true if you can reach the last index, or false
        otherwise.
		
	- Example: 
		Input: nums = [2,3,1,1,4]
		Output: true
		
	- Algorithem: 

	- Time complixity: 
	- Space complixity:

	- Approach:
*/

bool canJump(vector<int>& nums) {
    int pos = nums[0], steps = nums.size() - 1;

	for (int i = 0; i < nums.size() -1; i++) {
		if (pos <= 0 && nums[i] <= 0) return 0;
		if (pos <= nums[i]) {
			pos = nums[i]; 
		}
		pos--;
	}

	return 1;
}

int main () {
	vector<int> vec = {1,1,1,0};
	// vector<int> vec = {3,2,1,0,4};
	// vector<int> vec = {2,3,1,1,4};

	int ret = canJump(vec);

    cout << "Expected: " << 1 << endl;
	cout << "Output:   " << ret << endl;
}