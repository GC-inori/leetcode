字典树加dfs
基本思想是暴力搜索出所有单词路径，再判断该路径表示的单词是否出现在单词列表中。枚举所有路径时先枚举起点，再枚举路径延伸的方向。
但朴素DFS搜索空间太大，直接搜会超时。所以我们需要剪枝。
先将所有单词存入Trie树中，这样我们在搜索时，如果发现当前单词前缀不在trie中，那么当前的路径一定不会构成任意一个单词，我们直接return。
class Solution {
public:
    struct trie
    {
        int id=-1;//id等于-1表示不是单词结尾 否则表示当前到了第id个单词的结尾 
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
        if(~t->id) us.insert(t->id);//防止出现重复答案所以用set 
        auto tmp=board[x][y];
        board[x][y]=0;//防止走重复的点 
        for(int i=0,xx,yy;i<4;i++)
        {
            xx=x+dx[i],yy=dy[i]+y;
            if(~xx&&~yy&&xx<m&&yy<n&&board[xx][yy]&&t->p[board[xx][yy]-'a']) dfs(xx,yy,t->p[board[xx][yy]-'a'],board);
        }
        board[x][y]=tmp;//恢复现场 
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) 
    {
        m=board.size(),n=board[0].size();
        r=new trie;
        for(int i=0,n=words.size();i<n;i++)
            insert(i,words[i]);
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(r->p[board[i][j]-'a']) dfs(i,j,r->p[board[i][j]-'a'],board);//枚举每一个起点 
        vector<string> res;
        for(auto &c:us)
            res.push_back(words[c]);
        return res;
    }
};
