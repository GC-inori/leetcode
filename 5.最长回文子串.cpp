由于回文分为偶回文（比如 bccb）和奇回文（比如 bcacb），而在处理奇偶问题上会比较繁琐，所以这里我们使用一个技巧，具体做法是：在字符串首尾，及各字符间各插入一个字符（前提这个字符未出现在串里）。

举个例子：s="abbahopxpo"，转换为p="$#a#b#b#a#h#o#p#x#p#o#@"（这里的字符 $@ 只是为了防止越界，下面代码会有说明），如此，s 里起初有一个偶回文abba和一个奇回文opxpo，被转换为#a#b#b#a#和#o#p#x#p#o#，长度都转换成了奇数。

定义一个辅助数组int f[]，其中f[i]表示以 i 为中心的最长回文的半径，例如：

i           0   1   2   3   4   5   6   7   8   9   10  11  12  13  14  15  16  17  18  19   20
p           $   #   a   #   b   #   b   #   a   #   h   #   o   #   p   #   x   #   p   #    @
f[i]        1   2   1   2   5   2   1   2   1   2   1   2   1   2   1   4   1   2   1   0    
可以看出，f[i] - 1正好是原字符串中最长回文串的长度。

接下来的重点就是求解 f 数组：

设置两个变量，mx 和 id 。mx 代表以 id 为中心的最长回文的右边界，也就是mx = id + p[id]。

假设我们现在求p[i]，也就是以 i 为中心的最长回文半径，如果i < mx，那么：
if (i < mx)  
    f[i] = min(f[2 * id - i], mx - i);
2 * id - i为 i 关于 id 的对称点j点，而f[j]表示以j为中心的最长回文半径，因此我们可以利用f[j]来加快查找
否则的话,f[j]=1,向两边扩展
class Solution 
{
public:
    string longestPalindrome(string s) 
    {
        string p="$#";
        for(auto c:s)
        {
            p.push_back(c);
            p.push_back('#');
        }
        p.push_back('@');
        int r=0,id=0,lmax=0,f[2010]={0},resid;
        for(int i=1,n=p.size()-1;i<n;i++)
        {
            f[i]=lmax>i?min(f[2*id-i],lmax-i):1;
            while(p[i+f[i]]==p[i-f[i]]) f[i]++; //向两边扩展
            if(f[i]+i>lmax)
            {
                lmax=f[i]+i;
                id=i;
            }
            if(f[i]>r) 
            {
                r=f[i];
                resid=i;
            } 
        }
        return s.substr(resid-r>>1,r-1);
    }
};

