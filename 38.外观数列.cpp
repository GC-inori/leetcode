ģ�⼴�� 
class Solution {
public:
    vector<string> res={"1"};
    string countAndSay(int n) 
    {
        if(n<=res.size()) return res[n-1];
        for(int i=res.size()-1;i<n;i++)
        {
            string tmp;
            for(int j=0,N=res[i].size();j<N;)
            {
                int t=j+1;
                while(t<N&&res[i][t]==res[i][j]) t++; //�����м��������ظ����� 
                tmp+=to_string(t-j)+res[i][j];
                j=t;
            }
            res.push_back(tmp);
        }
        return res[n-1];
    }
};
