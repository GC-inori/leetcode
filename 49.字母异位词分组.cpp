定义从string 映射到 vector<string>的哈希表：unordered_map<string, vector<string>> 
将每个字符串的所有字符从小到大排序，将排好序的字符串作为key，然后将原字符串插入key对应的vector<string>中。
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        unordered_map<string,vector<string>> hash;
        for(auto &v:strs)
        {
            string tmp=v;
            sort(tmp.begin(),tmp.end());
            hash[tmp].push_back(v);
        }
        vector<vector<string>> res;
        for(auto t:hash)
            res.push_back(t.second);
        return res;    
    }
};
