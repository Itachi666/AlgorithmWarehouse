# Weekly Contest 170

头天晚上通了个宵，本来觉得估计要翘掉这次了，结果没想到硬是在9点半的时候醒了怎么都睡不着，干脆爬起来打了。还好没太影响智商（还是影响了的）

### 1309. Decrypt String from Alphabet to Integer Mapping

[题目](https://leetcode.com/contest/weekly-contest-170/problems/decrypt-string-from-alphabet-to-integer-mapping/) 

提交次数：1/1

第一题猛一看感觉有点棘手，又是字符串替换又是要考虑冲突啥的。仔细一想好像只要处理一个`#`号就行了，于是思路变成优先看当前后面的第二位是不是`#`号，如果是的话就按`#`号替换就好了。



### 1310. XOR Queries of a Subarray

[题目](https://leetcode.com/contest/weekly-contest-170/problems/xor-queries-of-a-subarray/)

提交次数：1/1

就是个前缀和，异或是有前缀和性质的，没啥好说的


### 1311. Get Watched Videos by Your Friends

[题目](https://leetcode.com/contest/weekly-contest-170/problems/get-watched-videos-by-your-friends/)

提交次数：1/1

这题在小号上挂了一次emm，所以严格意义上其实应该有个罚时的。

上来看着头疼直接写Q4去了，做完回来再看发现其实就是一个裸的BFS，但是对最后获得的视频顺序上有点麻烦，在这方面上纠结了一会，没想到什么直接获得的好办法，还是老老实实单独处理了。

耽误时间主要就是忘记标记重复了，结果也没反应过来只给初始值标记了个重，还查了估计十多分钟，耽误了不少时间。


### 1312. Minimum Insertion Steps to Make a String Palindrome

[题目](https://leetcode.com/contest/weekly-contest-170/problems/minimum-insertion-steps-to-make-a-string-palindrome/)

提交次数：1/1

这题都不知道出几次了。。直接写了个区间dp交上去了，状态转移方程代码听清楚的就懒得打在这了XD

看讨论还有别的方法，这题等价于求最大回文子序列，剩下的就是需要添加的字母个数。把字符串反过来排一个最长公共子序列是个不错的方法。