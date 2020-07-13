设h(n)为catalan数的第n+1项，令h(0)=1,h(1)=1，catalan数满足递推式 ：
h(n)= h(0)*h(n-1)+h(1)*h(n-2) + ... + h(n-1)*h(0) (n>=2)
由上一题可知
数量满足卡特兰数的规律
class Solution {
public:
    int numTrees(int n) 
    {
        if(n<1) return 0;
        long long res=1;
        for(int i=2*n,j=1;i>n;i--,j++)
            res=res*i/j;
        return res/(n+1);
    }
}; 
