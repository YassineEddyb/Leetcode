#include <iostream>
#include <vector>
#include <climits>

using namespace std;

/*
	- Problem: H-Index

	- Difficulty: Meduim

	- Subject: 
		Given an array of integers citations where citations[i]
		is the number of citations a researcher received for
		their ith paper, return the researcher's h-index.

		According to the definition of h-index on Wikipedia:
		The h-index is defined as the maximum valueof h such
		that the given researcher has published at least h
		papers that have each been cited at least h times.
		
	- Example: 
		Input: citations = [3,0,6,1,5]
		Output: 3
		Explanation: [3,0,6,1,5] means the researcher has 
		5 papers in total and each of them had received 
		3, 0, 6, 1, 5 citations respectively.
		Since the researcher has 3 papers with at least 3 
		citations each and the remaining two with no more 
		than 3 citations each, their h-index is 3.
				
	- Algorithems: Binary Search, Counting Sort.

	- Time complixity: O(n)
	- Space complixity: O(n)

	- Approach:
		I used counting sort to sort the citations, Which sort's
		small numbers in linear time, And I used binary search 
		to look for h index.
*/

// Counting sort
void countingSort(vector<int>& arr) {
	// we initialize a vector of max numbers in the array with zeros
	vector<int> countTable(5000, 0);

	/* iterate over the array and increment the number 
	in it's corresponding index in countTable */
	for (int i = 0; i < arr.size(); i++)
		countTable[arr[i]]++;


	/* loop over the countTable and put every number 
	that is not 0 in the array countTable[i] times */
	int j = 0;
	for (int i = 0; i < countTable.size(); i++) {
		while (countTable[i]) {
			arr[j] = i;
			j++;
			countTable[i]--;
		}
	}
}

int hIndex(vector<int>& citations) {
	int n = citations.size();
	int start = 0, end = n - 1;

	// sort the array with counting sort
	countingSort(citations);

	// Binary Search
	while(start <= end) {
		// get the mid of a chunck
		int mid = start + (end - start) / 2;

		/* if the value citations[mid] is less than items 
		form mid to n mean that we should look in the
		right of the array */
		if (citations[mid] < n - mid)
			start = mid + 1;
		// eles we look in the left of the array
		else
			end = mid - 1;
	}

	// return n - start which is the h index of citations
	return n - start;
}

int main () {
	vector<int> vec = {3,0,6,1,5};

	int ret = hIndex(vec);

	cout << "Expected: 3" << endl;
	cout << "Output:   " << ret << endl;
}