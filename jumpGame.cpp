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
		Input: nums = [3,2,1,0,4]
		Output: false
		
	- Algorithem: gready method

	- Time complixity: O(n)
	- Space complixity: O(1)

	- Approach:
		I used pos to keep truck of the position with most steps
		in it (gready), On every iteration I check if pos < nums[i]
		if so then pos = nums[i] and I decrease pos with 1,
		But first I check if (pos == 0 and nums[i] == 0) than means
		the we can not move to the next index I return 0, If everythig
		is ok means that we reached the end of array and I return 1.
	
	- Approach 2:
		https://www.youtube.com/watch?v=muDPTDrpS28&t=299s

*/

bool canJump(vector<int>& nums) {
    int pos = nums[0];

	for (int i = 0; i < nums.size() - 1; i++) {
		if (pos == 0 && nums[i] == 0 ) return 0;
		if (pos < nums[i]) {
			pos = nums[i]; 
		}
		pos--;
	}

	return 1;
}

bool canJump2(vector<int>& nums) {
    int reachable = 0;

	for (int i = 0; i < nums.size(); i++) {
		if ( i > reachable) return false;

		if (nums[i] + i > reachable)
			reachable = nums[i] + i;
	}

	return true;
}

int main () {
	vector<int> vec = {3,2,1,0,4};
	vector<int> vec2 = {2,3,1,1,4};

	int ret = canJump(vec);
	int ret2 = canJump(vec2);

    cout << "Expected: 0 1" << endl;
	cout << "Output:   " << ret << " " << ret2 << endl;
}