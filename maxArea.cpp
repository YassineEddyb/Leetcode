#include <iostream>
#include <vector>

using namespace std;

/*
	- Problem: Container With Most Water

	- Difficulty: Meduim

	- Subject: 
        You are given an integer array height of length n.
        There are n vertical lines drawn such that the two
        endpoints of the ith line are (i, 0) and (i, height[i]).

        Find two lines that together with the x-axis form a
        container, such that the container contains themost water.

        Return the maximum amount of water a container can store.

        Notice that you may not slant the container.
		
	- Example: 
        Input: height = [1,8,6,2,5,4,8,3,7]
        Output: 49
        Explanation: The above vertical lines are
        represented by array [1,8,6,2,5,4,8,3,7].
        In this case, the max area of water (blue
        section) the container can contain is 49.
		
	- Algorithem: Tow Pointer

	- Time complixity: O(n)
	- Space complixity: O(1)

	- Approach:
        The lines which are the heights and the farthest form 
        each other are the most likely to hold more water, So
        i used two pointers (l) which start's from left and (r)
        which start's form right, Then I calculate the max water 
        than can fit between them until (l) is no longer smaller
        than (r).
*/

int maxArea(vector<int>& height) {
    // maxWater for storing the max water so far
    int maxWater = 0;
 
    int l = 0;
    int r = height.size() - 1;

    // loop until left is no longer smaller
    while(l < r) {
        // calculate the water between current two lines
        int water = min(height[l], height[r]) * (r - l);

        // update max water if current water is bigger then maxWater
        maxWater = maxWater > water ? maxWater : water;

        // if height[l] is smaller of equal to height[r] advance (l)
        if (height[l] <= height[r])
            l++;
        // else decrease (r)
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