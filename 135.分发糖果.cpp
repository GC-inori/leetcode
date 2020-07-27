用l[i] r[i]分别表示按左边第i个小朋友最少发几个糖果 和按右边最少发几个糖果
l[i]=i左侧连续递减的小朋友数量+1 
最终给其最少分max(l[i],r[i])割 
class Solution {
public:
    int candy(vector<int>& ratings) 
    {
        int n=ratings.size(),res=0;
        vector<int> l(ratings.size(),1),r=l;
        for(int i=1;i<n;i++)
            if(ratings[i]>ratings[i-1]) l[i]=l[i-1]+1;
        for(int i=n-2;~i;i--)
            if(ratings[i]>ratings[i+1]) r[i]=r[i+1]+1;
        for(int i=0;i<n;i++)
            res+=max(l[i],r[i]);
        return res;
    }
};
