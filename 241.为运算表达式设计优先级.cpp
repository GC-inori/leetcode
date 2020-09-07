���õݹ�ķ�ʽ��ÿ��ͨ��ĳ�������������ǰ�ַ����ֳ����������֣��ݹ���������㡣
Ȼ��������������ַ��صĽ����ͨ�����������ϳ��µĽ����
�ݹ����Ϊ��ǰ�ַ�������һ�����֡�
class Solution {
public:
    vector<int> num;
    vector<char> signal;
    vector<int> dfs(int l,int r)
    {
        if(l>=r) return {num[l]};
        vector<int> res;
        for(int i=l;i<r;i++)//ѡȡһ������� ����� 
        {
            vector<int> ll=dfs(l,l+i-l),rr=dfs(l+i-l+1,r);
            if(signal[i]=='+') 
            {
                for(auto &c:ll)
                    for(auto &cc:rr) res.push_back(c+cc);
            }
            else if(signal[i]=='-')
            {
                for(auto &c:ll)
                    for(auto &cc:rr) res.push_back(c-cc);
            }
            else
            {
                for(auto &c:ll)
                    for(auto &cc:rr) res.push_back(c*cc);
            }
        }
        return res;
    }
    vector<int> diffWaysToCompute(string input) 
    {
        for(int i=0;i<input.size();i++)
            if(input[i]<='9'&&input[i]>='0')
            {
                int t=input[i]-'0';
                while(++i<input.size()&&input[i]<='9'&&input[i]>='0') t=t*10+input[i]-'0';
                num.push_back(t);
                i--;
            }
            else signal.push_back(input[i]);
        return dfs(0,num.size()-1);
    }
};
