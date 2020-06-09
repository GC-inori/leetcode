暴力枚举相等的前缀长度即可
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        if(strs.empty()||strs[0].empty()) return "";
        int len=-1;
        bool flag=1;
        while(flag)
        {
            len++;
            for(int i=0,n=strs.size();i<n;i++)
            {
                if(len>=strs[i].size()||(i&&strs[i][len]!=strs[i-1][len]))
                {
                    flag=0;
                    break;
                }
            }
        }

        return strs[0].substr(0,len);
    }
};

