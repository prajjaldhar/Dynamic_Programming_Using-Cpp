class Solution {
public:
  int firstMissingPositive(vector<int>& nums) {
    map<int, bool> mp;

    // Store all elements
    for (int num : nums) {
        mp[num] = true;
    }

    // Check from 1 to n
    
    for (int i=1; i <= nums.size(); i++) {
        if (mp.count(i) == 0) {
            return i;
        }
    }
        return nums.size() + 1;
    }
};