class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1;
    int j = num2.size() - 1;
    int carry = 0;
    string result = "";

    // Traverse both strings from the end towards the beginning
    while (i >= 0 || j >= 0 || carry > 0) {
        // Get the current digits from num1 and num2 or 0 if out of bounds
        int digit1 = (i >= 0) ? num1[i] - '0' : 0;
        int digit2 = (j >= 0) ? num2[j] - '0' : 0;
        
        // Calculate sum of current digits and carry
        int sum = digit1 + digit2 + carry;
        
        // Update carry for the next iteration
        carry = sum / 10;
        
        // Append the current digit (sum % 10) to the result
        result += to_string(sum % 10);
        
        // Move to the previous digits
        i--;
        j--;
    }

    // Since we added digits from the least significant to the most, we reverse the result
    reverse(result.begin(), result.end());
    return result;
    }
};