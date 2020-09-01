class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) 
    {
        unordered_set<int> us;
        for(int i=0,n=nums.size();i<n;i++)
        {
            if(i>k) us.erase(nums[i-k-1]);
            if(us.count(nums[i])) return 1;
            us.insert(nums[i]);
        }
        return 0;
    }
};
