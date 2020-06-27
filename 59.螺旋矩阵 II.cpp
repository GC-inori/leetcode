class Solution {
public:
    vector<vector<int>> generateMatrix(int n) 
    {
        const int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0},N=n;
        vector<vector<int>> res(n,vector<int>(n,0));
        int x=0,y=-1,to=0;
        for(int i=1,nn=n*n;i<=nn;)
        {
            if(x+dx[to]>=0&&x+dx[to]<n&&y+dy[to]>=0&&y+dy[to]<n&&!res[x+dx[to]][y+dy[to]])
            {
                x+=dx[to];
                y+=dy[to];
                res[x][y]=i++;  //填的数字加一 
            }
            else
                to=(to+1)%4;  //改变方向 
        }
        return res;
    }
};
