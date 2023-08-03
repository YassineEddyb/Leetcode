#include <iostream>
#include <vector>
#include <climits>

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
		
	- Algorithem: Dynamic Programing, Gready Method

	- Time complixity: dp O(n^2), gready O(n)
	- Space complixity: dp O(n), gready O(1)

	- Approach1 dp:
        I used dynamic programing memoization to traverse
        all the node and take the min steps tha you can make.
		
    - Approach2 gready:
        I used left (l) and right (r) wich represent the start
        and the end of a segment to iterate over it, then 
        I take the max reach that I can make form this segment
        And I move l to r + 1 and r to the max reach index. every
        time those steps complete I increment steps which will be
        returned at the end.
*/


int minJump(vector<int>& nums, vector<int>& store, int n) {
    // Base case this means that we reached the end of nums
    if (n >= nums.size() - 1)
        return 0;
    
    // Check if the node is already calculated
    if (store[n])
        return store[n];
    
    int jumps = INT_MAX;

    // Loop over all the jump that you can make from this node
    for (int i = n + 1; i <= n + nums[n]; i++)
        // take the min between jumps and the result recurtion 
        jumps = min(jumps, 1 + minJump(nums, store, i));

    // store the min jumps for n
    store[n] = jumps;

    return store[n];
}

int jump(vector<int>& nums) {
    // intailize the store with the length of array nums
    vector<int> store(nums.size());
    // call the minJump which will be recursive
    return minJump(nums, store, 0);
}

int jump2(vector<int>& nums) {
    int l = 0, r = 0, steps = 0;

    // Loop over the array nums until (r) reach the last index
    while(r < nums.size() - 1) {
        int maxSteps = 0;
        // Loop from left to the right of this segment
        while(l <= r) {
            // Take the max reach you can make from this segment
            maxSteps = max(maxSteps, l + nums[l]);
            l++;
        }
        // Move r to the max reach index and l will be in r position
        r = maxSteps;
        // Increment steps;
        steps++;
    }

    return steps;
}

int main () {
	vector<int> vec = {2,3,1,1,4};

	int ret = jump(vec);
	int ret2 = jump2(vec);

    cout << "Expected: 2 2" << endl;
	cout << "Output:   " << ret << " " << ret2 << endl;
}