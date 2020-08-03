桶排序
用两个数组Max和Min分别表示对应桶中的最大值和最小值。
要注意的是，相邻元素的最大差值一定是某个非空桶中的最小值与位于其之前的第一个非空桶中的最大值之差。 
具体解释的话，可以这么理解，理想情况下，桶排序中的所有元素呈现出均匀分布，即每一个桶都只有一个元素。
这时候显然题意中的最大差为两桶间差值；
而一旦不是均匀分布，类似从某些桶中抽出了一些元素，放入到了其他桶。这时候，一定会有空桶出现。
而如果两个非空桶之间存在空桶,也就意味着后一个桶中最小的元素比前一个桶中最大的元素还要大一个以上桶的容量，这个差值一定大于桶内相邻元素的差值(桶内元素差值不会超过桶的容量)。 
class Solution {
public:
    int maximumGap(vector<int>& nums) 
    {
        struct Range {
            int min, max;
            bool used;
            Range() : min(INT_MAX), max(INT_MIN), used(false){}
        };
        int n = nums.size();
        int Min = INT_MAX, Max = INT_MIN;
        for (auto x: nums) {
            Min = min(Min, x);
            Max = max(Max, x);
        }//寻找数列中的最值 
        if (n < 2 || Min == Max) return 0;
        vector<Range> r(n - 1);//n-1个桶 
        int len = (Max - Min + n - 2) / (n - 1);
        for (auto x: nums) {
            if (x == Min) continue;
            int k = (x - Min - 1) / len;
            r[k].used = true;
            r[k].min = min(r[k].min, x);//计算每个桶内的最大最小值 
            r[k].max = max(r[k].max, x);
        }
        int res = 0;
        for (int i = 0, last = Min; i < n - 1; i ++ )
            if (r[i].used) {
                res = max(res, r[i].min - last);//计算桶间的差值 
                last = r[i].max;
            }
        return res;
    }
};
