����ת�� 10-26 ע��26���ƴ�1��ʼ ÿ��ת��ʱҪ-1�� 1-26ӳ��Ϊ0-25 
class Solution {
public:
    string convertToTitle(int n) 
    {
        string res;
        while(n)
        {
            res.push_back((n-1)%26+'A');
            n=(n-1)/26;
        }
        return string(res.rbegin(),res.rend());
    }
};
