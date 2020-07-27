class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList)
    { 
        unordered_set<string> S;
        unordered_map<string, int> dist;
        queue<string> q;
        dist[beginWord] = 1;
        q.push(beginWord);
        for (auto word: wordList) S.insert(word);
        while (q.size()) //bfs 
        {
            auto t = q.front();
            q.pop();
            string r = t;
            for (int i = 0; i < t.size(); i ++ ) 
            {
                t = r;
                for (char j = 'a'; j <= 'z'; j ++ )
                    if (r[i] != j) {
                        t[i] = j;
                        if (S.count(t) && dist.count(t) == 0) //判断能变成那些字母 
                        {
                            dist[t] = dist[r] + 1;
                            if (t == endWord) return dist[t];
                            q.push(t);
                        }
                    }
            }
        }
        return 0;
    }
};
