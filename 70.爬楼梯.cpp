��̬�滮 
class Solution {
public:
    int climbStairs(int n) 
    {
        if(n<2) return 1;
        int a=1,b=1,c;
        for(int i=2;i<=n;i++) //a��ʾ����i-2��ķ����� b����i-1��ķ����� c����i��ķ����� 
        {
            c=a+b;
            a=b;
            b=c;
        }
        return c;
    }
};
