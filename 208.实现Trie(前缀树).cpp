class Trie {
public:
    /** Initialize your data structure here. */
    struct trie
    {
        trie* p[26]={NULL};
        bool f=0;
    };
    trie *h;
    Trie() 
    {
        h=new trie;
    }
    /** Inserts a word into the trie. */
    void insert(string word) 
    {
        auto t=h;
        for(auto &c:word)
        {
            if(t->p[c-'a']) t=t->p[c-'a'];
            else t->p[c-'a']=new trie,t=t->p[c-'a'];
        }
        t->f=1;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) 
    {
        trie *t=h;
        for(auto &c:word)
        {
            if(t->p[c-'a']) t=t->p[c-'a'];
            else return 0;
        }
        return t->f;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) 
    {
        trie *t=h;
        for(auto &c:prefix)
        {
            if(t->p[c-'a']) t=t->p[c-'a'];
            else return 0;
        }
        return 1;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
