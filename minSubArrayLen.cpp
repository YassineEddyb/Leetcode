#include <iostream>
#include <vector>
#include <climits>

using namespace std;

/*
	- Problem: Minimum Size Subarray Sum

	- Difficulty: Meduim

	- Subject: 
        Given an array of positive integers nums and a positive
        integer target, return the minimal length of a subarray
        whose sum is greater than or equal to target. If there
        is no such subarray, return 0 instead.
		
	- Example: 
        Input: target = 7, nums = [2,3,1,2,4,3]
        Output: 2
        Explanation: The subarray [4,3] has the minimal
        length under the problem constraint.
		
	- Algorithem: Sliding Window

	- Time complixity: O(n)
	- Space complixity: O(1)

	- Approach:
        I used Sliding window to loop over the array and 
        look for the smallest window that is bigger or
        equal to target. by using two pointers (r) which
        the end of the window and (l) which is the start
        of it, every loop I expand the window to the right
        and shrink from the left while mantaining
        sum >= target condition, and I update minSubSum to
        keep truck of the smallest subarray sum recorded.
*/

int minSubArrayLen(int target, vector<int>& nums) {
    int l = 0;
    int sum = 0, minSubSum = INT_MAX;

    // loop over nums with (r)
    for (int r = 0; r < nums.size(); r++) {
        // add nums[r] to sum
        sum += nums[r];

        // while sum of window >= target
        while(sum >= target) {
            // recalculate minSubSum
            minSubSum = min(r - l + 1, minSubSum);

            // substract nums[l] from sum
            sum -= nums[l];

            // shrink window form the left
            l++;
        }
    }

    /* if minSubSum still equal to INT_MAX then a solution
       not found return 0 */ 
    if (minSubSum == INT_MAX)
        return 0;

    return minSubSum;
}

int main () {
	vector<int> vec = {2,3,1,2,4,3};
    int target = 7;

	int res = minSubArrayLen(target, vec);

    cout << "Expected: " << "2" << endl;

	cout << "Output:   " << res << endl;
}