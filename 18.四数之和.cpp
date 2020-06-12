类似第15题三数之和，枚举起点加双指针 
class Solution 
{
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        vector<vector<int>> res;
        if(nums.size()<4) return res;
        sort(nums.begin(),nums.end());
        for(int i=0,n=nums.size();i<n-3;i++)
        {
            if(nums[i]+nums[i+1]>target&&nums[i]>0) break; //不满足条件退出 
            if(i&&nums[i]==nums[i-1]) continue;  //避免重复解 
            for(int j=i+1;j<n-2;j++)
            {
                if(nums[i]+nums[j]>target&&nums[j]>0) break;
                if(j>i+1&&nums[j]==nums[j-1]) continue;
                int l=j+1,r=n-1,s=target-nums[i]-nums[j];
                while(l<r)
                {
                    if(nums[l]+nums[r]<s) l++;
                    else if(nums[l]+nums[r]>s) r--;
                    else
                    {
                        res.push_back({nums[i],nums[j],nums[l],nums[r]});
                        l++,r--;
                        while(l<r&&nums[l]==nums[l-1]) l++;
                        while(l<r&&nums[r]==nums[r+1]) r--;
                    }
                }
            }
        }
        return res;
    }
};
