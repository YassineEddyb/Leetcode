#include <iostream>
#include <vector>

using namespace std;

/*
    - Problem: Jump Game 2

    - Difficulty: Meduim

	- Subject: 
        You are given a 0-indexed array of integers nums
        of length n. You are initially positioned at nums[0].

        Each element nums[i] represents the maximum length of
        a forward jump from index i. In other words, if you
        are at nums[i], you can jump to any nums[i + j] where:

        0 <= j <= nums[i] and
        i + j < n

        Return the minimum number of jumps to reach nums[n - 1].
        The test cases are generated such that you can reach
        nums[n - 1].
		
	- Example: 
		Input: nums = [2,3,1,1,4]
        Output: 2
		
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
*/

int jump(vector<int>& nums) {
    int i = 0, pos = nums[0], k = 1, max = 0, maxPos = 0;

    if (nums.size() == 1)
        return 0;

	while (i < nums.size()) {
		while(pos > 0) {
            if (nums[pos] + pos > max) {
                max = nums[pos] + pos;
                maxPos = pos;
            }
		    pos--;
        }
        i = maxPos;
        pos = nums[maxPos];
        k++;
        cout << pos << maxPos << i << endl;
        // exit(1);
        if (pos + i > nums.size() - 1) return k;
	}

	return k;
}

int main () {
	// vector<int> vec = {7,0,9,6,9,6,1,7,9,0,1,2,9,0,3};
	// vector<int> vec = {2,3,0,1,4};
	vector<int> vec = {1,1,1,1};
	// vector<int> vec = {1, 0};
	// vector<int> vec = {0};

	int ret = jump(vec);
	// int ret2 = jump(vec2);

    cout << "Expected: 2" << endl;
	cout << "Output:   " << ret << endl;
}