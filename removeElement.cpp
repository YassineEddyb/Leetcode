using namespace std;
#include <vector>
#include <iostream>

/*
    - Problem: Remove Element

    - Difficulty: Easy

	- Subject:
        Given an integer array nums and an integer val,
        remove all occurrences of val in nums in-place.
        The order of the elements may be changed. Then return
        the number of elements in nums which are not equal to val.

        Consider the number of elements in nums which are not
        equal to val be k, to get accepted, you need to do
        the following things:

        Change the array nums such that the first k elements
        of nums contain the elements which are not equal to val.
        The remaining elements of nums are not important as
        well as the size of nums.

        Return k.
	
	- Example:
        Input: nums = [3,2,2,3], val = 3
        Output: 2, nums = [2,2,_,_]
		
	- Algorithem: Two pointer techniquer

	- Time complixity: o(n)
	- Space complixity: O(1)

	- Solution:
        I iterate over the vector with the first pointer (i),
        And the second pointer (j) keep truck of the val index
        when nums[i] != val, Once i != j I swap nums[i] and mums[j],
        and Then I return (j) as the number of element that does not
        eqaut to val.
*/

int removeElement(vector<int>& nums, int val) {
    int i = 0, j = 0;

    while(i < nums.size() && j < nums.size()) {
        if (nums[i] != val) {
            if (i == j) {
                j++;
                i++;
                continue;
            }
            nums[j] = nums[i];
            nums[i] = val;
            j++;
        }
        i++;
    }

    return j;
}

int main () {
    vector<int> vec = {3,2,2,3};
    int val = 3;

    int ret = removeElement(vec, val);

	cout << "Expected" << " 2 2 " << endl;

	cout << "Output ";
	for(int i = 0; i < ret ; i++) {
		cout << vec[i] << " ";
	}
	cout << endl;
}