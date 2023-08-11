#include <iostream>
#include <vector>
#include <climits>

using namespace std;

/*
	- Problem: Minimum Size Subarray Sum

	- Difficulty:

	- Subject: 
		
	- Example: 
        Input: target = 7, nums = [2,3,1,2,4,3]
        Output: 2
        Explanation: The subarray [4,3] has the minimal
        length under the problem constraint.
		
	- Algorithem: 

	- Time complixity: 
	- Space complixity:

	- Approach:
*/

int minSubArrayLen(int target, vector<int>& nums) {
    int l = 0;
    int sum = 0, minSubSum = INT_MAX;

    for (int r = 0; r < nums.size(); r++) {
        sum += nums[r];

        while(sum >= target) {
            minSubSum = min(r - l + 1, minSubSum);
            sum -= nums[l];
            l++;
        }
    }

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