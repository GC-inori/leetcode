求组和数 总共要走n+m-2步 从中选m-1步向下走 
class Solution {
public:
    int uniquePaths(int m, int n) 
    {
        long long res=1;
        if(m>n) swap(m,n); //用m、n中较小值计算组合数 
        for(int i=1,j=m+n-2;i<m;i++,j--) //计算C(m+n-2,m-1); 
        {
            res=res*j/i;
        }
        return res;    
    }
};
