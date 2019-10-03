# Weekly Contest 156

### 1207. Unique Number of Occurrences

[题目](https://leetcode.com/contest/weekly-contest-156/problems/unique-number-of-occurrences/)

提交次数：1/1

签到题，搞个set判重就完事了。

### 1208. Get Equal Substrings Within Budget

[题目](https://leetcode.com/contest/weekly-contest-156/problems/get-equal-substrings-within-budget/)

提交次数：0

这题第一眼看想到了$O(n^2)$的算法，感觉要超时就先放着了（也确实会超。。）

回头看看实际上维护两个指针`l,r`指向首尾即可，对`r`进行累加，当超过了`maxCost`的时候让`l++`就行了，因为是找最大值，中间的状态值是没有重复搜索意义的。

### 1209. Remove All Adjacent Duplicates in String II

[题目](https://leetcode.com/contest/weekly-contest-156/problems/get-equal-substrings-within-budget/)

提交次数：0

后来才看到的题解，本质上其实和括号匹配是一个思路，一个栈维护即可。比赛的时候没细想就跳了。。

### 1210. Minimum Moves to Reach Target with Rotations

[题目](https://leetcode.com/contest/weekly-contest-156/problems/get-equal-substrings-within-budget/)

提交次数：0/1

这种结束后马上ac实在让人很不爽。。虽然本质上还是太菜了。

这题其实很简单，因为蛇只能往右下两个方向走，本质上和那个卒子dp一样，只不过多一个状态而已。

当然我当时直接bfs了，也是能做的。

但是我也不知道为什么要执着于跟STL刚。。刚了一整场还没刚出来太蠢了。



`set`如果想要在其中放自定义结构体的话，需要重载结构体的`<`运算符，告诉set该按怎样的规则排序。

`unordered_set`其实比`set`更费劲，，不仅要重载`==`运算符，而且还要给出结构体的`HASH`方式。

这方面暂时还没搞太清楚，总之先记住少用自己不熟的东西。。