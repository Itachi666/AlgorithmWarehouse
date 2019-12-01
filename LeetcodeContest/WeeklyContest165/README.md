# Weekly Contest 165

事实证明罚时非常重要，多测两下比吃个罚时强多了。。题倒是不难，但三个罚时直接排名掉了100，本来能进200的，难受。



### 1275. Find Winner on a Tic Tac Toe Game

[题目](https://leetcode.com/contest/weekly-contest-165/problems/find-winner-on-a-tic-tac-toe-game/) 

提交次数：1/3

这题刚开始一直报一个莫名其妙的报错，最后也不知道发生了啥搁那折腾了快20分钟。然后就吃俩罚时。。事实证明给的测试样例起码要测全。。



### 1276. Number of Burgers with No Waste of Ingredients

[题目](https://leetcode.com/contest/weekly-contest-165/problems/number-of-burgers-with-no-waste-of-ingredients/)

提交次数：1/1

这题实在过分了，看完发现是个二元一次方程，闹呢



### 1277. Count Square Submatrices with All Ones

[题目](https://leetcode.com/contest/weekly-contest-165/problems/count-square-submatrices-with-all-ones/)

提交次数：1/2

比那个找矩阵的好点，`dp[i][j]`记录以这个点为右下角的最大正方形的边长，然后把所有加一块就行了。

吃了个罚时，因为没有判定这个点自己是不是`1`，有点蠢




### 1278. Palindrome Partitioning III

[题目](https://leetcode.com/contest/weekly-contest-165/problems/palindrome-partitioning-iii/)

提交次数：1/1

比较基础的dp，考虑到对一段固定的字符串来说替换成回文串次数是固定的，所以`dp[i][k]`记录前`i`个被分成了`k`段之后的最小替换次数，然后`j`遍历`1-i`来推就可以了。
