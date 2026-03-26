class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
          int i = 0; // even index
        int j = 1; // odd index
        int n = nums.size();

        while (i < n && j < n) {
            if (nums[i] % 2 == 0) {
                i += 2; // correct
            } else {
                // find wrong element at odd index
                while (nums[j] % 2 == 1) {
                    j += 2;
                }
                swap(nums[i], nums[j]);
            }
        }

        return nums;
    }
};