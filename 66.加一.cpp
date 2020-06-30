class Solution {
public:
    vector<int> plusOne(vector<int>& digits) 
    {
        int t=1;
        for(int i=digits.size()-1;~i;i--)
        {
            t+=digits[i];
            digits[i]=t%10;
            t/=10;
            if(!t) break;
        }
        if(t) digits.insert(digits.begin(),1);
        return digits;    
    }
};
