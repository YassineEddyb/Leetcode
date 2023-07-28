using namespace std;
#include <vector>
#include <iostream>

/*
    - Problem: Remove Duplicates from Sorted Array

    - Difficulty: Easy

	- Subject: 
        Given an integer array nums sorted in non-decreasing order,
        remove the duplicates in-place such that each unique element
        appears only once. The relative order of the elements should
        be kept the same. Then return the number of unique
        elements in nums.

        Consider the number of unique elements of nums to be k,
        to get accepted, you need to do the following things:

        Change the array nums such that the first k elements of
        nums contain the unique elements in the order they were
        present in nums initially. The remaining elements of
        nums are not important as well as the size of nums.

        Return k.
		
	- Example: 
        Input: nums = [0,0,1,1,1,2,2,3,3,4]
        Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
		
	- Algorithem: Two pointer tecknique

	- Time complixity: O(n)

	- Approach:
        I iterate over the array with the first pointer (i),
        And I keep truck of the first non duplicate element with
        the second pointer (j), Whenever nums[j] == nums[i] I replace
        nums[i] with a placeholder (pl = nums[0] - 1, since nums is sotrted),
        And I increment j until it does not equal to placeholder,
        Then I used Remove Element algorithm to move all the placeholders
        to the end of the array

    - Approach 2 (from geeksforgeeks):
        Iterate with the first pointer (i) over nums, Once
        nums[i] != nums[i + 1], update nums[second pointer (j)]
        with nums[i] and increment j;

*/

int removeDuplicates(vector<int>& nums) {
    int pl = nums[0] - 1;
    int j = 0;

    for (int i = 1; i < nums.size(); i++) {
        while (nums[j] == pl)
            j++;
        if (nums[i] > nums[j]) {
            j++;
            continue;
        }
        nums[i] = pl;
    }

    // Remove Element Algorithem
    j = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != pl) {
            if (j == i) {
                j++;
                continue;
            }
            nums[j] = nums[i];
            nums[i] = pl;
            j++;
        }
    }

    return j;
}

int removeDuplicates2(vector<int>& nums)
{
    if (nums.size() == 0 || nums.size() == 1)
        return nums.size();

    int j = 0;
    
    for (int i = 0; i < nums.size() - 1; i++) {
        if (nums[i] != nums[i + 1]) {
            nums[j] = nums[i];
            j++;
        }
    }

    nums[j++] = nums[nums.size() -1];

    return j;
}

int main () {
    vector<int> vec = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

    int ret = removeDuplicates2(vec);

	cout << "Expected: " << " 0 1 2 3 4 " << endl;

	cout << "Output:   ";
	for(int i = 0; i < ret ; i++) {
		cout << vec[i] << " ";
	}
	cout << endl;
}