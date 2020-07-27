class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        int res=0;
        unordered_set<int> s(nums.begin(),nums.end());
        for(auto c:nums)
        {
            if(s.count(c-1)) continue;//防止多次查找 每次枚举连续区间时 只从最小的数字开始枚举 
            int t=c+1;
            while(s.count(t)) t++;
            res=max(res,t-c);
        }
        return res;
    }
};
