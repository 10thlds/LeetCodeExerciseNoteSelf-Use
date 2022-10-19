/*
Given an integer x, return true if x is palindrome integer.

An integer is a palindrome when it reads the same backward as forward.

For example, 121 is a palindrome while 123 or -121 are not.
*/

class Solution {
public:
    bool isPalindrome(int x) {
		if (x<0 || (x % 10 == 0 && x!=0))
        {						// Negetive numbers and one whose last digit is 0 are removed.
            return false;
        }
        int y = 0;
        while (x>y)				// Actually only consider half of the digits of the number
        {						// x = 52325	
            y = y * 10 + x%10;	// y = 5		y = 52		y = 523		y = 5232...
            x /= 10;			// x = 5232		x = 523		x = 52		x = 5	...
        }
    return x == y || x == y/10;	// Consider even and odd number...
    }
};
