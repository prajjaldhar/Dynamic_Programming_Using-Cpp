class Solution {
public:
    string multiply(string num1, string num2) {
         int m = num1.size(), n = num2.size();
    vector<int> result(m + n, 0);  // Result can have at most m + n digits

    // Reverse iteration for each digit of num1 and num2
    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            // Multiply the current digits
            int mul = (num1[i] - '0') * (num2[j] - '0');
            
            // Sum up at the appropriate position
            int sum = mul + result[i + j + 1]; 
            
            // Set the current position's value and handle the carry
            result[i + j + 1] = sum % 10;
            result[i + j] += sum / 10;
        }
    }

    // Convert the result array back to a string
    string product = "";
    for (int num : result) {
        if (!(product.empty() && num == 0)) {  // Skip leading zeros
            product += to_string(num);
        }
    }

    // If product is empty, that means the result is 0
    return product.empty() ? "0" : product;
    }
};