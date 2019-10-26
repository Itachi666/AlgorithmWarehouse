# Weekly Contest 159

两次第四题都没啥思路还都在前面耽误了很久，心态有点爆炸。知道了google的Kickstart，下个月是今年的最后一次了怎么也得参加一下。

### 1232.  Check If It Is a Straight Line 

[题目]( https://leetcode.com/contest/weekly-contest-159/problems/check-if-it-is-a-straight-line/ ) 

提交次数：1/1

签到题，比较每个点到第一个点的斜率就好了。



### 1233. Remove Sub-Folders from the Filesystem 

[题目]( https://leetcode.com/contest/weekly-contest-159/problems/remove-sub-folders-from-the-filesystem/ )

提交次数：1/1

刚开始以为是字典树心里一慌，后来仔细一看其实只是个前缀罢了。而且好像排序之后能写的更简单点。。

刚开始没排序，结果就一直有各种小问题，包括各种结尾斜杠之类的，还是自己调了一会才搞定。感觉还是不能太贪快，做出来最主要。



### 1234. Replace the Substring for Balanced String 

[题目]( https://leetcode.com/contest/weekly-contest-159/problems/replace-the-substring-for-balanced-string/ )

提交次数：1/4

这种交好几次没过人就不会很好。。

刚开始思路是既然只能替换一次，那么先把两边的符合条件的去掉，之后再对中间具体看应该替换几个。

然后到中间就发现问题非常多，最开始的思路忘了具体是什么样的了总之很暴力，结果样例证明思路是错的。。

然后就突然想到了滑动窗口，尝试了一下之后感觉可行，但又被下标和什么时候首部加什么时候尾部加等纠结半天，最后调了快一个小时才搞定。交的时候还虚的不行。

感觉要多练练角标的问题，吃亏不止一次了。



### 1235. Maximum Profit in Job Scheduling 

[题目]( https://leetcode.com/problems/maximum-profit-in-job-scheduling/ )

提交次数：0

从讨论里get到了dp思路。

一个区间必然是接在某个区间后面，也就是某个endTime后面。也即是说，在准备计算第i个区间的时候，需要完成所有endTime在该区间之前的区间的计算。然后很容易想到的是遍历这个区间前面所有的endTime，找到最大值加上当前区间来归入这个区间的endTime。这样的时间复杂度是$O(n^2)$，肯定是不行的。

那么需要转换思路。首先需要的是将time离散化，开一个map来存储所有的endTime即可，非endTime中的时间点实际没有什么存在意义。其次是`times[i]`的含义，这里应该记录的是在时间`i`之前的区间最大值，也即是说times是一个升序数组。

这样思路就出来了：

- 离散化endTime，将区间按照endTime大小进行排序。
- endTime从小开始遍历所有区间，对每一个区间，找到endTimes中小于等于区间startTime的最大的那个，加上自己的profile后取大值返回给`times[endTime]`

