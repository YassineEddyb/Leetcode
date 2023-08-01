#include <iostream>
#include <vector>

using namespace std;

/*
    - Problem: Best Time to Buy and Sell Stock II

    - Difficulty: Meduim

	- Subject: 
        You are given an integer array prices where prices[i]
        is the price of a given stock on the ith day.

        On each day, you may decide to buy and/or sell the stock.
        You can only hold at most one share of the stock at any
        time. However, you can buy it then immediately sell it on
        the same day.

        Find and return the maximum profit you can achieve.
		
	- Example: 
        Input: prices = [7,1,5,3,6,4]
        Output: 7
		
	- Algorithem: Greedy Algorithem

	- Time complixity: O(n) 
	- Space complixity: O(1)

	- Approach: 
        I used gready algorithem to buy and sell every time there
        is a profit, I iterate over the array every time prices[i]
        is greater than prices[i - 1] I add the difference between
        prices[i] - prices[i - 1] to max 
        
*/

int maxProfit(vector<int>& prices) {
    int max = 0;
    for(int i = 1; i < prices.size(); i++) {
        if (prices[i] > prices[i - 1]) {
            max += prices[i] - prices[i - 1];
        }
    }
    return max;
}

int main () {
	vector<int> vec = {7,1,5,3,6,4};

	int ret = maxProfit(vec);

    cout << "Expected: " << "7" << endl;
	cout << "Output:   " << ret << endl;
}