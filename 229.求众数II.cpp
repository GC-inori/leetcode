在任何数组中，出现次数大于该数组长度1/3的值最多只有两个
摩尔投票法其实就是抵消法，假设一个数的数量大于总数的1/3，且这个数需要用两个不同的数才能抵消。则抵消到最后这个数一定还存在
两个变量r1,r2作为仓库，c1,c2是仓库的计数。有两种抵消的情况
1.r1,r2有值，且x与r1,r2不同
2.x在某个仓库里，且新来的数与x和另外一个仓库里的数都不相同
如果仓库非空且新值与仓库中的值同类，则增加计数，如果仓库为空，则新添加元素进仓库；如果仓库非空，且新值与仓库里的值不同类，则开始抵消，只需要一趟遍历即可
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) 
    {
        int r1,r2,c1=0,c2=0;
        for(auto &c:nums)
        {
            if(c1&&c==r1) c1++;
            else if(c2&&r2==c) c2++;
            else if(!c1) r1=c,c1++;
            else if(!c2) r2=c,c2++;
            else c1--,c2--;
        }
        c1=c2=0;
        for(auto &c:nums)//判断可能解是否是答案 
            if(c==r1) c1++;
            else if(c==r2) c2++;
        vector<int> res;
        if(nums.size()/3<c1) res.push_back(r1);
        if(nums.size()/3<c2) res.push_back(r2);
        return res;
    }
};
