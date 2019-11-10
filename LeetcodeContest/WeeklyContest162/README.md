# Weekly Contest 162

一个罚时没进200，有点难过。这次题目说实话都直接的。。



### 1252. Cells with Odd Values in a Matrix 

[题目]( https://leetcode.com/contest/weekly-contest-162/problems/cells-with-odd-values-in-a-matrix/ ) 

提交次数：1/1

日常签到题，数据量比较小模拟就行了

不过也可以只统计行和列的计数情况，分别统计被增加偶数次和奇数次的行，以及被增加偶数次和奇数次的列，那么对应的 偶数行∗奇数列 和 奇数行∗偶数列 都可以被统计入结果，时间复杂度降为 O(n)



### 1253. Reconstruct a 2-Row Binary Matrix    

[题目]( https://leetcode.com/contest/weekly-contest-162/problems/reconstruct-a-2-row-binary-matrix/ )

提交次数：1/2

交的时候不太确定，不过用贪心足够了。对0和2来说不用考虑什么，1的时候选多的那个减一就可以了。

不过最后没看见每一行数目必须正好对上upper和lower才行。。。



### 1254. Number of Closed Islands 

[题目]( https://leetcode.com/contest/weekly-contest-162/problems/number-of-closed-islands/ )

提交次数：1/1

标准搜索题。直接bfs就行了。



### 1255. Maximum Score Words Formed by Letters 

[题目]( https://leetcode.com/contest/weekly-contest-162/problems/maximum-score-words-formed-by-letters/ )

提交次数：1/1

dfs搜就行了。。。

数据量不大，考虑了几个优化点不知道用上了没有。

