����б�ʿ���long double���� ����Ҫ���߾��� ���Ա������ gcd 
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) 
    {
        typedef long double LD;
        int res=0;
        for(auto &p:points)//ö�ٵ�һ���� 
        {
            int ss=0,vs=0;//ss��ʾ��p�غϵĵ����Ŀ��vs��p��ֱ�ĵ����Ŀ 
            unordered_map<LD,int> hash;
            for(auto &q:points)//ö�ٵڶ����� 
                if(p==q) ss++;
                else if(p[0]==q[0]) vs++;
                else
                    hash[(LD)(p[1]-q[1])/(p[0]-q[0])]++;//����б�ʣ�б����ͬ������ 
            res=max(res,ss+vs);
            for(auto &t:hash) res=max(res,t.second+ss);
        }
        return res;
    }
};
