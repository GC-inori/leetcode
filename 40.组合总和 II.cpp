暴力枚举 
class Solution {
public:
    void dfs(vector<vector<int>> &res,vector<int>& candidates,int now,int pos,int target,vector<int>& t) //res保存答案  now当期数字之和 pos当前第几个数字 t当前解 
    {
        if(now==target)  //如果等于目标值 保存 
        {
            res.push_back(t);
            return;
        }
        if(now>target||candidates.size()<=pos) return;
        t.push_back(candidates[pos]);
        dfs(res,candidates,now+candidates[pos],pos+1,target,t);  //选第pos个数字 
        t.pop_back();
        do pos++;while(pos<candidates.size()&&candidates[pos]==candidates[pos-1]); //如果不选第pos个数字 跳过与 candidates[pos]相等的数字 避免重复解 
        dfs(res,candidates,now,pos,target,t);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        vector<vector<int>> res;
        vector<int> t;
        sort(candidates.begin(),candidates.end()); //先排序 便于之后判重 
        dfs(res,candidates,0,0,target,t);
        return res;
    }
};
