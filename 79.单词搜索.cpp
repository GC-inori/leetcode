先枚举单词的起点，然后依次枚举单词的每个字母。
过程中需要将已经使用过的字母改成一个特殊字母，以避免重复使用字符。
class Solution {
public:
    int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0},m,n;
    bool dfs(int x,int y,string &word,int pos,vector<vector<char>>& board)//pos目前已经有匹配到word[pos] x,y当前点坐标 
    {
        if(pos==word.size()-1) return 1;
        board[x][y]='*'; //避免重复使用 
        for(int i=0,xx,yy;i<4;i++)
        {
            xx=x+dx[i];
            yy=y+dy[i];//下一点坐标 
            if(xx>=0&&xx<m&&yy>=0&&yy<n&&board[xx][yy]==word[pos+1]&&dfs(xx,yy,word,pos+1,board))//如果找到解返回1 
                return 1;
        }
        board[x][y]=word[pos]; //恢复现场 
        return 0;
    }
    bool exist(vector<vector<char>>& board, string word) 
    {
        m=board.size(),n=board[0].size();
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(board[i][j]==word[0]&&dfs(i,j,word,0,board))//寻找起点 
                    return 1;
        return 0;
    }
};
