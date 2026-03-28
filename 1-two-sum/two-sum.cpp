class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>bank;
        for(int i=0;i<nums.size();i++)
        {
            int need=target-nums[i];
            if(bank.count(need))
            {
                return {bank[need],i};
            }
            bank[nums[i]]=i;
        }
        return {};
    }
};