#include <iostream>
#include <vector>

using namespace std;

/*
	- Problem: Trapping Rain Water

	- Difficulty: Hard

	- Subject: 
        Given n non-negative integers representing an elevation
        map where the width of each bar is 1, compute how much
        water it can trap after raining.
		
	- Example: 
        Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
        Output: 6
        Explanation: The above elevation map (black section) is
        represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this
        case, 6 units of rain water (blue section) are being trapped.
		
	- Algorithem: Two Pointer

	- Time complixity: O(n)
	- Space complixity: O(1)

	- Approach:
        https://www.youtube.com/watch?v=ZI2z5pq0TqA

*/

int trap(vector<int>& height) {
    if (!height.size())
        return 0;

    // inialize two pointer left (l) and right (r)
    int l = 0, r = height.size() - 1;
    // intialize max left (maxR) and max right (maxR)
    int maxL = height[l], maxR = height[r];
    // rainSum to hold the sum of water that can be trapped
    int rainSum = 0;

    // loop until l and r meet
    while(l < r) {
        if (maxL <= maxR) {
            l++;
            // add rain that is trapped in height[l]
            rainSum += max(maxL - height[l], 0);
            // update maxL by take the max of height[l] and maxL
            maxL = max(height[l], maxL);
        } else {
            r--;
            // add rain that is trapped in height[l]
            rainSum += max(maxR - height[r], 0);
            // update maxR by take the max of height[r] and maxR
            maxR = max(height[r], maxR);
        }
    }

    return rainSum;
}

int main () {
    vector<int> vec = { 1,0,2,1,0,1,3,2,1,2,1 };

    int ret = trap(vec);

	cout << "Expected: 6" << endl;
	cout << "Output:   " << ret << endl;
}