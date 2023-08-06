#include <iostream>
#include <vector>

using namespace std;

/*
	- Problem: Candy

	- Difficulty: Hard

	- Subject: 
        There are n children standing in a line. Each child
        is assigned a rating value given in the integer
        array ratings.

        You are giving candies to these children subjected
        to the following requirements:

        Each child must have at least one candy.
        Children with a higher rating get more candies than
        their neighbors.
        Return the minimum number of candies you need to have
        to distribute the candies to the children.
		
	- Example: 
		Input: ratings = [1,0,2]
        Output: 5
        Explanation: You can allocate to the first, second
        and third child with 2, 1, 2 candies respectively.

	- Algorithem: Gready Algorithem

	- Time complixity: O(n)
	- Space complixity: O(n)

	- Approach:
        I used an array candies to keep truck of the number of
        candies of each child, first we iterate through ratings
        from lefe to right and calculate candies, and then from
        right to left recalculate candies, then i return the
        sum of candies array.


*/

int candy(vector<int>& ratings) {
    int n = ratings.size();
    /* Intialize new vector with 1 since every student has to 
       have at lease one candy */
    vector<int> candies(n, 1);

    /* iterate over ratings every time a ratings[i] found bigger 
       ratings at i + 1 increment rating[i] with 1 */
    for (int i = 1; i < n; i++) {
        if (ratings[i] > ratings[i - 1])
            candies[i]++;
    }

    /* iterate over the ratings reversevely if rating[i] is 
    greater than ratings[i + 1] and candies[i] are less or 
    equal to candies[i + 1] the candies[i] should be greater
    than candies[i + 1] with 1 */
    for (int i = n - 2; i >= 0; i--) {
        if (ratings[i] > ratings[i + 1] && candies[i] <= candies[i + 1])
            candies[i] = candies[i + 1] + 1;
    }

    /* calculate the sum */
    int minSum = 0;
    for(int i = 0; i < candies.size(); i++)
        minSum += candies[i];

    return minSum;
}

int main () {
	vector<int> vec = {1,3,2,2,1};

	int ret = candy(vec);

    cout << "Expected: " << "7" << endl;
	cout << "Output:   " << ret << endl;
}