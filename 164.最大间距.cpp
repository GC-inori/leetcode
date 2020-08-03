Ͱ����
����������Max��Min�ֱ��ʾ��ӦͰ�е����ֵ����Сֵ��
Ҫע����ǣ�����Ԫ�ص�����ֵһ����ĳ���ǿ�Ͱ�е���Сֵ��λ����֮ǰ�ĵ�һ���ǿ�Ͱ�е����ֵ֮� 
������͵Ļ���������ô��⣬��������£�Ͱ�����е�����Ԫ�س��ֳ����ȷֲ�����ÿһ��Ͱ��ֻ��һ��Ԫ�ء�
��ʱ����Ȼ�����е�����Ϊ��Ͱ���ֵ��
��һ�����Ǿ��ȷֲ������ƴ�ĳЩͰ�г����һЩԪ�أ����뵽������Ͱ����ʱ��һ�����п�Ͱ���֡�
����������ǿ�Ͱ֮����ڿ�Ͱ,Ҳ����ζ�ź�һ��Ͱ����С��Ԫ�ر�ǰһ��Ͱ������Ԫ�ػ�Ҫ��һ������Ͱ�������������ֵһ������Ͱ������Ԫ�صĲ�ֵ(Ͱ��Ԫ�ز�ֵ���ᳬ��Ͱ������)�� 
class Solution {
public:
    int maximumGap(vector<int>& nums) 
    {
        struct Range {
            int min, max;
            bool used;
            Range() : min(INT_MAX), max(INT_MIN), used(false){}
        };
        int n = nums.size();
        int Min = INT_MAX, Max = INT_MIN;
        for (auto x: nums) {
            Min = min(Min, x);
            Max = max(Max, x);
        }//Ѱ�������е���ֵ 
        if (n < 2 || Min == Max) return 0;
        vector<Range> r(n - 1);//n-1��Ͱ 
        int len = (Max - Min + n - 2) / (n - 1);
        for (auto x: nums) {
            if (x == Min) continue;
            int k = (x - Min - 1) / len;
            r[k].used = true;
            r[k].min = min(r[k].min, x);//����ÿ��Ͱ�ڵ������Сֵ 
            r[k].max = max(r[k].max, x);
        }
        int res = 0;
        for (int i = 0, last = Min; i < n - 1; i ++ )
            if (r[i].used) {
                res = max(res, r[i].min - last);//����Ͱ��Ĳ�ֵ 
                last = r[i].max;
            }
        return res;
    }
};
