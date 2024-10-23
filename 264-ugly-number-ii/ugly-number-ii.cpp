class Solution {
public:
    int nthUglyNumber(int n) {
         // Array to store the first n ugly numbers
        vector<int> ugly(n);
        ugly[0] = 1;  // The first ugly number is 1.
        
         int index2 = 0, index3 = 0, index5 = 0;
       int factor2 = 2, factor3 = 3, factor5 = 5;
        
        for (int i = 1; i < n; i++) {
            // The next ugly number is the minimum of the next multiples of 2, 3, and 5.
            int nextUgly = min(factor2, min(factor3, factor5));
            ugly[i] = nextUgly;
            
             if (factor2 == nextUgly)
                factor2 = 2 * ugly[++index2];
            if (factor3 == nextUgly)
                factor3 = 3 * ugly[++index3];
            if (factor5 == nextUgly)
                factor5 = 5 * ugly[++index5];
        }
        
        // Return the nth ugly number.
        return ugly[n - 1];
    }
};