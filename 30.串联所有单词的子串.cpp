滑动窗口。因为每个单词中的长度相同，那么我们可以根据每次枚举的起始位置将其划分为len组不同的匹配。
样例 
len = 3,s = abcdefghijkl
划分1: abc def ghi jkl
划分2: bcd efg hij
划分3: cde fgh ijk

首先枚举所有的划分起点位置，然后j-words[0].size()*(words.size()-1),j分别代表当前窗口的左右指针，cur_hash记录当前窗口内每个单词出现的次数，cnt记录words中和窗口中重复单词的数量，每次读入一个单词：
如果当前单词没有出现过，说明失配了，那么将j指针后移，重新匹配。
如果出现过，更新cur_hash：
如果当前单词出现个数小于等于我们需要的单词个数，那么说明找到了一个新的可满足的单词，更新cnt。
如果当前单词单词出现个数大于我们需要的单词个数，那么该单词没用不用更新cnt 
如果cnt==words.size() 说明找到了答案记录 

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) 
    {
        vector<int> res;
        if(s.empty()||words.empty()||words[0].empty()) return res;
        unordered_map<string,int> hash;
        for(auto &c:words) hash[c]++;  //记录words中每个单词的个数 
        for(int i=0,n1=words[0].size(),n2=s.size(),n3=words.size();i<n1;i++)
        {
            unordered_map<string,int> cur_hash;
            for(int j=i,cnt=0;j+n1-1<n2;j+=n1)
            {
                if((j-i)/n1>=n3)
                {
                    string tmp=s.substr(j-n3*n1,n1);
                    cur_hash[tmp]--;
                    if(hash.count(tmp)&&hash[tmp]>cur_hash[tmp]) cnt--; //如果这次出窗口的单词有用则匹配单词个数减一 
                }
                string tmp=s.substr(j,n1);
                cur_hash[tmp]++;
                if(hash.count(tmp)&&hash[tmp]>=cur_hash[tmp]) cnt++;//如果这次进窗口的单词有用则匹配单词个数加一 
                if(cnt==n3) res.push_back(j-(n3-1)*n1);
            }
        }
        return res;
    }
};
