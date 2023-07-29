using namespace std;
#include <vector>
#include <iostream>

/*
    - Problem: Remove Duplicates from Sorted Array II

    - Difficulty: Medium

	- Subject: 
        Given an integer array nums sorted in non-decreasing order,
        remove some duplicates in-place such that each unique element
        appears at most twice. The relative order of the elements
        should be kept the same.

        Since it is impossible to change the length of the array in
        some languages, you must instead have the result be placed in
        the first part of the array nums. More formally, if there are
        k elements after removing the duplicates, then the first k
        elements of nums should hold the final result. It does not
        matter what you leave beyond the first k elements.

        Return k after placing the final result in the first k slots of nums.

        Do not allocate extra space for another array.
        You must do this by modifying the input array in-place
        with O(1) extra memory.
		
	- Example: 
        Input: nums = [0,0,1,1,1,1,2,3,3]
        Output: 7, nums = [0,0,1,1,2,3,3,_,_]
		
	- Algorithem: Tow pointer tecknique

	- Time complixity: o(n)

	- Approach: 
        I used tow pointers (i) and (j), (i) iterates over the array,
        and (j) keeps truck of the first element of equal numbers,
        I used (c) to keep counting the numbsers one (c) is not less
        than 2, I replace the following number with a placeholder (pl)
        until nums[i] != nums[j] than I move (j) to his new position
        which is (i) and I initailize (c) with 1, once that done I used
        Romove Element Algorithem to move all the pl to the end of nums.

    - Approach 2:
        source: https://www.youtube.com/watch?v=ycAq8iqh0TI    

*/

int removeDuplicates(vector<int>& nums) {
    int j = 0, i = 1, c = 1;
    int pl = nums[0] - 1;

    if (nums.size() < 3)
        return nums.size();

    while(i < nums.size()) {
        if (nums[i] == nums[j]) {
            if (c < 2) {
                c++;
            } else {
                nums[i] = pl;
            }
        } else {
            j = i;
            c = 1;
        }
        i++;
    }


    // Romove Element Algorithem
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

int removeDuplicates2(vector<int>& nums) {
    int j = 0, c;

    for (int i = 0; i < nums.size(); i++) {
        c = 1;
        while(i + 1 < nums.size() && nums[i] == nums[i + 1]) {
            c++;
            i++;
        }

        for (int k = 0; k < min(c, 2); k++)
            nums[j++] = nums[i];
    }

    return j;
}

int main () {
    vector<int> vec = {0,0,1,1,1,1,1,2,3,3};

    int ret = removeDuplicates2(vec);

	cout << "Expected: " << "0 0 1 1 2 3 3" << endl;

	cout << "Output:   ";
	for(int i = 0; i < ret ; i++) {
		cout << vec[i] << " ";
	}
	cout << endl;
}