# Biweekly Contest 11

虽然都说P4是套路题但真就没想到是二分，，而且第二题调的时间也太多了，不太应该。

贴一个大佬的[录屏讲解](https://www.youtube.com/watch?v=m0SxhYSO54Y )，感觉确实不一样我十分钟才把一道easy搞定人家已经搞定三道了。。得关注一波。

### 1228. Missing Number In Arithmetic Progression 

[题目]( https://leetcode.com/contest/biweekly-contest-11/problems/missing-number-in-arithmetic-progression/ )

提交次数：1/1

签到题，稍微有点小坑在里面，搞的复杂了点，不过等差数列就那点东西，暴力就行了。

### 1229. Meeting Scheduler 

[题目]( https://leetcode.com/contest/biweekly-contest-11/problems/meeting-scheduler/ )

提交次数：1/3

代码写的太烂实在不太想看。。

其实题解思路很简单，每次把end值小的那一项加一就可以了，硬是被我搞的贼复杂还研究半天，交了三次才过。。

### 1230. Toss Strange Coins 

[题目]( https://leetcode.com/contest/biweekly-contest-11/problems/toss-strange-coins/ )

提交次数：1/1

动归真有成为最后的遮羞布的趋势。。

本来在尝试一维动归，写了一点感觉不太舒服，重新在纸上推了一遍结果发现状态转移方程其实只有两项emmm，感觉一维空间就足够了，但是比赛的时候看能过就没再管。不算难。

### 1231. Divide Chocolate

[题目](https://leetcode.com/contest/biweekly-contest-11/problems/divide-chocolate/ )

提交次数：0/0

评论表示这题根本没有hard难度我只能汗颜。。

确实是比较套路的一道题，应该是有固定模板的。对于把一个数组分成若干连续片段并且要满足一定条件，而且答案唯一的题应该都可以这么搞

主要问题在于没有想到去从元素值范围考虑二分（好吧其实压根就没想到二分，看两眼没想到什么思路，确实有点太局限于DP了）。

知道二分就容易多了，思路就是二分答案，每一次对答案进行判断能把数组分成多少份，分多了意味着答案小了，往上加；分少了意味着答案大了，往下减。剩下的就是通常的二分细节了

