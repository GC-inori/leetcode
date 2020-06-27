class Solution {
public:
    bool canJump(vector<int>& nums) 
    {
        int st=nums.size()-1;  //st表示能够到达末尾最小的点 
        for(int i=nums.size()-2;i>=0;i--) //从倒数第二个点开始 
            if(nums[i]+i>=st) st=i;  //如果能到达更新 
        return st==0; //判断起点能否到达 
    }
};
