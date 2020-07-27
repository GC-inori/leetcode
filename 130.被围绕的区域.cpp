���������⣬��ͳ�Ƴ���Щ���򲻻ᱻ��ռ��Ȼ���������򶼱��'X'���ɡ�
�����������£�
��һ����ά�������飬��¼��Щ���򱻱�������
ö�����б߽��ϵ�'O'���Ӹ�λ����Flood Fill������������ȱ�����ֻ������'O'��λ�ã��������б�������λ�ö���ǳ�true����ֻ�кͱ߽��ϵ�'O'�����ĵ��û�б���Χ�� 
������δ��������λ�ñ��'X'��
class Solution {
public:
    int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
    void dfs(int x,int y,vector<vector<char>>& board,vector<vector<bool>> &f)
    {
        if(board[x][y]=='X'||f[x][y]) return;
        int m=board.size(),n=board[0].size();
        f[x][y]=1;
        for(int i=0,xx,yy;i<4;i++)
        {
            xx=x+dx[i],yy=y+dy[i];
            if(xx>=0&&yy>=0&&xx<m&&yy<n&&!f[xx][yy])
                dfs(xx,yy,board,f);
        }
    }
    void solve(vector<vector<char>>& board) 
    {
        if(board.empty()||board[0].empty()) return;
        const int m=board.size(),n=board[0].size();
        vector<vector<bool>> f(m,vector<bool>(n,0));
        for(int i=0;i<n;i++) dfs(0,i,board,f);//�����ĸ��߽��ϵĵ� 
        for(int i=0;i<n;i++) dfs(m-1,i,board,f);
        for(int i=1;i<m-1;i++) dfs(i,0,board,f);
        for(int i=1;i<m-1;i++) dfs(i,n-1,board,f);
        for(int i=1;i<m-1;i++)
            for(int j=1;j<n-1;j++)
                if(board[i][j]=='O'&&!f[i][j]) board[i][j]='X';
    }
};
