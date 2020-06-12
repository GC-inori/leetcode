ֱ��ģ�⼴�� 
class Solution 
{
public:
    vector<char> hash[10]={{},{},{'a','b','c'},{'d','e','f'},{'g','h','i'},
    {'j','k','l'},{'m','n','o'},{'p','q','r','s'},{'t','u','v'},{'w','x','y','z'}};  //Ԥ����ÿ�����ֶ�Ӧ��Щ��ĸ 
    void dfs(string &digits,int pos,string cur,vector<string> &res)  //pos��ǰ����������λ��  cur��ǰƴ�ӵ��ַ��� 
    {
        if(pos>=digits.size()) 
        {
            res.push_back(cur);
            return;
        }
        for(auto c:hash[digits[pos]-'0']) //����ÿ�ֿ��ܵĽ�� 
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
