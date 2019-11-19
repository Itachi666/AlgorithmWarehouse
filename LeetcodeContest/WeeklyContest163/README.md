# Weekly Contest 163

头天晚上睡得太晚硬是睡过了。。迟到了半小时开始做，结果只做出来了两道。但没想到排名直接掉了40+，这掉的也太多了。。事实证明刚爬起来就不要瞎搞什么动脑子的活动。



### 1260. Shift 2D Grid 

[题目]( https://leetcode.com/contest/weekly-contest-163/problems/shift-2d-grid/ ) 

提交次数：1/1

刚开始看成矩阵旋转，写了一会发现看错题直接暴力模拟了，看题解说可以把这个矩阵拉成线性数组移位之后在放回去。



### 1261. Find Elements in a Contaminated Binary Tree 

[题目]( https://leetcode.com/contest/weekly-contest-163/problems/find-elements-in-a-contaminated-binary-tree/ )

提交次数：1/1

简单的树的遍历操作，没啥好说的



### 1262. Greatest Sum Divisible by Three 

[题目]( https://leetcode.com/contest/weekly-contest-162/problems/number-of-closed-islands/ )

提交次数：0/5？

难不难不好说，写这题的时候脑子简直一坨浆糊。。更没想到的是这题的dp思路和下午的Kickstart思路相同。。这个就留着那篇再说吧

忘了一开始怎么想的了，好像一直在贪心结果被各种特例吊打逐渐心态就崩了

两种做法：第一种很简单，求和取模，如果模3余1就找到最小的模3余1的值或者最小的两个模3余2的值，模3余2亦然。

另一种就是dp思路：`dp[i][j]` 表示前`i`个元素在模3余0，1，2的最大值，状态转移方程就有：

```c++
dp[i+1][(j + nums[i])%3] = max(dp[i][(j + nums[i])%3], dp[i][j]+nums[i])
```



### 1263. Minimum Moves to Move a Box to Their Target Location 

[题目]( https://leetcode.com/contest/weekly-contest-162/problems/maximum-score-words-formed-by-letters/ )

提交次数：0/?

最开始看到感觉代码量挺大的，最后补一下事实上也确实代码量挺大的emmmm

双重染色问题，两个BFS搞定了。

首先第一重BFS来记录推箱子，分别记录箱子的位置和人的位置。在每一个状态中，以人的位置为起点进行一次BFS遍历染色，找出所有人能够在不推箱子的情况下走到的位置，如果这个位置能够推箱子，就把他加入第一重BFS中。

但是坑在于如何记录箱子的移动，也就是去重。

一开始我是直接以记录箱子位置来判重，但是实际上会出现需要人先把箱子推过去后过去然后再推回来的情况。尝试删除这个判重结果果然爆炸，最后看数据范围直接开了个四重数组来记录人和箱子的位置来解决的。想了想可以简化一下，三维数组来记录箱子的位置和方向，应该也是可以的。

