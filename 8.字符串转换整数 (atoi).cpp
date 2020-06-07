class Solution 
{
public:
    int myAtoi(string s) 
    {
        long long res=0,flag=1;   //flag表示是正数还是负数
        for(int i=0,n=s.size();i<n;i++)
        {
            if(s[i]==' ') continue;
            if(s[i]=='-') flag=-1,i++;
            else if(s[i]=='+') i++;
            while(i<n&&s[i]<='9'&&s[i]>='0') 
            {
                res=res*10+s[i]-'0';
                if(res*flag<INT_MIN) return INT_MIN;
                if(res*flag>INT_MAX) return INT_MAX;
                i++; 
            }
            break;  //如果不是数字跳出循环
        }
        return res*flag;
    }
};
