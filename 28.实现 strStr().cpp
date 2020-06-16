kmpÀ„∑® 
class Solution {
public:
    int strStr(string haystack, string needle) 
    {
        if(needle.empty()) return 0;
        const int n1=haystack.size(),n2=needle.size();
        int Next[n2],k=-1,i=0,j=0;
        Next[0]=-1;
        while(i<n2)
        {
            while(k>-1&&needle[i]!=needle[k]) k=Next[k];
            k++,i++;
            if(i>=n2) break;
            if(needle[i]==needle[k]) Next[i]=Next[k];
            else Next[i]=k;
        }
        i=0;
        while(i<n1)
        {
            if(j==-1||haystack[i]==needle[j])
            {
                i++,j++;
                if(j==n2) return i-n2;
            }
            else j=Next[j];
        }
        return -1;
    }
};
