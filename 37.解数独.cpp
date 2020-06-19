������⼴�� 
class Solution {
public:
    int row[9],col[9],squ[9],flag=0;
    bool dfs(vector<vector<char>>& board,int x,int y)
    {
        if(y==9) x++,y=0; //���� 
        if(x==9) return 1;  //��8���Ѿ����� ˵�����ִ� ���� 
        if(board[x][y]=='.')  //���Ϊ. ����ʹ��1-9ÿ������ȥ�� 
            for(int k=1;k<10;k++)
            {
                if(row[x]&(1<<k)||col[y]&(1<<k)||squ[x/3*3+y/3]&(1<<k)) continue;
                board[x][y]=k+'0';
                row[x]|=1<<k;
                col[y]|=1<<k;
                squ[x/3*3+y/3]|=1<<k;
                if(dfs(board,x,y+1)) return 1;
                row[x]-=1<<k;  //�ظ��ֳ� 
                col[y]-=1<<k;
                squ[x/3*3+y/3]-=1<<k;
                board[x][y]='.';
            }
        else return dfs(board,x,y+1); //��Ϊ. ������һ������ 
        return 0; //Ŀǰ������1-9������ ����0 
    }
    void solveSudoku(vector<vector<char>>& board) 
    {
        for(int i=0;i<9;i++) row[i]=col[i]=squ[i]=0;
        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++)
                if(board[i][j]!='.')
                {
                    int t=board[i][j]-'0';
                    row[i]+=1<<t;     //Ԥ����ÿ�� ÿ�� ÿ��С���� ����Щ���� 
                    col[j]+=1<<t;
                    squ[i/3*3+j/3]+=1<<t;
                }
        dfs(board,0,0);  //��0��0 ��ʼ���б���ÿ������   
    }
};
