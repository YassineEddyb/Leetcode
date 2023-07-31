#include <iostream>
#include <vector>

using namespace std;

/*
    - Problem: Rotate Array

    - Difficulty: Meduim

	- Subject: 
        Given an integer array nums, rotate the array to the right 
        by k steps, where k is non-negative.
		
	- Example: 
        Input: nums = [1,2,3,4,5,6,7], k = 3
        Output: [5,6,7,1,2,3,4]
		
	- Algorithem: Reverse Array

	- Time complixity: O(n)
	- Space complixity: O(1)

	- Approach:
        first since rotate by k == nums.size() does not change the
        array we use k = k % nums.size() to avoid getting out of range,
        After that we reverse the hole array, Then we reverse the 
        array from 0 to k - 1 and from k to nums.size() -1;
*/

void reverse(vector<int>& nums, int start, int end) {
    int temp;
    while(end > start) {
        temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++;
        end--; 
    }
}


void rotateArray(vector<int>& nums, int k) {
    k = k % nums.size();
    
    reverse(nums, 0, nums.size() - 1);
    reverse(nums, 0, k  - 1);
    reverse(nums, k, nums.size() - 1);
}

int main () {
    vector<int> vec = {1,2,3,4,5,6,7};
    int k = 3;

	rotateArray(vec, k);

    cout << "Expected: " << "5 6 7 1 2 3 4" << endl;

	cout << "Output:   ";
	for(int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
	cout << endl;
}