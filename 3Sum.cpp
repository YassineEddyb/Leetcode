#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

/*
	- Problem: 3Sum

	- Difficulty: Meduim

	- Subject: 
        Given an integer array nums, return all the triplets [nums[i],
        nums[j], nums[k]] such that i != j, i != k, and j != k, and
        nums[i] + nums[j] + nums[k] == 0.

        Notice that the solution set must not contain duplicate triplets.
		
	- Example: 
        Input: nums = [-1,0,1,2,-1,-4]
        Output: [[-1,-1,2],[-1,0,1]]
        Explanation: 
        nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
        nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
        nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
        The distinct triplets are [-1,0,1] and [-1,-1,2].
        Notice that the order of the output and the order of the
        triplets does not matter.
		
	- Algorithem: Tow Pointer, Sort

	- Time complixity: O(n^2)
	- Space complixity: O(n)

	- Approach:
        First I sorted the nums, Then I iterated over nums with (i),
        And I used two pointer (r) and (l) to check for the two
        remaining numbers in leaner time, if the sum of nums[r, l, i]
        equal to 0 I push the solution to results vector.
*/

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> results;

    // sort the nums to use Two Pointers tecknique
    sort(nums.begin(), nums.end());
    

    // iterate over nums with (i)
    for (int i = 0; i < nums.size(); i++) {

        /* check nums[i - 1] if it is equal to nums[i] continue
            to avoid duplicate sulutions */
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        // left and right pointers
        int l = i + 1;
        int r = nums.size() - 1;

        // while left < right
        while(l < r) {
            /* if the sum of nums[l, r, i] are greater than 0
                decrease (r) */
            if (nums[l] + nums[r] + nums[i] > 0)
                r--;
            /* if the sum of nums[l, r, i] are smaller than 0
                increase (l) */
            else if (nums[l] + nums[r] + nums[i] < 0)
                l++;

            // else a solution found
            else {
                // push solution to resultes
                results.push_back({nums[i], nums[l], nums[r]});
                l++;
                /* check if nums[l - 1] is equal to nums[l] advacnce
                   (l) to avoid duplicate solutions */
                while(nums[l] == nums[l - 1] && l < r) l++;
            }
        }
    }

    return results;
}

int main () {
    vector<int> nums = {-1,0,1,2,-1,-4};

    vector<vector<int>> res = threeSum(nums);

	cout << "Expected: " << "[-1,-1,2] [-1,0,1]" << endl;

	cout << "Output:   ";
	for(int i = 0; i < res.size(); i++) {
        cout << "[";
	    for(int j = 0; j < res[i].size(); j++) {
		    cout << res[i][j] << ",";
        }
        cout << "] ";
	}
	cout << endl;
}