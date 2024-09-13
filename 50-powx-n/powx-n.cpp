class Solution {
public:
    double myPow(double x, int n) {
         if (n == 0) {
           return 1.0; }// Anything raised to the power of 0 is 1.
         return pow(x,n);
    }
    
   
};