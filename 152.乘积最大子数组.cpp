Max表示以nums[i]结尾的连续字数乘积的最大值 Min表示以nums[i]结尾的连续字数乘积的最小值 
class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int Max=nums[0],Min=nums[0],t1,t2,res=nums[0];
        for(int i=1,n=nums.size();i<n;i++)
        {
            t1=Max*nums[i],t2=nums[i]*Min;
            Max=max(nums[i],max(t1,t2));//要么只包含自己 要么和前面的子序列连起来 
            Min=min(nums[i],min(t1,t2));
            res=max(res,Max);
        }
        return res;
    }
};
