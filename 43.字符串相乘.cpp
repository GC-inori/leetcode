直接模拟竖式乘法计算。
乘积的最大长度为两个乘数的长度之和。
class Solution {
public:
    string multiply(string num1, string num2) 
    {
        int mul1[120],mul2[120],res[230]={0},n=num1.size(),m=num2.size(),len=m+n-1;
        for(int i=0;i<n;i++) mul1[n-i-1]=num1[i]-'0';
        for(int i=0;i<m;i++) mul2[m-i-1]=num2[i]-'0';
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                res[i+j]+=mul1[i]*mul2[j];  //计算每一位乘积 
                res[i+j+1]+=res[i+j]/10;
                res[i+j]%=10;
            }
        while(len&&res[len]==0) len--;  //len最小到0 此时两数相乘结果为0 
        string ans;
        for(int i=len;~i;i--)
            ans.push_back(res[i]+'0');
        return ans;
    }
};
