两次翻转 先将每个单词翻转 再将整个字符串翻转 
class Solution {
public:
    string reverseWords(string s) 
    {
        while(s.size()&&s.back()==' ') s.pop_back();//去除末尾空格 
        if(s.empty()) return s;
        int k=0;
        for(int i=0,n=s.size(),t;i<n;i++)
        {
            if(s[i]==' ') continue;//找到单词开始位置 
            t=k;
            while(i<n&&s[i]!=' ') s[k++]=s[i++];//找到结束位置 
            reverse(s.begin()+t,s.begin()+k);//翻转 
            if(i<n) s[k++]=' ';//在非结尾单词后添加空格 
        }
        s.erase(s.begin()+k,s.end());
        reverse(s.begin(),s.end());
        return s;
    }
};
