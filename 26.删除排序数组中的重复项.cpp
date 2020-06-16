双指针移动 
class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        if(nums.empty()) return 0;
        int res=1; //表示无重复数字个数 
        for(int i=1,n=nums.size();i<n;i++)
            if(nums[i]!=nums[i-1]) nums[res++]=nums[i]; //如果和前一个不相等，那么就是无重复的 
        return res;
    }
};
