class Solution {
public:
    int nthUglyNumber(int n) {
         // Array to store the first n ugly numbers
        vector<int> uglyNumbers(n);
        uglyNumbers[0] = 1;  // The first ugly number is 1.
        
        int i2 = 0, i3 = 0, i5 = 0; // Indices for multiples of 2, 3, and 5.
        int nextMultipleOf2 = 2, nextMultipleOf3 = 3, nextMultipleOf5 = 5;
        
        for (int i = 1; i < n; i++) {
            // The next ugly number is the minimum of the next multiples of 2, 3, and 5.
            int nextUgly = min(nextMultipleOf2, min(nextMultipleOf3, nextMultipleOf5));
            uglyNumbers[i] = nextUgly;
            
            // Update the next multiples based on which one was the next ugly number.
            if (nextUgly == nextMultipleOf2) {
                i2++;
                nextMultipleOf2 = uglyNumbers[i2] * 2;
            }
            if (nextUgly == nextMultipleOf3) {
                i3++;
                nextMultipleOf3 = uglyNumbers[i3] * 3;
            }
            if (nextUgly == nextMultipleOf5) {
                i5++;
                nextMultipleOf5 = uglyNumbers[i5] * 5;
            }
        }
        
        // Return the nth ugly number.
        return uglyNumbers[n - 1];
    }
};