(计算几何) O(1)
两个矩形并集的面积 = 两个矩形的总面积 - 两个矩形交集的面积。

两个矩形如果有交集，那么交集一定是矩形，剩下的问题是求出交集的长和宽。

求交集的长和宽是一个一维问题，即在数轴上给出线段 [A,B] 和 [C,D]，求它们交集的长度。
其交集的长度：L=min(B,D)-max(A,C)如果 L<0，说明两个线段不重合。
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) 
    {
        long long s=1ll*(C-A)*(D-B)+1ll*(G-E)*(H-F);//防止数据爆int 
        long long x=max(0ll,0ll+min(C,G)-max(A,E)),y=max(0ll,0ll+min(D,H)-max(B,F));
        return s-x*y;
    }
};
