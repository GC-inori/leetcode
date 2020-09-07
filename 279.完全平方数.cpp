法1 找到所有小于n的完全平方数 完全背包问题
2.数学法
拉格朗日四平方和定理：每个正整数均可表示为4个整数的平方和。 
勒让德三平方和定理 ：x=a*a+b*b+c*c 当且仅当 n!=4^(p)*(8q+7) 
class Solution {
public:
    bool check(int x)
    {
        int r=sqrt(x);
        return r*r==x;
    }
    int numSquares(int n) 
    {
        if(check(n)) return 1;
        for(int i=1;i<=n/i;i++)
            if(check(n-i*i)) return 2;
        while(n%4==0) n/=4;
        return n%8==7?4:3;
    }
};
