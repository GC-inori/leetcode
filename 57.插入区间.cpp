对于新区间左边和右边的、与新区间没有重叠的区间，直接将它们按顺序插入；
对于与新区间相交的区间，维护合并后区间的左端点和右端点，最后再将合并后的区间插入适当的位置。
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
    {
        vector<vector<int>> res;
        bool _insert=0;  //是否插入区间 
        for(auto &c:intervals)
        {
            if(c[0]>newInterval[1])  //如果要插入的区间在当前区间左边 
            {
                if(!_insert) //没有插入新区间则插入 
                {
                    res.push_back(newInterval);
                    _insert=1;
                }
                res.push_back(c);  //插入当前区间 
            }
            else if(c[1]<newInterval[0]) // 如果要插入的区间在当前区间右边，直接插入当前区间即可 
                res.push_back(c);
            else  //如果有交叉 合并区间 
            {
                newInterval[0]=min(c[0],newInterval[0]);
                newInterval[1]=max(c[1],newInterval[1]);
            }
        }
        if(!_insert) res.push_back(newInterval);//新区间比在所有区间的右边 
        return res;    
    }
};
