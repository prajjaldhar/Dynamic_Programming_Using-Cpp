class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
         int n = nums.size();
        
        vector<int> even, odd;

        // collect
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) even.push_back(nums[i]);
            else odd.push_back(nums[i]);
        }

        // sort
        sort(even.begin(), even.end());                 // increasing
        sort(odd.begin(), odd.end(), greater<int>());   // decreasing

        // two pointers for placement
        int i = 0, j = 0;

        for (int k = 0; k < n; k++) {
            if (k % 2 == 0) {
                nums[k] = even[i++];
            } else {
                nums[k] = odd[j++];
            }
        }

        return nums;
    }
};