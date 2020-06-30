动态规划 
class Solution {
public:
    int climbStairs(int n) 
    {
        if(n<2) return 1;
        int a=1,b=1,c;
        for(int i=2;i<=n;i++) //a表示到第i-2层的方案数 b到第i-1层的方案数 c到第i层的方案数 
        {
            c=a+b;
            a=b;
            b=c;
        }
        return c;
    }
};
