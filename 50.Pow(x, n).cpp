快速幂 
class Solution {
public:
    double ksm(double x,long long n)
    {
        double res=1;
        while(n)
        {
            if(n&1) res*=x;
            x*=x;
            n>>=1;
        }
        return res;
    }
    double myPow(double x, int n) 
    {
        if(n>=0) return ksm(x,n);
        else return 1.0/ksm(x,-1ll*n);  //防止负数最大值溢出  
    }
};
