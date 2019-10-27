# Weekly Contest 160

这次数据范围是真的小。另外因为第四题太蠢意外进了前200。。。。

### 1237.  Find Positive Integer Solution for a Given Equation

[题目]( https://leetcode.com/contest/weekly-contest-160/problems/find-positive-integer-solution-for-a-given-equation/   ) 

提交次数：1/1

签到题，一个二维单调函数`f(x,y)`找出所有`f(x,y)=z`的输入`(x,y)`，其实提高效率对每个x，二分y就可以了应该。但范围实在太小就直接暴力了。。



### 1238.  Circular Permutation in Binary Representation   

[题目]( https://leetcode.com/contest/weekly-contest-160/problems/circular-permutation-in-binary-representation/  )

提交次数：1/1

参见leetcode的[第89题](https://leetcode.com/problems/gray-code/)，找到这样的顺序之后把输入的start提前到最开始就可以了。

人生就是一个环hhh



### 1239. Replace the Substring for Balanced String 

[题目]( https://leetcode.com/contest/weekly-contest-160/problems/maximum-length-of-a-concatenated-string-with-unique-characters/ )

提交次数：1/2

数据范围太小了，总共就16个，不暴力实在不是人。。

被坑了一次，没考虑到一个字符串内部可能就会有重复。



### 1240. Tiling a Rectangle with the Fewest Squares

[题目]( https://leetcode.com/contest/weekly-contest-160/problems/tiling-a-rectangle-with-the-fewest-squares/ )

提交次数：1/2

目前做过的最蠢的第四题。。前面那一堆骗分的你们好意思么。

看起来是个dp，实际也是dp，但是测试样例非要搞个幺蛾子让人觉得不是dp。

但实际上就是dp，最后那个测试样例是个特例，就是误导人的emmm从结果上来看这个误导效果真的很好。。。