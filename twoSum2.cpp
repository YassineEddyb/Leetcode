#include <iostream>
#include <vector>

using namespace std;

/*
	- Problem: Two Sum II - Input Array Is Sorted

	- Difficulty: Meduim

	- Subject: 
        Given a 1-indexed array of integers numbers that is
        already sorted in non-decreasing order, find two
        numbers such that they add up to a specific target
        number. Let these two numbers be numbers[index1]and
        numbers[index2] where 1 <= index1 < index2 < numbers.length.

        Return the indices of the two numbers,
        index1 and index2, added by one as an integer
        array [index1, index2] of length 2.

        The tests are generated such that there is exactly
        one solution. You may not use the same element twice.

        Your solution must use only constant extra space.
		
	- Example: 
        Input: numbers = [2,7,11,15], target = 9
        Output: [1,2]
        Explanation: The sum of 2 and 7 is 9. Therefore,
        index1 = 1, index2 = 2. We return [1, 2].
		
	- Algorithem: Two Pointer

	- Time complixity: O(n)
	- Space complixity: O(1)

	- Approach:
        Since the numbers are sorted, I used Tow pointer (l)
        left and (r) right if  
*/

vector<int> twoSum(vector<int>& numbers, int target) {
    int r = numbers.size() - 1;
    int l = 0;

    while(l < r) {
        if (numbers[l] + numbers[r] < target)
            l++;
        else if (numbers[l] + numbers[r] > target)
            r--;
        else
            break;
    }

    return {l + 1, r + 1};
}

int main () {
	vector<int> vec = {2,7,11,15};
    int target = 9;

	vector<int> res = twoSum(vec, target);

    cout << "Expected: " << "0 1" << endl;

	cout << "Output:   ";
	for(int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}
	cout << endl;
}