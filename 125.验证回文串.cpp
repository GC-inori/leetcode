class Solution {
public:
    bool isPalindrome(string s) 
    {
        string t;
        for(auto &c:s)
            if(c<='Z'&&c>='A') t.push_back(c-'A'+'a');
            else if(c<='z'&&c>='a'||c<='9'&&c>='0') t.push_back(c);//ת���ַ�����ȥ����Ч�ַ� 
        int i=0,j=t.size()-1;
        while(i<j)
            if(t[i++]!=t[j--]) return 0;//�ж��Ƿ���� 
        return 1;
    }
};
