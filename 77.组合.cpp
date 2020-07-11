class Solution {
public:
    void dfs(vector<vector<int>> &res,int now,int use,int k,vector<int> &tmp)//now从n开始枚举，枚举到了数字now use当前使用数字个数 tmp当前解 
    {
        if(use==k)
        {
            res.push_back(tmp);
            return;
        }
        if(!now||now+use<k) return;//如果剩余数字不够返回 
        tmp[use]=now;//选数字now 
        dfs(res,now-1,use+1,k,tmp);
        dfs(res,now-1,use,k,tmp);//不选数字now 
    }
    vector<vector<int>> combine(int n, int k) 
    {
        vector<vector<int>>  res;
        vector<int> tmp(k);
        dfs(res,n,0,k,tmp);
        return res;  
    }
};
