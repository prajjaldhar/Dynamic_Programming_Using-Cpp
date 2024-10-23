class Solution {
public:
    int countDigitOne(int n) {
         long long count = 0;
        long long factor = 1;
        
        while (n / factor > 0) {
            long long lower = n - (n / factor) * factor; // Digits lower than the current digit
            long long current = (n / factor) % 10; // Current digit
            long long higher = n / (factor * 10); // Digits higher than the current digit
            
            // If the current digit is greater than 1
            if (current > 1) {
                count += (higher + 1) * factor;
            }
            // If the current digit is 1
            else if (current == 1) {
                count += higher * factor + (lower + 1);
            }
            // If the current digit is 0
            else {
                count += higher * factor;
            }
            
            // Move to the next higher place value
            factor *= 10;
        }
        
        return count;
    }
};