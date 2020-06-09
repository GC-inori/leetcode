排序 + 双指针
本题的难点在于如何去除重复解。
算法流程：
对数组进行排序。
遍历排序后数组：
若 nums[i]>0：因为已经排序好，所以后面不可能有三个数加和等于 0，直接返回结果。
对于重复元素：跳过，避免出现重复解
令左指针 L=i+1，右指针 R=n-1，当 L<R 时，执行循环：
当 nums[i]+nums[L]+nums[R]==0，执行循环，判断左界和右界是否和下一位置重复，去除重复解。并同时将 L,R 移到下一位置，寻找新的解
若和大于 0，说明 nums[R] 太大，R 左移
若和小于 0，说明 nums[L] 太小，L 右移
class Solution 
{
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<vector<int>> res;
        if(nums.size()<3) return res;
        sort(nums.begin(),nums.end());
        for(int i=0,n=nums.size();i<n;i++)
        {
            if(i&&nums[i]==nums[i-1]) continue;  //去除重复解 
            int l=i+1,r=n-1;
            if(nums[i]>0) break;
            while(l<r)
            {
                if(nums[l]+nums[r]==-nums[i])
                {
                    res.push_back({nums[i],nums[l],nums[r]});
                    l++,r--;
                    while(l<r&&nums[l]==nums[l-1]) l++; //去除重复解 
                    while(l<r&&nums[r]==nums[r+1]) r--;
                }
                else if(nums[l]+nums[r]<-nums[i]) l++;
                else r--;

            }
        }
        return res;
    }
};
