�Ƚ��������䰴�������
�ӵ�һ�����俪ʼ��¼�����յ�
����֮������� ��������֮ǰ��¼�������յ�֮�� ���µ�ǰ�յ�
������� �����¼�������յ㣬֮������䶼���ܺ���ϲ� Ȼ���ô�������������յ� 
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
