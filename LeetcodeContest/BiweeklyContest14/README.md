# Biweekly Contest 14

被第三题搞的头大，拖了好久结果没时间做Q4。其实讲道理第三题不难爆搜完全能过，就是自己一直不太想写爆搜结果出了好多问题。当然第四题讲道理15分钟其实够了，感觉自己二分还是不熟练每次边界都要调好久。



### 1271. Hexspeak

[题目](https://leetcode.com/contest/biweekly-contest-14/problems/hexspeak/)

提交次数：1/1

真签到题，16进制转换，实在没啥说的。



### 1272. Remove Interval

[题目](https://leetcode.com/contest/biweekly-contest-14/problems/remove-interval/)

提交次数：1/1

这题也不难，跑一遍区间判断一下重合度就可以了



### 1273. Delete Tree Nodes

[题目](https://leetcode.com/contest/biweekly-contest-13/problems/synonymous-sentences/)

提交次数：1/1

这题看了看觉得不用构造邻接表去存孩子（然后就坑了），一开始思路是一遍遍搜索叶子节点，把不是0的叶子权重加到他父节点上。中途发现还需要记录每个节点的总孩子个数来删节点，头就有点乱写了半天才出来。然后就没想到被测试数据坑了，一直以为是第一个数据有问题结果是第二个的问题，在那查了半天也没看出来。。。

事实证明测试数据过一个添一个，出错的时候还是一个个来比较好。



### 1274. Number of Ships in a Rectangle

[题目](https://leetcode.com/contest/biweekly-contest-14/problems/number-of-ships-in-a-rectangle/)

提交次数：0/0

刚开始看见什么互动问题吓了一跳就先做第三题去了，回头看看这一题真的不难，算了一下次数二分是绝对够用的，每次分成4个区域走下去就可以了，如果这个区域是false直接返回，否则直到找到那个点为止。

主要还是对边界没有理清，加上被第三题搞的心态有点炸，就出现了很多边角的细节问题。到时间了之后反而冷静了下来10分钟调出来了。

