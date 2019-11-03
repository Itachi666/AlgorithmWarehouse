# Weekly Contest 161

这回意外进前200了还是挺开心的（虽然是压线198），吃饭都香了2333

### 1247. Minimum Swaps to Make Strings Equal 

[题目](https://leetcode.com/contest/weekly-contest-161/problems/minimum-swaps-to-make-strings-equal/ ) 

提交次数：1/1

意外卡的最久，改了好几次思路。一开始以为只要统计出x和y的数量然后除以2就行了，后来发现不是。

总之纠结了一会发现只要首先找到若干的`xx`和`yy`对，最后看剩下的是不是个`xy&yx`对即可。



### 1248. Count Number of Nice Subarrays    

[题目]( https://leetcode.com/contest/weekly-contest-161/problems/count-number-of-nice-subarrays/)

提交次数：1/1

这一题猛一看还觉得有点难，仔细一看k给定了那就挺水的了：把奇数位置存起来，然后用一个长度为k的窗口扫一遍，判断有多少个就可以了。



### 1249. Minimum Remove to Make Valid Parentheses 

[题目](https://leetcode.com/contest/weekly-contest-161/problems/minimum-remove-to-make-valid-parentheses/ )

提交次数：1/1

括号匹配加强版。

匹配途中把多余的括号位置记录下来，然后在字符串中挨个删掉就行了。



### 1250. Check If It Is a Good Array 

[题目]( https://leetcode.com/contest/weekly-contest-161/problems/check-if-it-is-a-good-array/ )

提交次数：1/1

一开始看见选择任意子集还有点吓人，感觉跟最大公约数相关就先写了个gcd上去，甚至还调试了调试浪费了几分钟。。。

然后一看就返回个bool，那不就是看全数组的最大公约数是不是1么。。。

