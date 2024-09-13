class Solution {
public:
   bool isPowerOfTwo(int n)
    {
        // Early return for non-positive numbers
        if (n <= 0) return false;
        // Count the number of 1s in the binary representation
       if(n==1)
           return true;
        while (n%2==0) {
            n = n / 2;
        }
        // A number is a power of two if it has exactly one 1 bit in its binary representation
        return n == 1;
    }
};