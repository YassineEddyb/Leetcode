#include <iostream>
#include <vector>

using namespace std;

/*
	- Problem: Two Sum II - Input Array Is Sorted

	- Difficulty: Meduim

	- Subject: 
		
	- Example: 
        Input: numbers = [2,7,11,15], target = 9
        Output: [1,2]
        Explanation: The sum of 2 and 7 is 9. Therefore,
        index1 = 1, index2 = 2. We return [1, 2].
		
	- Algorithem: 

	- Time complixity: 
	- Space complixity:

	- Approach:
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