#include <iostream>
#include <vector>

using namespace std;

/*
    - Problem: Rotate Array

    - Difficulty:

	- Subject: 
		
	- Example: 
        Input: nums = [1,2,3,4,5,6,7], k = 3
        Output: [5,6,7,1,2,3,4]
		
	- Algorithem: 

	- Time complixity: 
	- Space complixity:

	- Approach:
*/

void rotateArray(vector<int>& nums, int k) {
    vector<int> arr(nums.size()) ;
    int j = nums.size() - 1;

    if (nums.size() == 1 || k == 0) return;
    
    k = k % nums.size();

    for(int i = k ; i >= 0; i--) {
        nums[j] = nums[i];
        j--;
    }
    
    for (int i = nums.size() - 1; i > k ; i--) {
        nums[j] = copy_nums[i];
        j--;
    }
}

int main () {
    // vector<int> vec = {1,2,3,4,5,6,7};
    vector<int> vec = {-1,-100};
    int k = 2;

	rotateArray(vec, k);

	cout << "Expected: " << "1 2 3 4 5 6 7" << endl;

	cout << "Output:   ";
	for(int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
	cout << endl;
}