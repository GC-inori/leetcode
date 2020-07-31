本题斜率可用long double保存 如需要更高精度 可以保存分数 gcd 
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) 
    {
        typedef long double LD;
        int res=0;
        for(auto &p:points)//枚举第一个点 
        {
            int ss=0,vs=0;//ss表示和p重合的点的数目，vs和p垂直的点的数目 
            unordered_map<LD,int> hash;
            for(auto &q:points)//枚举第二个点 
                if(p==q) ss++;
                else if(p[0]==q[0]) vs++;
                else
                    hash[(LD)(p[1]-q[1])/(p[0]-q[0])]++;//计算斜率，斜率相同的增加 
            res=max(res,ss+vs);
            for(auto &t:hash) res=max(res,t.second+ss);
        }
        return res;
    }
};
