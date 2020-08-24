�ַ���hash 
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) 
    {
        if(s.size()<=10) return {};//���С�ڵ���10 �������ظ� 
        vector<string> res;
        unsigned long long p=1,hash=0;
        unordered_map<unsigned long long,int> m;// unsigned long long��¼��ϣֵ int ��¼���ִ��� 
        for(int i=0;i<10;i++)
        {
            hash=hash*131+s[i];
            if(i<9) p*=131;
        }
        m[hash]=1;//�����һ�� 
        for(int i=10,n=s.size();i<n;i++)
        {
            hash=(hash-s[i-10]*p)*131+s[i];//��ǰһ���Ĺ�ϣֵ���һ�� 
            m[hash]++;
            if(m[hash]==2)
                res.push_back(s.substr(i-9,10));
        }
        return res;
    }
};
