环形比链式多一个限制条件 第0个和第n个不能同时选
所以分两种情况
1.不选第0个 1-n为链式
2.选第0个不选第n个 
class Solution {
public:
    int rob(vector<int>& nums) 
    {
        if(nums.empty()) return 0;
        int res=0,a=0,b=0;
        for(int i=1,n=nums.size(),c;i<n;i++)//不选第0个 
        {
            c=a;//a表示抢劫第i个屋子的最大收益 
            a=b+nums[i];//b表示不抢劫第i个屋子的最大收益 
            b=max(c,b);
        }
        res=max(a,b);
        a=nums[0],b=0;
        for(int i=1,n=nums.size(),c;i<n;i++)//不选第n个 
        {
            c=a;
            a=b+nums[i];
            b=max(c,b);
        }
        return max(nums.size()>1?b:a,res);//防止只有一个元素的情况 
    }
};
