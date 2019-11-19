# Biweekly Contest 13

这次双周赛居然有三个medium，快结束了打完都能差点进了200（其实能进但罚时超了，，



### 1256. Encode Number 

[题目](https://leetcode.com/contest/biweekly-contest-13/problems/encode-number/)

提交次数：1/1

签到题，然后就跪了emmm，一开始直接遍历数组然后判断操作的，结果发现前面的改动会影响后面就很难受。改成标记那些位置会改变，然后一起改就好了。

当然直接vector复制一个然后复制回去也可以，，，蠢了。

好几种办法吧，最简单的应该就是 $n+1$ 的二进制去掉首位了。

刚开始没想到，就看出来好像是以 $2^n$ 循环，写的有点复杂。



### 1257. Smallest Common Region 

[题目](https://leetcode.com/contest/biweekly-contest-13/problems/smallest-common-region/)

提交次数：1/1

不能算难，但挺麻烦的。想了想构造了一棵树，然后顺着一个节点往上搜就可以了，还好数据量不大，用两个哈希表可以存下。



### 1258. Synonymous Sentences 

[题目](https://leetcode.com/contest/biweekly-contest-13/problems/synonymous-sentences/)

提交次数：1/2

代码量有点大，wa了一次在误以为同义词的长度相同上。

刚开始看数据当成了同义词只会有两个，写完发现虽然是给的每一组两个同义词，但不同组之间也可以有相同的词，也就是说可以同时有好几个单词互相是同义词。

emmm就有点麻烦，被迫实现了一个并查集来统计。

其他的就没什么了，一个dfs搞定。



### 1259. Handshakes That Don't Cross 

[题目](https://leetcode.com/contest/biweekly-contest-13/problems/handshakes-that-dont-cross/)

提交次数：0/0

想了想认出来了dp。

`dp[i]`表示`2*i`个人的数量，枚举和1号节点连接的点`j=2,4,...,2*i`，这样剩下的就分成了两组`j-2`和`i*2-j`，乘起来就行了。

wa了一次没有对答案取余。。。不然就进200了T T

