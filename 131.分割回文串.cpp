���ȶ�̬�滮����f[i][j] ��ʾs[i~j]�Ƿ��ǻ��Ĵ�
���i==j ��Ȼf[i][j]=1;
���s[i]!=s[j]���ǻ��Ĵ�
s[i]==s[j]
1.i==j-1��ʱֻ�������ַ���� f[i][j]=1
2.j-1>i ��ʱf[i][j]=f[i+1][j-1] 
Ȼ������������������� 
class Solution {
public:
    vector<vector<string>> res;
    vector<string> tmp;
    void dfs(string &s,int pos,vector<vector<bool>> &f)
    {
        if(pos==s.size())
        {
            res.push_back(tmp);
            return;
        }
        for(int r=pos;r<s.size();r++)
        {
            if(f[pos][r])
            {
                tmp.push_back(s.substr(pos,r-pos+1));
                dfs(s,r+1,f);
                tmp.pop_back();
            }
        }

    }
    vector<vector<string>> partition(string s) 
    {
        const int n=s.size();
        vector<vector<bool>> f(n,vector<bool>(n,0));
        for(int len=1;len<=n;len++)
            for(int i=0;i+len-1<n;i++)
                if(len==1||(s[i]==s[len+i-1]&&len==2)||(s[i]==s[i+len-1]&&f[i+1][i+len-2])) f[i][i+len-1]=1;//��̬�滮�����Ĵ� 
        dfs(s,0,f);
        return res;
    }
};
