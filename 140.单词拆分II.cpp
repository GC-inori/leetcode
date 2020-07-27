类似上一题
求出 f 数组，f(i) 表示 [0, i-1] 是否可以被完整分割。
根据 f 数组，从位置 n 开始进行递归枚举所有可能分割的方式。枚举时，只需要判断 f(i) 是否可能从 f(j) 转移过来的，若可能，则递归到位置 j。 
class Solution {
public:
    vector<string> res;
    vector<string> tmp;
    unordered_set<unsigned long long> us;
    void dfs(int pos,string s,bool *f,vector<vector<bool>>& hash)//倒着搜索 
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
            if(f[i]&&hash[i][pos])//如果s[0]~s[i-1]能由字典中单词组成 且s[i]~s[pos]在字典中 搜索下一个单词 
            {
                tmp.push_back(t);
                dfs(i-1,s,f,hash);
                tmp.pop_back();
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) 
    {
        for(auto &c:wordDict)//用字符串哈希将字典里的单词映射为无符号整数  经验值取131或1331 
        {
            unsigned long long p=0;
            for(auto &t:c) p=p*131+t;
            us.insert(p);
        }
        const int n=s.size();
        vector<vector<bool>> hash(n,vector<bool>(n,0));
        for(int i=0;i<n;i++)//预处理hash表示s[i]~s[j]是否在字典中 
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
        for(int i=0;i<n;i++)//f[i]表示s[0]~s[i-1]能否由字典中单词组成 
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
