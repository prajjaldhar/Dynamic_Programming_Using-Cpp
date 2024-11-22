class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // int maxi = *max_element(nums.begin(),nums.end());
        // vector<int>freq(maxi+1);
        map<int,int>freq;
         for(auto it:nums)
        {
            freq[it]++;
            if(freq[it]>nums.size()/2)
            {
                return it;
        
            }
        }
        return -1;
    }
};