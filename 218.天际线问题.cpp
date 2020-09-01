记录每个大楼的左端点和右端点以及对应的高度，然后使用一条扫描线从左向右扫描，每次遇到一个大楼的左端点或者右端点，就有可能是关键点。可以得到以下的判别方式。

如果当前扫描到的点是左端点：如果当前左端点p是当前位置上最高的点，那么这一个点是一个关键点(p.left,p.height)。

如果当前扫描到的点是右端点：如果当前右端点p比除了这个右端点之外最高的点q还要高，那么我们形成了一个关键点，这个关键点的坐标就是(p.right,q.height)。

接下来考虑如何能够高效的实现支持单点更新的区间最大值，使用一个multiset就可以了，这里使用multiset而不是set是因为多个建筑物可以共享同一个高度。
如果遇到左端点，就把这个楼的高度加入multiset；如果遇到右端点，就把这个楼的高度从multiset中移除。

如果同一个横坐标有两个左顶点，我们记做p1.height > p2.height那么高度较高的那个左顶点才是真正的关键点，根据关键点判别思路，应该先遍历高度较高的那个p1。

如果同一个横坐标有两个右顶点，我们记做p1.height > p2.height，根据关键点判别思路如果先将高度较高的那个移除，就会生成一个(p1.right,p2.height)的错误关键点。所以应该先移除高度较小的右端点p2。

如果同一个横坐标有一个左端点p1和一个右端点p2，如果先遍历右端点再遍历左端点，可能会得到一个错误的关键点。
综上所述，对顶点进行排序，应该是按照横坐标从小到大，横坐标相同时，如果都是左端点，先那么遍历较高的那个，如果是右端点，先遍历较矮的那个，如果一个左端点一个右端点，先遍历左端点。
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) 
    {
        vector<pair<int,int>> points;
        multiset<int> ms;
        ms.insert(0);
        for(auto &c:buildings)
        {
            points.push_back({c[0],-c[2]});//左端点高的排在前面 
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
