模拟相加即可 
class Solution {
public:
    string addBinary(string &a, string &b) 
    {
        if(a.size()>b.size()) return addBinary(b,a);
        int t=0;
        for(int i=a.size()-1,j=b.size()-1;~j;j--,i--)
        {
            if(i>=0) t+=a[i]-'0';
            t+=b[j]-'0';
            b[j]=t%2+'0';
            t/=2;
        }
        if(t) b="1"+b;
        return b;
    }
};
