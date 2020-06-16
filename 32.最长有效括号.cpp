双向扫描。

第一遍从左往右扫描，left和right分别代表当前合法的左括号个数和右括号个数。遇到左括号left ++，遇到右括号right ++，
如果left = right，说明找到了一个合法的括号对，更新答案，如果left < right，说明后面怎么匹配都不可能合法了，此时把left和right置为0。

但是这样对于((())的括号序列，得不到正确解，因此我们继续从右往左匹配一次。left>right时，也无法判读是否合法如 "()(()"left=3 right=2 

第二遍第一遍从右往左扫描，left和right分别代表当前合法的左括号个数和右括号个数。遇到左括号left ++，遇到右括号right ++，
如果left = right，说明找到了一个合法的括号对，更新答案，如果left > right，说明前面怎么匹配都不可能合法了，此时把left和right置为0。

class Solution {
public:
    int longestValidParentheses(string s) 
    {
        int left=0,right=0,res=0;
        for(auto &c:s)
        {
            if(c=='(') left++;
            else
            {
                right++;
                if(right>left) right=left=0;
                else if(right==left) res=max(right<<1,res);
            }
        }
        right=left=0;
        for(int i=s.size()-1;i>=0;i--)
        {
            if(s[i]==')') right++;
            else
            {
                left++;
                if(left>right) left=right=0;
                else if(left==right) res=max(left<<1,res);
            }
        }
        return res;    
    }
};
