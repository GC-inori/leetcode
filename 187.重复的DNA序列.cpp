字符串hash 
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) 
    {
        if(s.size()<=10) return {};//如果小于等于10 不存在重复 
        vector<string> res;
        unsigned long long p=1,hash=0;
        unordered_map<unsigned long long,int> m;// unsigned long long记录哈希值 int 记录出现次数 
        for(int i=0;i<10;i++)
        {
            hash=hash*131+s[i];
            if(i<9) p*=131;
        }
        m[hash]=1;//处理第一个 
        for(int i=10,n=s.size();i<n;i++)
        {
            hash=(hash-s[i-10]*p)*131+s[i];//由前一个的哈希值算后一个 
            m[hash]++;
            if(m[hash]==2)
                res.push_back(s.substr(i-9,10));
        }
        return res;
    }
};
