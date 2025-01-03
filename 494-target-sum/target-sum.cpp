class Solution {
public:
     int findTargetSumWays(vector<int>& nums, int target) {
        int result = 0;
        backtrack(nums, 0, target, 0, result);
        return result;
    } 
    void backtrack(vector<int>& nums, int index, int target, int currentSum, int& result) {
        // Base case: If we have considered all numbers
        if (index == nums.size()) {
            // If the current sum equals the target, we found a valid expression
            if (currentSum == target) {
                result++;
            }
            return;
        }
        
        // Try adding the current number with a positive sign
        backtrack(nums, index + 1, target, currentSum + nums[index], result);
        
        // Try adding the current number with a negative sign
        backtrack(nums, index + 1, target, currentSum - nums[index], result);
    }
};