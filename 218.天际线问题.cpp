��¼ÿ����¥����˵���Ҷ˵��Լ���Ӧ�ĸ߶ȣ�Ȼ��ʹ��һ��ɨ���ߴ�������ɨ�裬ÿ������һ����¥����˵�����Ҷ˵㣬���п����ǹؼ��㡣���Եõ����µ��б�ʽ��

�����ǰɨ�赽�ĵ�����˵㣺�����ǰ��˵�p�ǵ�ǰλ������ߵĵ㣬��ô��һ������һ���ؼ���(p.left,p.height)��

�����ǰɨ�赽�ĵ����Ҷ˵㣺�����ǰ�Ҷ˵�p�ȳ�������Ҷ˵�֮����ߵĵ�q��Ҫ�ߣ���ô�����γ���һ���ؼ��㣬����ؼ�����������(p.right,q.height)��

��������������ܹ���Ч��ʵ��֧�ֵ�����µ��������ֵ��ʹ��һ��multiset�Ϳ����ˣ�����ʹ��multiset������set����Ϊ�����������Թ���ͬһ���߶ȡ�
���������˵㣬�Ͱ����¥�ĸ߶ȼ���multiset����������Ҷ˵㣬�Ͱ����¥�ĸ߶ȴ�multiset���Ƴ���

���ͬһ���������������󶥵㣬���Ǽ���p1.height > p2.height��ô�߶Ƚϸߵ��Ǹ��󶥵���������Ĺؼ��㣬���ݹؼ����б�˼·��Ӧ���ȱ����߶Ƚϸߵ��Ǹ�p1��

���ͬһ���������������Ҷ��㣬���Ǽ���p1.height > p2.height�����ݹؼ����б�˼·����Ƚ��߶Ƚϸߵ��Ǹ��Ƴ����ͻ�����һ��(p1.right,p2.height)�Ĵ���ؼ��㡣����Ӧ�����Ƴ��߶Ƚ�С���Ҷ˵�p2��

���ͬһ����������һ����˵�p1��һ���Ҷ˵�p2������ȱ����Ҷ˵��ٱ�����˵㣬���ܻ�õ�һ������Ĺؼ��㡣
�����������Զ����������Ӧ���ǰ��պ������С���󣬺�������ͬʱ�����������˵㣬����ô�����ϸߵ��Ǹ���������Ҷ˵㣬�ȱ����ϰ����Ǹ������һ����˵�һ���Ҷ˵㣬�ȱ�����˵㡣
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) 
    {
        vector<pair<int,int>> points;
        multiset<int> ms;
        ms.insert(0);
        for(auto &c:buildings)
        {
            points.push_back({c[0],-c[2]});//��˵�ߵ�����ǰ�� 
            points.push_back({c[1],c[2]});
        }
        sort(points.begin(),points.end());
        vector<vector<int>> res;
        for(auto &c:points)
        {
            if(c.second<0)
            {
                if(-c.second>*ms.rbegin()) res.push_back({c.first,-c.second});
                ms.insert(-c.second);
            }
            else
            {
                ms.erase(ms.find(c.second));
                if(c.second>*ms.rbegin()) res.push_back({c.first,*ms.rbegin()});
            }
        }
        return res;
    }
};
