拓扑排序 
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<vector<int>> e(numCourses);//边数组 
        vector<int> degree(numCourses,0);//统计出入度 
        int cnt=0;
        for(auto &c:prerequisites)
        {
            e[c[1]].push_back(c[0]);
            degree[c[0]]++;
        }
        queue<int> q;
        for(int i=0,n=numCourses;i<n;i++)
            if(!degree[i]) q.push(i);
        while(q.size())
        {
            if(cnt+q.size()==numCourses) return 1;
            auto t=q.front();
            q.pop();
            cnt++;
            for(auto &c:e[t])
                if(--degree[c]==0) q.push(c);
        }
        return 0;
    }
};
