模拟 
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        if(matrix.empty()||matrix[0].empty()) return {};
        const int m=matrix.size(),n=matrix[0].size(),dx[4]={0,1,0,-1},dy[4]={1,0,-1,0}; //方向数组 
        bool vis[m][n],f=1;
        memset(vis,0,sizeof(vis));
        int x=0,y=-1,to=0; //初始化 第一步先向右移动 
        vector<int> res;
        while(f)
        {
            f=0;
            while(x+dx[to]>=0&&x+dx[to]<m&&y+dy[to]>=0&&y+dy[to]<n&&!vis[x+dx[to]][y+dy[to]]) //如果不越界沿着该方向一直移动 
            {
                x+=dx[to];
                y+=dy[to];
                vis[x][y]=1;
                res.push_back(matrix[x][y]);
                f=1;  //如果能移动说明未遍历完，否则说明已经遍历完 
            }
            to=(to+1)%4; //改变方向 
        }
        return res;
    }
};
