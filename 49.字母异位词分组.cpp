�����string ӳ�䵽 vector<string>�Ĺ�ϣ��unordered_map<string, vector<string>> 
��ÿ���ַ����������ַ���С�������򣬽��ź�����ַ�����Ϊkey��Ȼ��ԭ�ַ�������key��Ӧ��vector<string>�С�
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
