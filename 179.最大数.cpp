class Solution {
public:
    string largestNumber(vector<int>& nums) 
    {
        string res;
        if(nums.empty()) return res;
        vector<string> v;
        for(auto &c:nums) v.push_back(to_string(c));
        sort(v.begin(),v.end(),[](string &a,string &b){
            return a+b>b+a;});//ƫ���ϵ 
        for(auto &c:v)
            res+=c;
        if(res[0]=='0') return "0";//������λΪ0˵���ý��Ϊ0 
        return res;
    }
};
