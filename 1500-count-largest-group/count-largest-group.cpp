class Solution {
public:
int digitSum(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}
    int countLargestGroup(int n) {
         map<int, int> mp;

        // Step 1 & 2: Fill map with digit sum frequency
        for (int i = 1; i <= n; i++) {
            int sum = digitSum(i);
            mp[sum]++;
        }

        // Step 3: Find max group size
        int maxSize = 0;
        for (auto it : mp) {
            maxSize = max(maxSize, it.second);
        }

        // Step 4: Count how many groups have max size
        int count = 0;
        for (auto it : mp) {
            if (it.second == maxSize) {
                count++;
            }
        }

    return count;
    }
};