#include <iostream>
#include <vector>

using namespace std;

/*
	- Problem: Container With Most Water

	- Difficulty: Meduim

	- Subject: 
		
	- Example: 
        Input: height = [1,8,6,2,5,4,8,3,7]
        Output: 49
        Explanation: The above vertical lines are
        represented by array [1,8,6,2,5,4,8,3,7].
        In this case, the max area of water (blue
        section) the container can contain is 49.
		
	- Algorithem: 

	- Time complixity: 
	- Space complixity:

	- Approach:
*/

int maxArea(vector<int>& height) {
    int maxWater = 0;
    int l = 0;
    int r = height.size() - 1;

    while(l < r) {
        int water = min(height[l], height[r]) * (r - l);
        maxWater = maxWater > water ? maxWater : water;
        if (height[l] <= height[r])
            l++;
        else
            r--;
    }

    return maxWater;
}

int main () {
	vector<int> height = {1,8,6,2,5,4,8,3,7};

	int ret  = maxArea(height);

    cout << "Expected: 49" << endl;
	cout << "Output:   " << ret << endl;
}