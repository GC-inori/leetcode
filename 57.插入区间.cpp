������������ߺ��ұߵġ���������û���ص������䣬ֱ�ӽ����ǰ�˳����룻
�������������ཻ�����䣬ά���ϲ����������˵���Ҷ˵㣬����ٽ��ϲ������������ʵ���λ�á�
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
    {
        vector<vector<int>> res;
        bool _insert=0;  //�Ƿ�������� 
        for(auto &c:intervals)
        {
            if(c[0]>newInterval[1])  //���Ҫ����������ڵ�ǰ������� 
            {
                if(!_insert) //û�в�������������� 
                {
                    res.push_back(newInterval);
                    _insert=1;
                }
                res.push_back(c);  //���뵱ǰ���� 
            }
            else if(c[1]<newInterval[0]) // ���Ҫ����������ڵ�ǰ�����ұߣ�ֱ�Ӳ��뵱ǰ���伴�� 
                res.push_back(c);
            else  //����н��� �ϲ����� 
            {
                newInterval[0]=min(c[0],newInterval[0]);
                newInterval[1]=max(c[1],newInterval[1]);
            }
        }
        if(!_insert) res.push_back(newInterval);//�������������������ұ� 
        return res;    
    }
};
