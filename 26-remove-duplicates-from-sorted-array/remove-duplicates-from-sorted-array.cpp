class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) {
            return n;
        }

        int k = 1; // Index to track unique elements
        
        for (int i = 1; i < n; ++i) {
            if (nums[i] != nums[i - 1]) {
                nums[k] = nums[i]; // Move the unique element to the next position
                k++;
            }
        }

        return k; 
    }
};