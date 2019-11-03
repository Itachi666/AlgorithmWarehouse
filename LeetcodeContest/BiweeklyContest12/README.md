# Biweekly Contest 12

最近两次的双周赛都做的不是很顺，在Q3上纠结了太久。

### 1243. Array Transformation 

[题目](  https://leetcode.com/contest/biweekly-contest-12/problems/array-transformation/ )

提交次数：1/2

签到题，然后就跪了emmm，一开始直接遍历数组然后判断操作的，结果发现前面的改动会影响后面就很难受。改成标记那些位置会改变，然后一起改就好了。

当然直接vector复制一个然后复制回去也可以，，，蠢了。

### 1244. Design A Leaderboard  

[题目](  https://leetcode.com/contest/biweekly-contest-12/problems/design-a-leaderboard/  )

提交次数：1/1

这题目读的是真费劲。

第一眼感觉要用数据结构，结果不知道为什么觉得n2的算法不行，非要往下找。现在看看数据范围用n2暴力算法是完全够用的。。。

但用两个map来写是可以的，一开始想到了这个但是有一点没想通就搁着写后面的了。思路很简单：一个map来存每个人的成绩，第二个map来存成绩。靠map自带的有序属性来获取最大的K个成绩。

好像每个人的成绩用vector也够用了

### 1245. Tree Diameter  

[题目]( https://leetcode.com/contest/biweekly-contest-12/problems/tree-diameter/  )

提交次数：1/5

看评论说是模版题，就有点尴尬了。

最开始写dfs暴力搜索每个叶子节点的最长，想了半天怎么去重也没去掉，最后果不其然超时了，关键超时就算了还试图优化一下想混过去。。。5min啊5min

后来转换了一下思路，每一轮中扫描所有的节点，每一次把叶子节点删掉，删到只剩下一个或者两个节点为止，这时的轮数就是他的半径。



当然dfs其实也是可以的，参考了一下大佬的方法， 思路很简单：找到距离0号节点最远的节点，然后从这个节点出发找到距离这个节点的最远节点，就是直径。

这个思路就好很多，想了想哪怕这是个图也可以解决。

附代码：

```c++
class Solution {
    vector<vector<int>> w;
    pair<int,int> best;
    void dfs(int a, int par, int len) {
        best = max(best, make_pair(len, a));
        for(int b : w[a]){ 
            if(b != par) {
                dfs(b, a, len + 1);
            }
        }
    }
public:
    int treeDiameter(vector<vector<int>>& edges) {
        int n = (int) edges.size() + 1;
        w.clear();
        w.resize(n + 1);
        for(int i = 0; i < n - 1; ++i) {
            int a = edges[i][0];
            int b = edges[i][1];
            w[a].push_back(b);
            w[b].push_back(a);
        }
        best = {-1, -1};
        dfs(0, -1, 0);
        int from = best.second;
        best = {-1, -1};
        dfs(from, -1, 0);
        return best.first;
    }
};
```



### 1246. Palindrome Removal 

[题目]( https://leetcode.com/contest/biweekly-contest-12/problems/palindrome-removal/  )

提交次数：0/0

区间dp还是不太熟练。

第三题浪费了太久，到第四题的时候时间已经不多了，看见数据范围100鬼使神差的就想搞个四重循环，当时都觉得自己失了智。

其实有点被题目误导，想法是这样的：首先两层循环确定区间长度和区间首尾，然后枚举内部区间，判断把这个区间删了之后剩下的是不是个回文串。

emmmm总之没调出来，后来还是参考了一下题解才搞定的：

其实就是个比较标准的区间dp，把一个区间拆成两个区间就可以了，然后判断一下首尾是否相同即可。

