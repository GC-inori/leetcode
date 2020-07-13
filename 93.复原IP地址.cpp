暴力搜索即可 
class Solution {
public:
    int change(string &s,int l,int r)
    {
        if(r>=s.size()) return 256;
        int res=0;
        for(int i=l;i<=r;i++)
            res=res*10+s[i]-'0';
        if(r>l&&res<pow(10,r-l)) return 256;
        return res;
    }
    vector<string> restoreIpAddresses(string s) 
    {
        vector<string> res;
        for(int i=0,n=s.size();i<3;i++)//将其分为0-i i+1~j j+1~k k+1~n-1四部分 
            if(change(s,0,i)<256) //判断每部分是否合法 
                for(int j=i+1;j<i+4&&j<n;j++)
                    if(change(s,i+1,j)<256)
                        for(int k=j+1;k<j+4&&k<n-1;k++)//k<n-1 保证第四部分至少有一个数 
                        {
                            if(change(s,j+1,k)<256&&n-k<5&&change(s,k+1,n-1)<256) //n-k<5第四部分至多有三位 
                            {
                                string t=s.substr(0,i+1)+"."+s.substr(i+1,j-i)+"."+s.substr(j+1,k-j)+"."+s.substr(k+1);
                                res.push_back(t);
                            }
                        }
            
        return res;    
    }
};
