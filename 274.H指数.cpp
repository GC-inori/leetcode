先将其按从大到小排序
对于第i为位 如果 citations[i] > i 那么只有 i个数比citations[i]大且 i<citations[i] <= i
当citations[i] <=i 时 有i个数大于i
返回i即可 
public:
    int hIndex(vector<int>& citations) 
    {
        sort(citations.begin(), citations.end(), [](const int &a, const int &b){return a > b; });
        int i = 0;
        for (; i < citations.size(); ++i)
            if (citations[i] <= i)
                break;
        return i;
    }
};
