为了能尽量优化常数，我们在递归过程中尽量不要使用栈来维护表达式。本题中我们维护如下不变式：

a+b*()，其中括号中的数是我们枚举的下一个数；
然后分类讨论下一个运算符，其中 c 是枚举的括号中的数：

下一个运算符是加号，那么 a+b×(c)+()=(a+b×c)+1×()
下一个运算符是减号，那么 a+b×(c)-()=(a+b×c)+(-1)×()
下一个运算符是乘号，那么 a+b×(c)×()=a+(b×c)×()
为了方便，在表达式最后统一添加一个加号，那么最终不变式就会变成 a+1×()，所以 a 就是枚举的表达式的值，判断一下和target是否相等即可。

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
            //加号
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
