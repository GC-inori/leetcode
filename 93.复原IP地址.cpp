������������ 
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
        for(int i=0,n=s.size();i<3;i++)//�����Ϊ0-i i+1~j j+1~k k+1~n-1�Ĳ��� 
            if(change(s,0,i)<256) //�ж�ÿ�����Ƿ�Ϸ� 
                for(int j=i+1;j<i+4&&j<n;j++)
                    if(change(s,i+1,j)<256)
                        for(int k=j+1;k<j+4&&k<n-1;k++)//k<n-1 ��֤���Ĳ���������һ���� 
                        {
                            if(change(s,j+1,k)<256&&n-k<5&&change(s,k+1,n-1)<256) //n-k<5���Ĳ�����������λ 
                            {
                                string t=s.substr(0,i+1)+"."+s.substr(i+1,j-i)+"."+s.substr(j+1,k-j)+"."+s.substr(k+1);
                                res.push_back(t);
                            }
                        }
            
        return res;    
    }
};
