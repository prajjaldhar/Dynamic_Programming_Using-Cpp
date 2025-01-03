class Solution {
public:
    char kthCharacter(int k) {
        char current_char = 'a';
        
        // Keep track of how the string is growing
        int length = 1;  // Initially, the string is "a" with length 1
        
        // We will loop until we find that the string length is >= k
        while (length < k) {
            length *= 2;  // After each operation, the string doubles in length
        }
        
        // Now, we have a string with a length >= k, let's find the kth character
        while (length > 1) {
            int mid = length / 2;
            
            // If k is in the second half, we need to adjust k and move to the previous stage
            if (k > mid) {
                k -= mid;
                current_char = (current_char == 'z') ? 'a' : current_char + 1;  // Next character
            }
            
            // Now, we work with the first half
            length = mid;
        }
        
        return current_char;
    }
};