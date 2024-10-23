class Solution {
public:
    int myAtoi(string s) {
         int i = 0;
        int n = s.size();
        int sign = 1; // To store the sign of the number
        long result = 0; // Result to store the number (using long to prevent overflow during calculation)
        
        // Step 1: Ignore leading whitespace
        while (i < n && s[i] == ' ') {
            i++;
        }
        
        // Step 2: Check if the next character is '-' or '+'
        if (i < n && (s[i] == '-' || s[i] == '+')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        
        // Step 3: Convert the number and handle non-digit characters
        while (i < n && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');
            
            // If the result goes out of 32-bit signed integer bounds, clamp it
            if (result > INT_MAX) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            
            i++;
        }
        
        // Step 4: Return the result with the correct sign
        return sign * result;
    }
};