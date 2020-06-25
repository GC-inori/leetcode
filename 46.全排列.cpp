class Solution {
public:
    int N;
    void dfs(int state,vector<int> &t,vector<vector<int>> &res,vector<int>& num) //state每一位表示是否选了该位数字 t当前解 res答案  
    {
        if(state==(1<<N)-1)
        {
            res.push_back(t);
            return;
        }
        for(int i=0;i<N;i++)
        {
            if(state&(1<<i)) continue;
            t.push_back(num[i]);
            dfs(state+(1<<i),t,res,num);
            t.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) 
    {
        N=nums.size();
        vector<vector<int>> res;
        vector<int> t;
        dfs(0,t,res,nums);
        return res;
    }
};
