Ϊ���ܾ����Ż������������ڵݹ�����о�����Ҫʹ��ջ��ά�����ʽ������������ά�����²���ʽ��

a+b*()�����������е���������ö�ٵ���һ������
Ȼ�����������һ������������� c ��ö�ٵ������е�����

��һ��������ǼӺţ���ô a+b��(c)+()=(a+b��c)+1��()
��һ��������Ǽ��ţ���ô a+b��(c)-()=(a+b��c)+(-1)��()
��һ��������ǳ˺ţ���ô a+b��(c)��()=a+(b��c)��()
Ϊ�˷��㣬�ڱ��ʽ���ͳһ���һ���Ӻţ���ô���ղ���ʽ�ͻ��� a+1��()������ a ����ö�ٵı��ʽ��ֵ���ж�һ�º�target�Ƿ���ȼ��ɡ�

class Solution {
public:
    vector<string> res;
    string tmp;
    int t;
    void dfs(string &num,int len,int pos,long long a,long long b)
    {
        if(num.size()==pos)
        {
            if(a==t)
                res.push_back(tmp.substr(0,len-1));
            return;
        }
        for(long long i=pos,t=0;i<num.size();i++)
        {
            t=t*10+num[i]-'0';
            //�Ӻ�
            tmp[len++]=num[i];
            tmp[len]='+';
            dfs(num,len+1,i+1,a+b*t,1);
            if(i<num.size()-1)
            {
                //*
                tmp[len]='*';
                dfs(num,len+1,i+1,a,b*t);
                // -
                tmp[len]='-';
                dfs(num,len+1,i+1,a+b*t,-1);
            }
            if(t==0) break;
        }
    }
    vector<string> addOperators(string num, int target) 
    {
        tmp.resize(100);
        t=target;
        dfs(num,0,0,0,1);
        return res;
    }
};
