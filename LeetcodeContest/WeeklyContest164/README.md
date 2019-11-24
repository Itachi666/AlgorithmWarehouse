# Weekly Contest 164

水题四道emmm，还算不错40分钟做完了，侥幸进了前200



### 1266. Minimum Time Visiting All Points

[题目](https://leetcode.com/contest/weekly-contest-164/problems/minimum-time-visiting-all-points/) 

提交次数：1/1

两点路线固定，还按顺序，直接算就行了。



### 1267. Count Servers that Communicate

[题目](https://leetcode.com/contest/weekly-contest-164/problems/count-servers-that-communicate/)

提交次数：1/1

开两个数组记录每行每列各有多少个机器就行了。

本来想尝试一次扫描搞定来着，看了看数据范围也不大不打算耽误多长时间了，就直接暴力了。



### 1268. Greatest Sum Divisible by Three 

[题目](https://leetcode.com/contest/weekly-contest-164/problems/search-suggestions-system/)

提交次数：1/1

最后写的这道题，看见这种一堆words的就头疼。。

数据范围不大直接写的暴力，单词每加一个字母得到的搜索结果肯定是上一个搜索结果里面的，最后输出前把记录取前三个就行了。

看了看题解似乎是想让用字典树，真的这个数据范围太弱了加俩零应该就没啥问题了。。字典树的问题在于会自动去重，要在叶子的地方做一些处理。




### 1269. Number of Ways to Stay in the Same Place After Some Steps

[题目](https://leetcode.com/contest/weekly-contest-164/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps/)

提交次数：1/1

不知道见多少次的dp了，`arrLen`看着挺吓人但其实也就那么回事，只要`steps`不高压根就走不过去。
