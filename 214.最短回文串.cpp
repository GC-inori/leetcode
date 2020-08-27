设s=ss+t 其中 ss为回文串
则目标为 ~t+ss+t ~t表示t的翻转字符串
要求~t最小 则ss最大 即要求ss最长回文前缀
设p=ss+t+" "+~t+~ss;
由于ss为回文串则ss=~ss；
即求p中最长前缀和后缀相等的长度
kmp算法 
class Solution {
public:
    string shortestPalindrome(string s) 
    {
        string t=s;
        s=s+' '+string(s.rbegin(),s.rend())+'&';
        const int n=s.size();
        int Next[n];
        int k=Next[0]=-1,i=0;
        while(i<n)
        {
            while(~k&&s[i]!=s[k]) k=Next[k];
            i++,k++;
            if(i>=n) break;
            Next[i]=k;
        }
        s=t.substr(Next[n-1]);
        return string(s.rbegin(),s.rend())+t;
    }
};
