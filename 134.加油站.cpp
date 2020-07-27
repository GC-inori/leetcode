首先破环成链 用need[i]表示i%n站点所需要的汽油 负数表示缺油 正数表示有结余
原题意思即可转化为在need上找一段长度为n的序列 使得need[k]>=0 need[k]+need[k+1]>=0 ...   need[k]+need[k+1]+...+need[k+n-1]>=0 
第二步.双指针 或者单调队列前缀和都可以 此处用双指针 
定义两个指针 start 和 end，分别表示当前假设的起点，和在这个起点下能走到的终点，tot 为当前油量。
如果发现 tot < 0，即不能走到 end 时，需要不断往后移动 start，使得 tot 能满足要求。注意到，向后移动 start 并不会使得 [start, end] 之间出现油量为负的情况。
如果 end - start + 1 == n，即找到了一个环形路线。
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
    {
        const int n=gas.size();
        for(int i=0;i<n;i++)
            gas[i]-=cost[i];
        vector<int> need;
        for(auto &c:gas) need.push_back(c);
        for(auto &c:gas) need.push_back(c);
        int start=0,end=0,tot=0;
        while(start<n&&end<n+n)
        {
            tot+=need[end];
            while(tot<0)
            {
                tot-=need[start];
                start++;
            }
            if(end-start+1==n) return start;
            end++;
        }
        return -1;
    }
};
