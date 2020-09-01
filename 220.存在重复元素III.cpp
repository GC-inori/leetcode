由于如果出现重复值肯定符合题目要求 所以用set即可 
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) 
    {
        set<long long> s;
        s.insert(1e12);
        s.insert(-1e12);
        for(int i=0,n=nums.size();i<n;i++)
        {
            if(i>k)
                s.erase(nums[i-k-1]);
            auto tt=s.lower_bound(nums[i]);//找打第一个大于等于nums[i]的数 
            if(abs(*tt-nums[i])<=t) return 1;
            tt--;//找到小于nums[i]最大的数 
            if(abs(*tt-nums[i])<=t) return 1;
            s.insert(nums[i]);
        }
        return 0;
    }
};
