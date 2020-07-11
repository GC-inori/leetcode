��ö�ٵ��ʵ���㣬Ȼ������ö�ٵ��ʵ�ÿ����ĸ��
��������Ҫ���Ѿ�ʹ�ù�����ĸ�ĳ�һ��������ĸ���Ա����ظ�ʹ���ַ���
class Solution {
public:
    int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0},m,n;
    bool dfs(int x,int y,string &word,int pos,vector<vector<char>>& board)//posĿǰ�Ѿ���ƥ�䵽word[pos] x,y��ǰ������ 
    {
        if(pos==word.size()-1) return 1;
        board[x][y]='*'; //�����ظ�ʹ�� 
        for(int i=0,xx,yy;i<4;i++)
        {
            xx=x+dx[i];
            yy=y+dy[i];//��һ������ 
            if(xx>=0&&xx<m&&yy>=0&&yy<n&&board[xx][yy]==word[pos+1]&&dfs(xx,yy,word,pos+1,board))//����ҵ��ⷵ��1 
                return 1;
        }
        board[x][y]=word[pos]; //�ָ��ֳ� 
        return 0;
    }
    bool exist(vector<vector<char>>& board, string word) 
    {
        m=board.size(),n=board[0].size();
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(board[i][j]==word[0]&&dfs(i,j,word,0,board))//Ѱ����� 
                    return 1;
        return 0;
    }
};
