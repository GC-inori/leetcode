类似26题 
class Solution {
public:
    int removeElement(vector<int>& nums, int val) 
    {
        if(nums.empty()) return 0;
        int res=0;  //不等于val的个数 
        for(int i=0,n=nums.size();i<n;i++)
            if(nums[i]!=val) nums[res++]=nums[i];  //如果不相等移动 
        return res;
    }
};
