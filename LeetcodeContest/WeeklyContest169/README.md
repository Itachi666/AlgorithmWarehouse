# Weekly Contest 169

翻车了。。。估计要掉分了。

十来分钟就写完了前三题，结果第四题的搜索还是写炸了，来回调试了估计有1个多小时，细节上还是注意的不够

### 5295. Find N Unique Integers Sum up to Zero

[题目](https://leetcode.com/contest/weekly-contest-169/problems/find-n-unique-integers-sum-up-to-zero/) 

提交次数：1/1

签到题，策略太多了



### 5296. All Elements in Two Binary Search Trees

[题目](https://leetcode.com/contest/weekly-contest-169/problems/all-elements-in-two-binary-search-trees/)

提交次数：1/1

遍历一遍两棵树然后排个序就行了

当然也可以写个中序遍历然后merge，懒得写了hh



### 5297. Jump Game III

[题目](https://leetcode.com/contest/weekly-contest-169/problems/jump-game-iii/)

提交次数：1/1

这题倒是也不难，两个分支的搜索。看讨论说用bfs更好一点，我写的dfs的话还要加个判重，倒是不复杂但是bfs确实舒服。




### 5298. Verbal Arithmetic Puzzle

[题目](https://leetcode.com/contest/weekly-contest-169/problems/verbal-arithmetic-puzzle/)

提交次数：0/0

这题emmm，其实算一算可能性是搜的完的，以防万一考虑了一下优化，决定从个位开始往前顺次搜索，遇到没有对应值的字母就搜索进下一层，result的值是可以从前面推出来的。

思路倒是好想，结果调试各种出问题，总的来说最后找出来的有三个：

- 进位问题：本来只用一个int来存进位，结果如果是回溯的话这个值是没有被存下来的，结果上就导致后面的进位被算在了前面。
- 回溯的时候没有正确清除足迹，这个算我蠢。。
- 可能是最大的bug来源：在一些特定分支上没有在结束后return，导致有些不应该搜索的地方被执行，结果就炸了

来回基本调了一个半小时估计，也算是提个醒吧T T。