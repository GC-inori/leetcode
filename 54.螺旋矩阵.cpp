ģ�� 
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        if(matrix.empty()||matrix[0].empty()) return {};
        const int m=matrix.size(),n=matrix[0].size(),dx[4]={0,1,0,-1},dy[4]={1,0,-1,0}; //�������� 
        bool vis[m][n],f=1;
        memset(vis,0,sizeof(vis));
        int x=0,y=-1,to=0; //��ʼ�� ��һ���������ƶ� 
        vector<int> res;
        while(f)
        {
            f=0;
            while(x+dx[to]>=0&&x+dx[to]<m&&y+dy[to]>=0&&y+dy[to]<n&&!vis[x+dx[to]][y+dy[to]]) //�����Խ�����Ÿ÷���һֱ�ƶ� 
            {
                x+=dx[to];
                y+=dy[to];
                vis[x][y]=1;
                res.push_back(matrix[x][y]);
                f=1;  //������ƶ�˵��δ�����꣬����˵���Ѿ������� 
            }
            to=(to+1)%4; //�ı䷽�� 
        }
        return res;
    }
};
