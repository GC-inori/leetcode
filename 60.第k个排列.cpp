类似数位dp 
class Solution {
public:
    string getPermutation(int n, int k) 
    {
        int cnt[10],res=0;
        bool use[10]={0};
        cnt[0]=1;
        for(int i=1;i<n;i++) cnt[i]=cnt[i-1]*i; //考虑第i+1位不变， 1~i位有多少种排列 
        for(int i=n-1;~i;i--)
            for(int j=0;j<n;j++) //找到未使用过的数字 
                if(!use[j])
                {
                    if(k>cnt[i]) //如果第i+1位填j的方案数不够k种，寻找下一个未使用过的数字 
                        k-=cnt[i];
                    else
                    {
                        res=res*10+j+1;  //否则使用j 
                        use[j]=1;
                        break;
                    }
                }
        return to_string(res);
    }
};
