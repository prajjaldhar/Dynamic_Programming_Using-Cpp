class Solution {
public:
    int minimumOperations(vector<int>& nums) {
            map<int, bool> mp;

    for (int num : nums) {
        if (num != 0) {
            mp[num] = true;
        }
    }

    return mp.size();
    }
};