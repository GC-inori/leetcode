//找规律
class Solution {
public:
    string convert(string s, int numRows) 
    {
        if(s.size()<=numRows||numRows==1) return s;
        string res;
        int step1=2*numRows-2;  //每个循环长度为step1=2*numRows-2
        for(int i=0,n=s.size(),step2;i<numRows;i++)
            for(int j=i;j<n;j+=step1)
            {
                res.push_back(s[j]);
                step2=i?2*(numRows-i-1):0;   //第一行和最后一行不需要添加第二个
                if(step2&&j+step2<n) res.push_back(s[j+step2]);
            }
        return res;
    }
};
