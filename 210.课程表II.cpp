����dfs���������� 
class Solution {
public:
    vector<int> res;
    bool dfs(int cur,vector<vector<int>> &e,vector<int> &f)
    {
        f[cur]=1;//1��ʾ���������� 
        for(auto &c:e[cur])
            if(f[c]==1||(!f[c]&&!dfs(c,e,f))) return 0;//������������������ĵ㣬���ӽڵ���ڻ� ����0 
        res.push_back(cur);
        f[cur]=2;//2��ʾ������� 
        return 1;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<vector<int>> e(numCourses);
        for(auto &c:prerequisites)
            e[c[1]].push_back(c[0]);
        vector<int> f(numCourses,0);
        for(int i=0;i<numCourses;i++)
            if(!f[i]&&!dfs(i,e,f))  return {};//dfsÿ��δ�������ĵ� 
        return vector<int> (res.rbegin(),res.rend());//���𷵻ش� 
    }
};
