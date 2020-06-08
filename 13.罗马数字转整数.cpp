模拟即可，如果前一个字母的权值大于后一个加上权值，否则减去 
class Solution 
{
public:
    int romanToInt(string s) 
    {
        int res=0;
        int rome[256];
        rome['I']=1, rome['V']=5, rome['X']=10,
        rome['L']=50, rome['C']=100, rome['D']=500,
        rome['M']=1000;
        for(int i=0,n=s.size();i<n;i++)
        {
            if(i<n-1&&rome[s[i]]<rome[s[i+1]]) res-=rome[s[i]]; //减去权值如IX -1+10 
            else res+=rome[s[i]];
        }
        return res;
    }
};
