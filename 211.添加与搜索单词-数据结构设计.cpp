字典树加dfs匹配 
class WordDictionary {
public:
    /** Initialize your data structure here. */
    struct trie
    {
        trie *p[26]={NULL};
        bool f=0;
    };
    trie *h;
    WordDictionary() 
    {
        h=new trie;
    }
    /** Adds a word into the data structure. */
    void addWord(string word) 
    {
        auto t=h;
        for(auto &c:word)
        {
            if(!t->p[c-'a']) t->p[c-'a']=new trie;
            t=t->p[c-'a'];
        }
        t->f=1;
    }
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) 
    {
        return dfs(0,word,h);
    }
    bool dfs(int pos,string &word,trie* cur)
    {
        if(pos==word.size()&&cur->f) return 1;
        if(pos==word.size()) return 0;
        if(word[pos]!='.')
        {
            if(cur->p[word[pos]-'a'])
                return dfs(pos+1,word,cur->p[word[pos]-'a']);
        }
        else
        {
            for(int i=0;i<26;i++)//枚举每一个可能的匹配 
                if(cur->p[i]&&dfs(pos+1,word,cur->p[i])) return 1;
        }
        return 0;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
