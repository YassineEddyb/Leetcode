using namespace std;
#include <vector>
#include <iostream>

/*
	- Problem: Merge Sorted Array.

	- Subject: 
		You are given two integer arrays nums1 and nums2,
		sorted in non-decreasing order, and two integers m and n,
		representing the number of elements in nums1 and nums2 respectively.

		Merge nums1 and nums2 into a single array sorted in non-decreasing order.

		The final sorted array should not be returned by the function,
		but instead be stored inside the array nums1. To accommodate this,
		nums1 has a length of m + n,where the first m elements denote the
		elements that should be merged, and the last n elements are set
		to 0 and should be ignored. nums2 has a length of n.
	
	- Example: 
		Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
		Output: [1,2,2,3,5,6]

	- Algorithem: Two pointer techniquer

	- Time complixity: O(n)
	- Space complixity: O(1)

	- Solution:
		Since the given arrays are sorted, 
		I kept truck of the last tow indexes of each array and I took
		the biggest and put in x wich iterates over the array reversely.
*/

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	int i = m - 1, j = n - 1, x = n + m - 1;

	while(x >= 0) {
		if (i >= 0 && j >= 0 && nums1[i] > nums2[j]) {
			nums1[x] = nums1[i];
			nums1[i] = 0;
			i--;
		} else if (j >= 0) {
			nums1[x] = nums2[j];
			j--;
		}
		x--;
	}
}

int main () {
	vector<int> v1 = {1, 2, 3, 0, 0, 0};
	vector<int> v2 = {2, 5, 6};

	merge(v1, 3, v2, 3);

	cout << "Expected" << " 1 2 2 3 5 6 " << endl;

	cout << "Output ";
	for(int i = 0; i < v1.size(); i++) {
		cout << v1[i] << " ";
	}
	cout << endl;
}