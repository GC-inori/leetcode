�Ƚ��䰴�Ӵ�С����
���ڵ�iΪλ ��� citations[i] > i ��ôֻ�� i������citations[i]���� i<citations[i] <= i
��citations[i] <=i ʱ ��i��������i
����i���� 
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
