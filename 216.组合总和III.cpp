class Solution {
public:
    vector<vector<int>> res;
    vector<int> tmp;
    void dfs(int cur,int n,int k)//cur当前要使用的数字 n当前和目标值还差多少 k当前还剩多少数字可以使用 
    {
        if(n==0&&k==0)
        {
            res.push_back(tmp);
            return;
        }
        if(!n||!k||cur==10||n-k*cur<0||cur+k>10) return;
        dfs(cur+1,n,k);
        tmp.push_back(cur);
        dfs(cur+1,n-cur,k-1);
        tmp.pop_back();
    }
    vector<vector<int>> combinationSum3(int k, int n) 
    {
        dfs(1,n,k);
        return res;
    }
};
