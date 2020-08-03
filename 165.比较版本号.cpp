class Solution {
public:
    int compareVersion(string version1, string version2) 
    {
        int i=0,j=0;
        while(i<version1.size()||j<version2.size())
        {
            int k=i+1,l=j+1;
            while(k<version1.size()&&version1[k]!='.') k++;//找到当前数字结尾 
            while(l<version2.size()&&version2[l]!='.') l++;
            long long v1=i<version1.size()?stoll(version1.substr(i,k-i)):0,//转换版本号 如果到达结尾记为0 
                      v2=j<version2.size()?stoll(version2.substr(j,l-j)):0;
            if(v1!=v2) return v1>v2?1:-1;
            i=k+1,j=l+1;
        }
        return 0;
    }
};
