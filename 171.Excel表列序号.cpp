逐个读取字符进行转换，本质上是26进制转10进制。
例如，BC=2×26^1+3×26^0=55。
class Solution {
public:
    int titleToNumber(string s) 
    {
        long long p=1,res=0;
        for(int i=s.size()-1;~i;i--)
        {
            res+=p*(s[i]-'A'+1);
            p*=26;
        }
        return res;
    }
};
