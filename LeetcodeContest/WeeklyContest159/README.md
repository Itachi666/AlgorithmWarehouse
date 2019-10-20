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

写了个暴力DP结果是超时的，暂时没思路。