# Biweekly Contest 16

Q2两个罚时有点蛋疼，第四题还是dp不太熟，总想着搜。。来回改了好几次耽误了不少时间



### 1299. Replace Elements with Greatest Element on Right Side

[题目](https://leetcode.com/contest/biweekly-contest-16/problems/replace-elements-with-greatest-element-on-right-side/)

提交次数：1/1

基本就是单调栈那个思路，开个变量存着就行了。



### 1300. Sum of Mutated Array Closest to Target

[题目](https://leetcode.com/contest/biweekly-contest-16/problems/sum-of-mutated-array-closest-to-target/)

提交次数：1/3

一开始想写二分来着，结果二分感觉不太好处理边界就想写个$n^2$的代码赌一把，然后果断跪了2333。老老实实换回二分，对最后$l=r-1$的边界感觉很棘手一直，最后直接把在这种情况下单独判断了一下才过。

看别人的代码其实可以分成$[l, m-1], m, [m+1, r]$三个区间，期间一直记录最小值就可以了，思路不太灵活。



### 1302. Deepest Leaves Sum

[题目](https://leetcode.com/contest/biweekly-contest-16/problems/deepest-leaves-sum/)

提交次数：1/1

就是个bfs层次遍历，不说了。



### 1301. Number of Paths with Max Score

[题目](https://leetcode.com/contest/biweekly-contest-16/problems/number-of-paths-with-max-score/)

提交次数：1/1

其实就是两遍dp，第一遍从右下到左上正常求最大值，第二遍从左上到右下推次数。

结果从看见就想着搜。。犹豫了一会先把第一遍dp写了，然后次数又想着靠第一遍推出来的dp剪枝搜。。。冷静了一会终于想到了正解，然而时间用太多了还是没排进200。