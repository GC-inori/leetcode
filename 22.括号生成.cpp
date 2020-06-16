直接生成合法的括号序列 dfs
每次可以放置左括号的条件是当前左括号的数目不超过 n。
每次可以放置右括号的条件是当前右括号的数目不超过左括号的数目。
class Solution {
public:
    int max;
    void dfs(int left,int right,string &cur,vector<string> &res) //left左括号数 right右括号数 cur当前括号序列 res答案数组 max最多使用括号数 
    {
        if(left==max&&right==max)
        {
            res.push_back(cur);
            return;
        }
        if(left<max)
        {
            cur[left+right]='(';
            dfs(left+1,right,cur,res);
        }
        if(left>right)
        {
            cur[left+right]=')';
            dfs(left,right+1,cur,res);
        }

    }
    vector<string> generateParenthesis(int n) 
    {
        max=n;
        vector<string> res;
        string s(n+n,'(');
        dfs(0,0,s,res);
        return res;    
    }
};
