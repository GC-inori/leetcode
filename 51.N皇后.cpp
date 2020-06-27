暴力搜索 
class Solution {
public:
    void dfs(int pos,vector<int> &tmp,vector<vector<string>> &res) //tmp[i] 表示在第i行tmp[j]列放置了皇后  res保存答案  pos当前行数 
    {
        if(pos==tmp.size())
        {
            vector<string> t;
            for(int i=0;i<pos;i++)
            {
                string s;
                for(int j=0;j<pos;j++)
                {
                    if(j!=tmp[i]) s+='.';
                    else s+='Q';
                }
                t.push_back(s);
            }
            res.push_back(t);
            return;
        }
        for(int i=0;i<tmp.size();i++)
        {
            bool f=1;
            for(int j=0;j<pos;j++)
            {
                if(tmp[j]==i||abs(tmp[j]-i)==abs(pos-j))
                {
                    f=0;
                    break;
                }
            }
            tmp[pos]=i;
            if(f) dfs(pos+1,tmp,res);
        }
    }
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<int> tmp(n);
        vector<vector<string>> res;
        dfs(0,tmp,res);
        return res;    
    }
};
