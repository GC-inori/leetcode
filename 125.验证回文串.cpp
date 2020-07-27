class Solution {
public:
    bool isPalindrome(string s) 
    {
        string t;
        for(auto &c:s)
            if(c<='Z'&&c>='A') t.push_back(c-'A'+'a');
            else if(c<='z'&&c>='a'||c<='9'&&c>='0') t.push_back(c);//转化字符串，去掉无效字符 
        int i=0,j=t.size()-1;
        while(i<j)
            if(t[i++]!=t[j--]) return 0;//判断是否回文 
        return 1;
    }
};
