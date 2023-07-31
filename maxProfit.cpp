#include <iostream>
#include <vector>

using namespace std;

/*
    - Problem: Best Time to Buy and Sell Stock

    - Difficulty: Easy

	- Subject: 
        You are given an array prices where prices[i] is the price
        of a given stock on the ith day.

        You want to maximize your profit by choosing a single day
        to buy one stock and choosing a different day in the
        future to sell that stock.

        Return the maximum profit you can achieve from this
        transaction. If you cannot achieve any profit, return 0.
		
	- Example: 
        Input: prices = [7,1,5,3,6,4]
        Output: 5
		
	- Algorithem: Greedy Algorithem

	- Time complixity: O(n) 
	- Space complixity: O(n)

	- Approach: 
        we use a variable buy with keep tuck of the lowest element
        in the array, And a variable max which keep tuck of the
        maximum profit, In every iteration we check if prices[i]
        is lower than buy if so then buy = prices[i] else if
        we check if prices[i] - buy > max then max = prices[i] - buy.
*/

int maxProfit(vector<int>& prices) {
    int buy = prices[0], max = 0;

    for(int i = 1; i < prices.size(); i++) {
        if (prices[i] < buy)
            buy = prices[i];
        else if (prices[i] - buy > max)
            max = prices[i] - buy;
    }

    return max;
}

int main () {
	 vector<int> vec = {7,1,5,3,6,4};

	int ret = maxProfit(vec);

    cout << "Expected: " << "5" << endl;
	cout << "Output:   " << ret << endl;
}