class Solution {
public:
    int lengthOfLastWord(string s) 
    {
        while(s.size()&&s.back()==' ') s.pop_back(); //去除结尾空格 
        int res=0;
        for(int i=s.size()-1;~i;i--)
        {
            if(s[i]!=' ') res++; //不为空格计数 
            else return res;  //否则返回 
        }
        return res;    
    }
};
