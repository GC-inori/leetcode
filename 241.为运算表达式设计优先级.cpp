采用递归的方式，每次通过某个运算符，将当前字符串分成左右两部分，递归子问题计算。
然后根据左右两部分返回的结果，通过该运算符组合成新的结果。
递归出口为当前字符串仅有一个数字。
class Solution {
public:
    vector<int> num;
    vector<char> signal;
    vector<int> dfs(int l,int r)
    {
        if(l>=r) return {num[l]};
        vector<int> res;
        for(int i=l;i<r;i++)//选取一个运算符 最后算 
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
