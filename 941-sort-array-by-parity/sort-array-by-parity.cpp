class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
          int i = 0;
        int j = nums.size() - 1;

        while (i < j) {
            if (nums[i] % 2 == 0) {
                i++; // even → correct side
            } else {
                swap(nums[i], nums[j]);
                j--; // move odd to end
            }
        }

        return nums;
    }
};