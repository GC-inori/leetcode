class Solution {
public:
    bool isIsomorphic(string s, string t) 
    {
        int hash[500]={0},f[500]={0};//hash数组表示映射的目标 f表示是否映射过 
        for(int i=0;i<s.size();i++)
        {
            if(hash[s[i]]==t[i]) continue;
            if(!hash[s[i]]&&!f[t[i]]) hash[s[i]]=t[i],f[t[i]]=1;
            else return 0;
        }
        return 1;
    }
};
