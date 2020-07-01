首先用哈希表统计出 TT 中所有字符出现的次数
然后用两个指针 l,r(r>+l)来扫描整个字符串，同时用一个哈希表统计l-r之间每种字符出现的次数，每次遍历需要的操作如下：
加入 s[r]，同时更新哈希表；
检查 s[l] 是否多余，如果是，则移除 s[j]s[j]；
检查当前窗口是否已经满足 T 中所有字符，如果是，则更新答案；
class Solution {
public:
    string minWindow(string s, string t) 
    {
        unordered_map<char,int> hash;
        int cnt=0,mn=1e9,x;
        for(auto &c:t)
        {
            if(!hash.count(c)) cnt++;
            hash[c]++;
        }
        for(int l=0,r=0,n=s.size(),cur_cnt=0;r<n;r++)
        {
            if(hash[s[r]]==1) cur_cnt++; 
            hash[s[r]]--; //加入s[r]，如果s[r]==1说明加入s[r]之后有个字符满足条件来 cnt++  
            while(hash[s[l]]<0) hash[s[l++]]++;//无用的出队 
            if(cnt==cur_cnt&&r-l+1<mn) //更新答案 
            {
                mn=r-l+1;
                x=l;
            }
               
        }
        return mn==1e9?"":s.substr(x,mn);  
    }
};
