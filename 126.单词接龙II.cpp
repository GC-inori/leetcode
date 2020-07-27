//���·��Ѱ��·�� 
class Solution {
public:
    vector<vector<string>> res;
    vector<string> tmp;
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList)     {
        wordList.push_back(beginWord);
        swap(wordList[0],wordList[wordList.size()-1]);
        for(int i=1,n=wordList.size();i<n;i++)
        {
            if(wordList[i]==endWord)
            {
                swap(wordList[i],wordList[wordList.size()-1]);
                break;
            }
        }//�ҵ������յ�ֱ����0��n-1�� 
        if(wordList.back()!=endWord) return res;
        const int n=wordList.size(),m=wordList[0].size();
        vector<int> e[n],dis(n,0x3f3f3f3f);
        for(int i=0,cnt;i<n;i++)
            for(int j=i+1;j<n;j++)
            {
                cnt=0;
                for(int k=0;k<m;k++)
                {
                    if(wordList[i][k]!=wordList[j][k]) cnt++;
                    if(cnt>2) break;
                }
                if(cnt<2) e[i].push_back(j),e[j].push_back(i);//�����߱� 
            }
        bool f=1;
        dis[0]=0;
        queue<int> q;
        q.push(0);
        while(q.size()&&f)//bfs�����·���� 
        {
            int t=q.front();
            q.pop();
            for(auto c:e[t])
            {
                if(dis[c]>dis[t]+1) dis[c]=dis[t]+1,q.push(c);
                if(c==n-1) 
                {
                    f=0;
                    break;
                }
            }
        }
        dfs(wordList,n-1,e,dis);
        return res;
    }
    void dfs(vector<string>& wordList,int cur,vector<int> *e,vector<int> &dis)//dfs�����· 
    {
        tmp.push_back(wordList[cur]);
        if(cur==0)
        {
            reverse(tmp.begin(),tmp.end());
            res.push_back(tmp);
            reverse(tmp.begin(),tmp.end());
            return;
        }
        for(auto c:e[cur])
            if(dis[c]+1==dis[cur])//�жϸõ��Ƿ������·�� 
            {
                dfs(wordList,c,e,dis);
                tmp.pop_back();
            }
    }
};
