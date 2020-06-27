先将所有区间按起点排序
从第一个区间开始记录起点和终点
对于之后的区间 如果起点在之前记录的起点和终点之间 更新当前终点
如果不在 保存记录的起点和终点，之后的区间都不能和其合并 然后用此区间更新起点和终点 
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        vector<vector<int>> res;
        sort(intervals.begin(),intervals.end());
        intervals.push_back({INT_MAX,INT_MAX});
        int st=intervals[0][0],ed=intervals[0][1];
        for(int i=1,n=intervals.size();i<n;i++)
        {
            if(intervals[i][0]<=ed)
                ed=max(ed,intervals[i][1]);
            else
            {
                res.push_back({st,ed});
                st=intervals[i][0];
                ed=intervals[i][1];
            }
        }
        return res;
    }
};
