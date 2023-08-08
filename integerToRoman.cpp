#include <iostream>
#include <map>
#include <cmath>

using namespace std;

/*
	- Problem: 

	- Difficulty:

	- Subject: 
		
	- Example: 
		
	- Algorithem: 

	- Time complixity: 
	- Space complixity:

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
    string ret = intToRoman(4);

	cout << "Expected: " << " " << endl;
	cout << "Output:   " << ret << endl;
}