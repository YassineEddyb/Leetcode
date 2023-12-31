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
		
	- Algorithem: prefix Porduct, Suffix Product.

	- Approach 1:
		- Time complixity: O(n) 
		- Space complixity: O(n)

		Lets take (i) as an element in array, We want to 
		calculate the product (P) of array except (i) let's
		call it (Px), If we think about it we'll find that
		Px(i) = P(0, i - 1) * P(i + 1, nums.size() - 1)
		I used two arrays to calculate the prefix product 
		and suffix product, and the used them to get the
		product of each element.
	
	- Approach 2:
		- Time complixity: O(n) 
		- Space complixity: O(1)

		Instead of using two arrays to store prefix product and
		suffix product we can use the output array to store
		the prifix product, And we use suffixProduct variable
		to store the suffix, As we iterate over nums from the 
		end (i = n - 1) we multiply with the prifix Product
		which is stored in output[i] with suffixProduct and
		we store it in output[i], Then we recalculate the
		suffixProduct by multiplying it with nums[i].
		

*/

vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> prefix(n);
    vector<int> suffix(n);
    vector<int> output(n);

	// initailize prefix with first num and suffix with last num
    prefix[0] = nums[0];
    suffix[n - 1] = nums[n - 1];

	// calculate the accumilative prefix product
    for(int i = 1; i < n; i++)
        prefix[i] = prefix[i - 1] * nums[i];

	// calculate the accumilative suffix product
    for(int i = n - 2; i >= 0; i--)
        suffix[i] = suffix[i + 1] * nums[i];

	// iterate over array nums 
	for (int i = 0; i < n; i++) {
		// get prefix[i - 1] if i > 0
		int pre = i == 0 ? 1 : prefix[i - 1];
		// get suffix[i + 1] if i < n - 1
		int suff = i == n - 1 ? 1 : suffix[i + 1];
		// get product of prefix and suffix
		output[i] = pre * suff;
	}

    return output;
}

vector<int> productExceptSelf2(vector<int>& nums) {
    int n = nums.size();
    vector<int> output(n);

	// initailize prefix[0] with 1
    output[0] = 1;

	// calculate the accumilative prefix product
    for(int i = 1; i < n; i++)
        output[i] = output[i - 1] * nums[i - 1];

	// suffix product variable to store the suffix
	int suffixProduct = 1;
	// start from the end iterate over nums
	for (int i = n - 1; i >= 0; i--) {
		// multipy the prefix product with suffix
		output[i] *= suffixProduct;
		// recalculate the suffix
		suffixProduct *= nums[i];
	}

    return output;
}

int main () {
	vector<int> vec = {1,2,3,4};

	vector<int> pVec = productExceptSelf2(vec);

    cout << "Expected: " << "24 12 8 6" << endl;

	cout << "Output:   ";
	for(int i = 0; i < pVec.size(); i++) {
		cout << pVec[i] << " ";
	}
	cout << endl;
}