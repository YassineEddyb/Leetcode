#include <iostream>
#include <vector>

using namespace std;

/*
	- Problem: Product of Array Except Self

	- Difficulty: Meduim

	- Subject: 
        Given an integer array nums, return an array answer
        such that answer[i] is equal to the product
        of all the elements of nums except nums[i].

        The product of any prefix or suffix of nums is
        guaranteed to fit in a 32-bit integer.

        You must write an algorithm that runs in O(n)
        time and without using the division operation.
		
	- Example: 
        Input: nums = [1,2,3,4]
        Output: [24,12,8,6]

		
	- Algorithem: Preffix Porduct, Suffix Product.

	- Time complixity: O(n) 
	- Space complixity: O(n)

	- Approach:

*/

vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> suffix(n);
    vector<int> preffix(n);

    suffix[0] = nums[0];
    preffix[0] = nums[n - 1];

    for(int i = 1; i < n; i++)
        suffix[i] = suffix[i - 1] * nums[i];

    for(int i = 0; i < n; i++)
        cout << suffix[i] << endl;
}




int main () {
	
}