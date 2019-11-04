# Biweekly Contest 10

头一次全ac还是比较舒服的，虽然是压线交的。

### 1213. Intersection of Three Sorted Arrays

[题目](https://leetcode.com/contest/biweekly-contest-10/problems/intersection-of-three-sorted-arrays/)

提交次数：1/1

签到题，开个hashmap记录下所有数出现次数，输出出现次数是3的就可以了。

看题目他的有序数组绝对可以做文章，改改应该是可以减少空间存储的开销。

### 1214. Two Sum BSTs

[题目](https://leetcode.com/contest/biweekly-contest-10/problems/two-sum-bsts/)

提交次数：1/1

刚看见还慌了一下因为没用过leetcode上的树结构。结果回来仔细一看还是搜索树，，，遍历第一个树去第二个树二分找就完事了。

### 1215. Stepping Numbers

[题目](https://leetcode.com/contest/biweekly-contest-10/problems/stepping-numbers/)

提交次数：1/1

说起来最近写了好多dfs。

没什么好说的裸的dfs，按位数枚举就行了。处理好边界条件和0就好，最后记得排序。

### 1216. Valid Palindrome III

[题目](https://leetcode.com/contest/biweekly-contest-10/problems/valid-palindrome-iii/)

提交次数：1/5

愉悦的提交了5次，25min的罚时看的心疼。。事实说明感觉能dp的题肯定能dp，少总想着去搜

之前的搜索思路就不提了，各种报错心态都快崩了，然后还超时。最后半小时改成了dp两次过了。

思路很简单，就当区间dp做就好，对`dp[i][j]`只有两种情况：当两端相等的时候，那么是可以从`dp[i+1][j-1]`推出来，否则就看两遍删哪个次数少就行了，状态转移方程：

$$
dp[i][j]=\begin{equation}  
\left\{  
             \begin{array}{**l**}  
             0, & i=j.  \\  
             0, & j-i=1, s[i]=s[j].\\
             min(dp[i+1][j], dp[i][j-1])+1, & s[i]\neq s[j].\\  
             dp[i+1][j-1], & s[i]=s[j].    
             \end{array}  
\right.  
\end{equation}
$$

![](http://latex.codecogs.com/gif.latex?d p[i][j]=\left\{\begin{array}{ll}{0,} & {i=j} \\ {0,} & {j-i=1, s[i]=s[j]} \\ {\min (d p[i+1][j], d p[i][j-1])+1,} & {s[i] \neq s[j]} \\ {d p[i+1][j-1],} & {s[i]=s[j]}\end{array}\right.)

出错是因为忘了两个相同字母也是一个回文串了，，也是初始条件之一。







做完翻评论看到说这一题把字符串翻转一下，就变成了最长公共子序列问题了，大佬还是厉害。。。