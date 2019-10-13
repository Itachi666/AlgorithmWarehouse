# Weekly Contest 158

讲道理这次的题比上次强，第三题dp卡了一会然后卡在第四题，结果出来之后发现似乎并没有多少人卡第四题，，好消息是这次没有出现罚时。

### 1221. Split a String in Balanced Strings

[题目](https://leetcode.com/contest/weekly-contest-158/problems/split-a-string-in-balanced-strings/)

提交次数：1/1

签到题，从头跑到尾计数就行了。

### 1222. Queens That Can Attack the King

[题目](https://leetcode.com/contest/weekly-contest-158/problems/queens-that-can-attack-the-king/)

提交次数：1/1

很简单的暴力，按king的位置往八个方向搜就行了，为了省时间代码也写的特别暴力。。

### 1223. Dice Roll Simulation

[题目](https://leetcode.com/contest/weekly-contest-158/problems/dice-roll-simulation/)

提交次数：1/1

其实说到底还是dp，省点空间的话可以用滚动数组，这题算了算空间消耗够了就懒得写了。

说实话还是卡了一会的，原本尝试一个数组递推，然后发现不太行，在递推过程中原数组是不能发生变动的。最后就直接开了个5000长的三维数组2333

剩下就很简单了，`dp[i][j][k]`表示第`i`轮末尾有`k`个`j`的序列有多少个，对每一个往后推就好了。

### 1224. Maximum Equal Frequency

[题目](https://leetcode.com/contest/weekly-contest-158/problems/maximum-equal-frequency/)

提交次数：0/0

没做出来主要还是思路的问题，光想着存每个数字出现次数了，没想过还可以存每个次数有多少个数字。

知道怎么做就简单多了，两个数组，一个存数字出现次数，一个存当前次数下有多少个数字。第二个用`map`来存，当`map`中元素小于等于2的时候就可以判断了，具体会有三种情况：

- map中只有一个元素时，若该元素是1则符合条件（所有数字出现次数为1）
- map中只有一个元素时，若该元素值为1则符合条件（数组只有一个数字）
- map中有两个元素，其中一个元素为1且值为1，即`map[1]=1`（只有一个数字出现一次，其他数字出现次数相等）
- map中有两个元素，两个元素相差1且大的元素值为1（有一个数字出现次数比其他多一次）