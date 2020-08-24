f[i][j] 表示前i间房屋中，第i间打劫状态为j的最大收益
f[i][0]=max(f[i-1][0],f[i-1][1]) 上一间没打劫或打劫了的最大值
f[i][1]=f[i-1][0]+nums[i]; 
class Solution {
public:
    int rob(vector<int>& nums) 
    {
        if(nums.empty()) return 0;
        int a=0,b=nums[0];//a表示没打劫 b表示打劫了 
        for(int i=1,n=nums.size(),c;i<n;i++)
        {
            c=a;
            a=max(b,a);
            b=c+nums[i];
        }
        return max(a,b);
    }
};
