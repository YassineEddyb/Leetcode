#include <iostream>
#include <vector>

using namespace std;

/*
	- Problem: Trapping Rain Water

	- Difficulty: Hard

	- Subject: 
		
	- Example: 
		
	- Algorithem: 

	- Time complixity: 
	- Space complixity:

	- Approach:
*/

int trap(vector<int>& height) {
    if (!height.size())
        return 0;

    int l = 0, r = height.size() - 1;
    int maxL = height[l], maxR = height[r];
    int rainSum = 0;

    while(l < r) {
        if (maxL <= maxR) {
            l++;
            rainSum += max(maxL - height[l], 0);
            maxL = max(height[l], maxL);
        } else {
            r--;
            rainSum += max(maxR - height[r], 0);
            maxR = max(height[r], maxR);
        }
    }

    return rainSum;
}

int main () {
    vector<int> vec = {1,0,2,1,0,1,3,2,1,2,1};

    int ret = trap(vec);

	cout << "Expected: 6" << endl;

	cout << "Output:   "<< ret << endl;
}