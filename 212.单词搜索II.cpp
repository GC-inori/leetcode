�ֵ�����dfs
����˼���Ǳ������������е���·�������жϸ�·����ʾ�ĵ����Ƿ�����ڵ����б��С�ö������·��ʱ��ö����㣬��ö��·������ķ���
������DFS�����ռ�̫��ֱ���ѻᳬʱ������������Ҫ��֦��
�Ƚ����е��ʴ���Trie���У���������������ʱ��������ֵ�ǰ����ǰ׺����trie�У���ô��ǰ��·��һ�����ṹ������һ�����ʣ�����ֱ��return��
class Solution {
public:
    struct trie
    {
        int id=-1;//id����-1��ʾ���ǵ��ʽ�β �����ʾ��ǰ���˵�id�����ʵĽ�β 
        trie *p[26]={NULL};
    };
    trie *r;
    unordered_set<int> us;
    int m,n,dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
    void insert(int id,string &s)
    {
        auto t=r;
        for(auto &c:s)
        {
            if(!t->p[c-'a']) t->p[c-'a']=new trie;
            t=t->p[c-'a'];
        }
        t->id=id;
    }
    void dfs(int x,int y,trie *t,vector<vector<char>>& board)
    {
        if(~t->id) us.insert(t->id);//��ֹ�����ظ���������set 
        auto tmp=board[x][y];
        board[x][y]=0;//��ֹ���ظ��ĵ� 
        for(int i=0,xx,yy;i<4;i++)
        {
            xx=x+dx[i],yy=dy[i]+y;
            if(~xx&&~yy&&xx<m&&yy<n&&board[xx][yy]&&t->p[board[xx][yy]-'a']) dfs(xx,yy,t->p[board[xx][yy]-'a'],board);
        }
        board[x][y]=tmp;//�ָ��ֳ� 
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) 
    {
        m=board.size(),n=board[0].size();
        r=new trie;
        for(int i=0,n=words.size();i<n;i++)
            insert(i,words[i]);
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(r->p[board[i][j]-'a']) dfs(i,j,r->p[board[i][j]-'a'],board);//ö��ÿһ����� 
        vector<string> res;
        for(auto &c:us)
            res.push_back(words[c]);
        return res;
    }
};
