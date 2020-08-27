基于dfs的拓扑排序 
class Solution {
public:
    vector<int> res;
    bool dfs(int cur,vector<vector<int>> &e,vector<int> &f)
    {
        f[cur]=1;//1表示正在搜索中 
        for(auto &c:e[cur])
            if(f[c]==1||(!f[c]&&!dfs(c,e,f))) return 0;//如果遇到了正在搜索的点，或子节点存在环 返回0 
        res.push_back(cur);
        f[cur]=2;//2表示搜索完成 
        return 1;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<vector<int>> e(numCourses);
        for(auto &c:prerequisites)
            e[c[1]].push_back(c[0]);
        vector<int> f(numCourses,0);
        for(int i=0;i<numCourses;i++)
            if(!f[i]&&!dfs(i,e,f))  return {};//dfs每个未搜索过的点 
        return vector<int> (res.rbegin(),res.rend());//倒叙返回答案 
    }
};
