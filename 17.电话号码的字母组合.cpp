直接模拟即可 
class Solution 
{
public:
    vector<char> hash[10]={{},{},{'a','b','c'},{'d','e','f'},{'g','h','i'},
    {'j','k','l'},{'m','n','o'},{'p','q','r','s'},{'t','u','v'},{'w','x','y','z'}};  //预处理每个数字对应哪些字母 
    void dfs(string &digits,int pos,string cur,vector<string> &res)  //pos当前处理到的数字位数  cur当前拼接的字符串 
    {
        if(pos>=digits.size()) 
        {
            res.push_back(cur);
            return;
        }
        for(auto c:hash[digits[pos]-'0']) //遍历每种可能的结果 
            dfs(digits,1+pos,cur+c,res);
    }
    vector<string> letterCombinations(string digits) 
    {
        vector<string> res;
        if(digits.empty()) return res;
        dfs(digits,0,"",res);
        return res;
    }
};
