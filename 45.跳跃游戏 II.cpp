模拟 
class Solution {
public:
    int jump(vector<int>& nums) 
    {
        int res=0,maxl=0,len=0;    //maxl当前步数下跳跃的最远距离 res当前跳跃步数 
        for(int i=0,n=nums.size();i<n;i++) //len res+1布跳跃的最远距离
        {
            if(i>maxl)  //如果i>maxl 需要多跳一步 
            {
                res++;
                maxl=len;
            }
            len=max(len,nums[i]+i);  //记录下一步最远跳达位置 
        }
        return res;
    }
};
