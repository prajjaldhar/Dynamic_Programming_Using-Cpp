class Solution {
public:
    int missingNumber(vector<int>& nums) {
         map<int, bool> mp;

        // Step 1: store all elements
        for (int num : nums) {
            mp[num] = true;
        }

        // Step 2: check from 0 to n
        for (int i = 0; i <= nums.size(); i++) {
            if (mp.count(i) == 0) {
                return i;
            }
        }

        return -1; // never reached
    }
};