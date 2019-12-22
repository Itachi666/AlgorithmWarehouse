# Weekly Contest 168

运气不错两次罚时还能进前200。刚做完的时候看排名还在120的样子，然后10分钟罚时过了之后就变成190了。。。题目平均难度比前几次大了点，但第四题看着难真做下来还不如第三题感觉23333细节比较多但归根结底还是个纯模拟。



### 1295. Find Numbers with Even Number of Digits

[题目](https://leetcode.com/contest/weekly-contest-168/problems/find-numbers-with-even-number-of-digits/) 

提交次数：1/1

签到题，统计位数是不是偶数，纯送。



### 1296. Divide Array in Sets of K Consecutive Numbers

[题目](https://leetcode.com/contest/weekly-contest-168/problems/divide-array-in-sets-of-k-consecutive-numbers/)

提交次数：1/1

一开始以为是要分成k组连续数字感觉好像还有点难，结果仔细一看k是长度emmm，那就没啥好说的了，开个map每次找最小的往后数k个看有没有就行了。



### 1297. Maximum Number of Occurrences of a Substring

[题目](https://leetcode.com/contest/weekly-contest-168/problems/maximum-number-of-occurrences-of-a-substring/)

提交次数：1/2

这题一直在怕爆空间hhh，为了计数开了个哈希表存子串次数，然后以长度为顺序暴搜了一波，当时还想着怎么最大长度这么小，万幸没超时。

做完看讨论才知道其实扫一遍就可以了，那个`maxLetter`就是用来吓唬人的。因为如果一个子串出现了若干次，那么这个子串的子串出现次数一定大于等于他。所以其实只要找长度为`minLetter`的出现次数最多的子串即可，往上再多都没用。




### 1298. Maximum Candies You Can Get from Boxes

[题目](https://leetcode.com/contest/weekly-contest-168/problems/maximum-candies-you-can-get-from-boxes/)

提交次数：1/2

这题我说真的，刚开始看吓了一跳这都啥玩意。另外多说一句这个题的输入数据是真的反人类md。。

本来看那么多以为是要拓扑排序啥的找最优策略，结果看完发现原来是个模拟。。开了个队列存待开箱子，另外开两个数组存手里的钥匙和暂时打不开的箱子。不过挂了一次因为没考虑两个箱子里面互相有对方钥匙的情况，加了个开过箱子的统计就过了。