������һ��
��� f ���飬f(i) ��ʾ [0, i-1] �Ƿ���Ա������ָ
���� f ���飬��λ�� n ��ʼ���еݹ�ö�����п��ָܷ�ķ�ʽ��ö��ʱ��ֻ��Ҫ�ж� f(i) �Ƿ���ܴ� f(j) ת�ƹ����ģ������ܣ���ݹ鵽λ�� j�� 
class Solution {
public:
    vector<string> res;
    vector<string> tmp;
    unordered_set<unsigned long long> us;
    void dfs(int pos,string s,bool *f,vector<vector<bool>>& hash)//�������� 
    {
        if(pos==-1)
        {
            string t;
            t=tmp.back();
            for(int i=tmp.size()-2;~i;i--) t+=" "+tmp[i];
            res.push_back(t);
            return;
        }
        string t;
        for(int i=pos;~i;i--)
        {
            t=s[i]+t;
            if(f[i]&&hash[i][pos])//���s[0]~s[i-1]�����ֵ��е������ ��s[i]~s[pos]���ֵ��� ������һ������ 
            {
                tmp.push_back(t);
                dfs(i-1,s,f,hash);
                tmp.pop_back();
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) 
    {
        for(auto &c:wordDict)//���ַ�����ϣ���ֵ���ĵ���ӳ��Ϊ�޷�������  ����ֵȡ131��1331 
        {
            unsigned long long p=0;
            for(auto &t:c) p=p*131+t;
            us.insert(p);
        }
        const int n=s.size();
        vector<vector<bool>> hash(n,vector<bool>(n,0));
        for(int i=0;i<n;i++)//Ԥ����hash��ʾs[i]~s[j]�Ƿ����ֵ��� 
        {
            unsigned long long p=0;
            for(int j=i;j<n;j++)
            {    
                p=p*131+s[j];
                hash[i][j]=us.count(p);
            }
        }
        bool f[n+1];
        memset(f,0,sizeof(f));
        f[0]=1;
        for(int i=0;i<n;i++)//f[i]��ʾs[0]~s[i-1]�ܷ����ֵ��е������ 
        {
            if(f[i])
                for(int j=i;j<n;j++)
                    if(hash[i][j]) f[j+1]=1;
        }
        if(!f[n]) return res;
        dfs(n-1,s,f,hash);
        return res;
    }
};
