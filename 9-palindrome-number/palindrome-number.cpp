class Solution {
public:
    bool isPalindrome(int x) {
         // Negative numbers and numbers ending with 0 (except 0 itself) are not palindromes.
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int reversed = 0;
        while (x > reversed) {
            reversed = reversed * 10 + x % 10;
            x /= 10;
        }

        // For even-length numbers, x and reversed will be the same.
        // For odd-length numbers, reversed will have an extra digit in the middle, which we can ignore.
        return x == reversed || x == reversed / 10;
    }
};