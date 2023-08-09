#include <iostream>
#include <map>
#include <cmath>

using namespace std;

/*
	- Problem: Integer to Roman

	- Difficulty: Meduim

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
        just two one's added together. 12 is written as XII,
        which is simply X + II. The number 27 is written as
        XXVII, which is XX + V + II.

        Roman numerals are usually written largest to smallest
        from left to right. However, the numeral for four is
        not IIII. Instead, the number four is written as IV.
        Because the one is before the five we subtract it
        making four. The same principle applies to the number
        nine, which is written as IX. There are six instances
        where subtraction is used:

        I can be placed before V (5) and X (10) to make 4 and 9. 
        X can be placed before L (50) and C (100) to make 40 and 90. 
        C can be placed before D (500) and M (1000) to make 400 and 900.
        Given an integer, convert it to a roman numeral.
		
	- Example: 
        Input: num = 3
        Output: "III"
        Explanation: 3 is represented as 3 ones.
		
	- Algorithem: hash map

	- Time complixity: O(n)
	- Space complixity: O(1)

	- Approach:
*/

string intToRoman(int num) {
    map<int, char> roman;
    roman[1] = 'I';
    roman[5] = 'V';
    roman[10] = 'X';
    roman[50] = 'L';
    roman[100] = 'C';
    roman[500] = 'D';
    roman[1000] = 'M';

    string tmp = to_string(num);
    int numDigits = tmp.length();
    
    string res = "";
    for(int i = 0; i < numDigits; ++i) {
        char src = tmp[i];
        int number = (src - '0');
        int place = (numDigits - 1) - i;
        int absolute = pow(10, place);
        
        if (number == 9) {
            res.append(1, roman[absolute]);
            res.append(1, roman[(number + 1) * absolute]);
        } else if (number >= 5) {
            res.append(1, roman[5 * absolute]);
            res.append(number - 5, roman[absolute]);
        } else if (number >= 4) {
            res.append(1, roman[absolute]);
            res.append(1, roman[5 * absolute]);
        } else {
            res.append(number, roman[absolute]);
        }
    }
    return res;
}

int main () {
    string ret = intToRoman(3);

	cout << "Expected: " << "III" << endl;
	cout << "Output:   " << ret << endl;
}