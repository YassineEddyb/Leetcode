#include <iostream>
#include <vector>

using namespace std;

/*
	- Problem: Gas Station

	- Difficulty:

	- Subject: 
        There are n gas stations along a circular route,
        where the amount of gas at the ith station is gas[i].

        You have a car with an unlimited gas tank and it
        costs cost[i] of gas to travel from the ith station
        to its next (i + 1)th station. You begin the journey
        with an empty tank at one of the gas stations.

        Given two integer arrays gas and cost, return the
        starting gas station's index if you can travel
        around the circuit once in the clockwise direction,
        otherwise return -1. If there exists a solution,
        it is guaranteed to be unique
        
		
	- Example: 
        Input: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
        Output: 3
        Explanation:
        Start at station 3 (index 3) and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
        Travel to station 4. Your tank = 4 - 1 + 5 = 8
        Travel to station 0. Your tank = 8 - 2 + 1 = 7
        Travel to station 1. Your tank = 7 - 3 + 2 = 6
        Travel to station 2. Your tank = 6 - 4 + 3 = 5
        Travel to station 3. The cost is 5. Your gas is just enough to travel back to station 3.
        Therefore, return 3 as the starting index.
		
	- Algorithem: Gready Algorithem

	- Time complixity: O(n)
	- Space complixity: O(1)

	- Approach:
        First I realized that if the gas sum is less than
        cost sum mean's that there is not soultion I return -1,
        on the opposite if gas sum is greater than cost sum,
        There is definatly a solution, I started Iterating over
        the array with (i) and each time I calculate the current
        gas and if it ever became negative mean's there is no 
        solution starting from this index I then move start 
        to i + 1 and I initailize current gas with 0, and I
        repeat the same steps until the end of array.
*/

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int gasSum = 0;
    int costSum = 0;
    int currentGas = 0;
    int start = 0;

    for(int i = 0; i < cost.size(); i++) {
        gasSum += gas[i];
        costSum += cost[i];

        // calculate the current gas
        currentGas += gas[i] - cost[i];

        /* if ever current gas becomes negative mean's that
           you can't complete a circle for this index */
        if (currentGas < 0) {
            // move start to i + 1
            start = i + 1;
            currentGas = 0;
        }
    }

    /* if gas sum is less than cost sum mean's you
       can't complete a circle */
    if (gasSum < costSum)
        return -1;

    return start;
}

int main () {
	vector<int> gas = {1,2,3,4,5};
	vector<int> cost = {3,4,5,1,2};

	int ret  = canCompleteCircuit(gas, cost);

    cout << "Expected: 3" << endl;
	cout << "Output:   " << ret << endl;
}