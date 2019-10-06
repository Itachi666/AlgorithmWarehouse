# Weekly Contest 157

1小时ac。这周两次的题是真的水。

### 1217. Play with Chips

[题目](https://leetcode.com/contest/weekly-contest-157/problems/play-with-chips/)

提交次数：1/3

对着签到题疯狂报错。。。

刚开始感觉应该是和奇偶数有点关系，但看了看数据范围实在太小就想写个暴力算了，没想到暴力还写错了。。

其实就是统计下奇偶数个数找个小的返回就行了。

### 1218. Longest Arithmetic Subsequence of Given Difference

[题目](https://leetcode.com/contest/weekly-contest-157/problems/longest-arithmetic-subsequence-of-given-difference/)

提交次数：1/1

本来还以为是个什么最长上升子序列的变形，看了看数据范围还在想要写个二分出来。

仔细一想连间隔都给了我只要找上一个数在哪就行了，开个map存一下每一个数目前最长的序列长度就行了。

### 1219. Path with Maximum Gold

[题目](https://leetcode.com/contest/weekly-contest-157/problems/path-with-maximum-gold/)

提交次数：1/2

其实就是个dfs（最近dfs真多），刚开始想玩个骚的搞记忆化搜索结果爆了。。不同的点出发得到的dp图是不一样的，后来干脆删了就a了。。

### 1220. Count Vowels Permutation

[题目](https://leetcode.com/contest/weekly-contest-157/problems/count-vowels-permutation/)

提交次数：1/1

一个评论说的很好，这题就不该是hard。。

首先看一眼，好像乌龟棋那题；再一看数据范围，2w。行吧dp

没什么好说的，5个数组维护(`'a'`, `'e'`, `'i'`, `'o'`, `'u'`)的数量，一路往后递推就行了，懒得写方程了看代码吧（真有人看这个的话）。

