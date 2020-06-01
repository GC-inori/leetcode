class Solution 
{
//用两个指针i,j.表示从j开始的无重复字符字串[j,i].
//当i向后移动时,若发现重复,说明从j开始的最长无重复字符串为[j,i-1];
//此时，向后移动j，若s[j]!=s[i]说明[j+1,i]中有重复字符，一直移动直到s[k]==s[i],此时[k+1,i]中无重复字符
//而任意t属于[j+1,k],[t,i]中有重复字符，且从t开始的最从字符小于从j开始的。
public:
    int lengthOfLongestSubstring(string s) 
    {
        bool flag[300]; //只需要保存是否在[j,i]中用一个bool数组即可 
        memset(flag,0,sizeof(flag));
        int res=0;
        for(int i=0,j=0,n=s.size();i<n;i++)
        {
            if(!flag[s[i]])
            {
                flag[s[i]]=1;
                res=max(res,i-j+1);
            }
            else
            {
                while(s[j]!=s[i])
                {
                    flag[s[j]]=0; //从j+1开始的无重复字符串一定小于从j开始的 
                    j++;
                }
                j++;
            }
        }
        return res;
    }
};

