��̬�滮
f[i] ��ʾ s[0]~s[i-1] �ܷ����ֵ���ĵ��ʱ�ʾ
f[0]=0 
f[k]=(f[t]&&s[t]~s[k-1]���ֵ���) 
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        unordered_set<unsigned long long> us;
        for(auto &c:wordDict)//���ַ�����ϣ���ֵ���ĵ���ӳ��Ϊ�޷�������  ����ֵȡ131��1331 
        {
            unsigned long long p=0;
            for(auto &t:c) p=p*131+t;
            us.insert(p);
        }
        const int n=s.size();
        bool f[n+1];
        memset(f,0,sizeof(f));
        f[0]=1;
        for(int i=0;i<n;i++)
        {
            if(f[i])
            {
                unsigned long long t=0;
                for(int j=i;j<n;j++)
                {
                    t=t*131+s[j];
                    if(us.count(t)) f[j+1]=1;
                }
            }
        }
        return f[n];
    }
};
