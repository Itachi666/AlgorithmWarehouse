# Weekly Contest 166

题有点过于水了。。。40分钟做完排名300我还以为看错了。总共1k+人次完赛，这个难度不太应该。

值得一提的是1037那一名靠着面向测试数据编程的方式暴力过了23333，用十几次提交测出了所有测试数据（真的有啥意义。。）



### 1281. Subtract the Product and Sum of Digits of an Integer

[题目](https://leetcode.com/contest/weekly-contest-166/problems/subtract-the-product-and-sum-of-digits-of-an-integer/) 

提交次数：1/1

签到题，数字拆分。。。为数不多的几次写完就敢直接交的。



### 1282. Group the People Given the Group Size They Belong To

[题目](https://leetcode.com/contest/weekly-contest-166/problems/group-the-people-given-the-group-size-they-belong-to/)

提交次数：1/1

纯模拟，虽然题干说了一堆有的没的，但还是模拟。



### 1283. Find the Smallest Divisor Given a Threshold

[题目](https://leetcode.com/contest/weekly-contest-166/problems/find-the-smallest-divisor-given-a-threshold/)

提交次数：1/1

这个曾经见过一次类似的，能够发现`f(x)`和`x`是单调增的关系，所以直接二分就行了。




### 1284. Minimum Number of Flips to Convert Binary Matrix to Zero Matrix

[题目](https://leetcode.com/contest/weekly-contest-166/problems/minimum-number-of-flips-to-convert-binary-matrix-to-zero-matrix/)

提交次数：1/1

做之前看了一眼难度是6，刚开始看完题感觉搜索好像要超时，结果一看矩阵最大3*3。

不说了谁都别拦着我暴力

本来bfs是考虑记录点坐标判重的，结果发现好像有点问题做不到，就直接把矩阵哈希进去了。看了看题解可以考虑状态压缩，直接当成一个9bit的数就可以，1k都不到。

这题还是值得研究一下的，主要是状态压缩部分，毕竟数据量上来了不太好处理。看了看主流的讨论思路是把每一位翻不翻记录成一个数（还是状态压缩），然后对每一个状态检查他是不是把矩阵变成全0了，如果是的话就统计下计数。时间复杂度大概是$O(2^{mn}*mn)$。好像效率上和我写的差不多，但是好写emmm

附两个大佬代码：

```c++
// by nhho
class Solution {
public:
    int minFlips(vector<vector<int>>& x) {
        int n = x.size();
        int m =x[0].size();
        int ans = -1;
        for (int i = 0; i < (1 << (n * m)); i++) {
            auto y = x;
            int cnt = 0;
            for (int j = 0; j < n * m; j++) {
                if (i & (1 << j)) {
                    cnt++;
                int a = j / m;
                int b = j % m;
                y[a][b] ^= 1;
                if (a)
                    y[a - 1][b] ^= 1;
                if (b)
                    y[a][b - 1] ^= 1;
                if (a != n - 1)
                    y[a + 1][b] ^= 1;
                if (b != m- 1)
                    y[a][b + 1] ^= 1;}
            }
            bool ok= 1;
            for (auto& j : y)for (int k : j) if (k)ok = 0;
            if (ok && (ans == -1 || cnt < ans))
                ans = cnt;
        }
        return ans;
    }
};
```

```c++
// by wifiii
class Solution {
public:
    int minFlips(vector<vector<int>>& a) {
        int dir1[] = {-1,1,0,0};
        int dir2[] = {0,0,-1,1};
        int n = a.size(), m = a[0].size();
        int sz = n*m;
        int ret = 1e9;
        
        for(int i=0;i<1<<sz;++i) {
            vector<vector<int>> tmp(n,vector<int>(m));
            for(int i=0;i<n;++i) for(int j=0;j<m;++j) tmp[i][j] = a[i][j];
            for(int j=0;j<sz;++j) {
                if(i&(1<<j)) {
                    int x=j/m,y=j%m;
                    tmp[x][y] = 1-tmp[x][y];
                    for(int k=0;k<4;++k) {
                        int xx=x+dir1[k],yy=y+dir2[k];
                        if(xx<0||yy<0||xx>=n||yy>=m) continue;
                        tmp[xx][yy] = 1-tmp[xx][yy];
                    }
                }
            }
            int ok=1;
            for(int i=0;i<n;++i) for(int j=0;j<m;++j) if(tmp[i][j]) ok=0;
            if(ok) ret=min(ret,__builtin_popcount(i));
        }
        if(ret > 1000) return -1;
        return ret;
    }
};
```

补充：`int __builtin_popcount(unsigned int)`用于计算一个 32 位无符号整数有多少个位为1

> 这个题如果扩展到$0<=n,m<=500$这种数据范围。只需要枚举第一行就行了

emmm没想清楚这个是什么原因，不过确实数据范围到100感觉会很棘手，先坑着