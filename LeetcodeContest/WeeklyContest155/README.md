# Weekly Contest 155

### 1201. Minimum Absolute Difference

[题目](https://leetcode.com/contest/weekly-contest-155/problems/minimum-absolute-difference/) 

提交次数：1/1

这题没什么好说的，签到题。排序之后记录最小间隔就行了



### 1202. Ugly Number III

[题目](https://leetcode.com/contest/weekly-contest-155/problems/ugly-number-iii/)

提交次数：0

得说这个题目看着头疼，，之前的Ugly Number II有极大的误导性，一开始看感觉一点思路都没有。最后看着三个or推了一下突然意识到不就是容斥原理么。然而时间不太够了没调出来。



### 1203. Smallest String With Swaps

[题目](https://leetcode.com/contest/weekly-contest-155/problems/smallest-string-with-swaps/)

提交次数：1/2

看见无限次交换就感觉应该和这个交换没啥关系了，最后果然是并查集。按能否交换把字母分成几个组，每个组排序即可。

最开始想简单了，每一个组都从全局搜出来排序再放回去，直接超时了，，后来又调了半天搞定，一个题用了一个小时实在不应该。

贴一个大佬的代码，简洁很多思路也清楚，不用像我一样费那么多乱七八糟的工夫去把每个集合取出来排序放回去。

```c++
const int MAXN = 100010;

int F[MAXN];

int father(int x)
{
    return F[x] == x ? x : F[x] = father(F[x]);
}

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        for (int i = 0; i < n; ++ i) F[i] = i;
        for (auto e : pairs)
        {
            int x = e[0], y = e[1];
            F[father(x)] = father(y);
        }
        vector<vector<char>> v(n);
        for (int i = 0; i < n; ++ i)
        {
            v[father(i)].push_back(s[i]);
        }
        for (int i = 0; i < n; ++ i)
        {
            sort(v[i].begin(), v[i].end());
            reverse(v[i].begin(), v[i].end());
        }
        string t;
        for (int i = 0; i < n; ++ i)
        {
            t += v[father(i)].back();
            v[father(i)].pop_back();
        }
        return t;
    }
};
```

### 1204. Sort Items by Groups Respecting Dependencies

[题目](https://leetcode.com/contest/weekly-contest-155/problems/sort-items-by-groups-respecting-dependencies/)

提交次数：0

emmm主要是没时间做，也是后来才补上的。当时感觉这种有依赖的排序应该是有算法的，查了查果然是**拓扑排序**。知道了算法其实不难，一个小处理就是吧所有的`-1`组都单独分成一组，这样在Group进行拓扑排序的时候可以不用单独处理了。