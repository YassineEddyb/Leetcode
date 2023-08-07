#include <iostream>
#include <map>

using namespace std;

/*
	- Problem: Roman to Integer

	- Difficulty: Easy

	- Subject:
		Roman numerals are represented by seven different
		symbols: I, V, X, L, C, D and M.

		Symbol       Value
		I             1
		V             5
		X             10
		L             50
		C             100
		D             500
		M             1000
		For example, 2 is written as II in Roman numeral,
		just two ones added together. 12 is written as XII,
		which is simply X + II. The number 27 is written
		as XXVII, which is XX + V + II.

		Roman numerals are usually written largest to smallest
		from left to right. However, the numeral for four
		is not IIII. Instead, the number four is written as
		IV. Because the one is before the five we subtract it 
		making four. The same principle applies to the number
		nine, which is written as IX. There are six instances
		where subtraction is used:

		I can be placed before V (5) and X (10) to make 4 and 9. 
		X can be placed before L (50) and C (100) to make 40 and 90. 
		C can be placed before D (500) and M (1000) to make 400 and 900.
		Given a roman numeral, convert it to an integer.
		
	- Example: 
		Input: s = "LVIII"
		Output: 58
		Explanation: L = 50, V= 5, III = 3.
		
	- Algorithem: Hash Map

	- Time complixity: O(n)
	- Space complixity: O(n)

	- Approach:
		I used a hash map to map all character to thier value
		and then I iterate over str and I add the coresponding
		value of str[i] to sum.

*/

int romanToInt(string str) {
    map<char, int> m;
    m.insert({ 'I', 1 });
    m.insert({ 'V', 5 });
    m.insert({ 'X', 10 });
    m.insert({ 'L', 50 });
    m.insert({ 'C', 100 });
    m.insert({ 'D', 500 });
    m.insert({ 'M', 1000 });

    int sum = 0;

    for (int i = 0; i < str.length(); i++)
    {
		/* this condition is for if there is a number like
		   (IV) it should be counted 4 not 6 so if str[i] < str[i + 1]
		   I substruct str[i] from str[i + 1] and add to sum */
		if (m[str[i]] < m[str[i + 1]]) {
			sum += m[str[i + 1]] - m[str[i]];
			i++;
		} else
			// else I simply add the coresponding number
			sum += m[str[i]];
    }
    return sum;
}

int main () {
	string s = "LVIII";

	int ret = romanToInt(s);

	cout << "Expected: 58" << endl;
	cout << "Output:   " << ret << endl;
}