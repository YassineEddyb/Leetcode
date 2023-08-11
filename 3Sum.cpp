#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

/*
	- Problem: 3Sum

	- Difficulty: Meduim

	- Subject: 
		
	- Example: 
		
	- Algorithem: 

	- Time complixity: 
	- Space complixity:

	- Approach:
*/

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> results;
    sort(nums.begin(), nums.end());
    
    for (int i = 0; i < nums.size(); i++) {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        int l = i + 1;
        int r = nums.size() - 1;

        while(l < r) {
            if (nums[l] + nums[r] + nums[i] > 0)
                r--;
            else if (nums[l] + nums[r] + nums[i] < 0)
                l++;
            else {
                results.push_back({nums[i], nums[l], nums[r]});
                l++;
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