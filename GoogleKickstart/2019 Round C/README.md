# Round C - Kick Start 2019 

[https://codingcompetitions.withgoogle.com/kickstart/round/0000000000050ff2](https://codingcompetitions.withgoogle.com/kickstart/round/0000000000050ff2)

## Wiggle Walk

### Problem

Banny has just bought a new programmable robot. Eager to test his coding skills, he has placed the robot in a grid of squares with **R** rows (numbered 1 to **R** from north to south) and **C** columns (numbered 1 to **C** from west to east). The square in row r and column c is denoted (r, c).

Initially the robot starts in the square (**SR**, **SC**). Banny will give the robot **N** instructions. Each instruction is one of `N`, `S`, `E` or `W`, instructing the robot to move one square north, south, east or west respectively.

If the robot moves into a square that it has been in before, the robot will continue moving in the same direction until it reaches a square that it *has not* been in before. Banny will never give the robot an instruction that will cause it to move out of the grid.

Can you help Banny determine which square the robot will finish in, after following the **N** instructions?

### Input

The first line of the input gives the number of test cases, **T**. **T** test cases follow. Each test case starts with a line containing the five integers **N**, **R**, **C**, **SR** and **SC**, the number of instructions, the number of rows, the number of columns, the robot's starting row and starting column, respectively.

Then, another line follows containing a single string of **N** characters; the i-th of these characters is the i-th instruction Banny gives the robot (one of `N`, `S`, `E` or `W`, as described above).

### Output

For each test case, output one line containing `Case #x: r c`, where `x` is the test case number (starting from 1), `r` is the row the robot finishes in and `c` is the column the robot finishes in.

### Limits

Memory limit: 1GB.
1 ≤ **T** ≤ 100.
1 ≤ **R** ≤ 5 × 104.
1 ≤ **C** ≤ 5 × 104.
1 ≤ **SR** ≤ **R**.
1 ≤ **SC** ≤ **C**.
The instructions will not cause the robot to move out of the grid.

#### Test set 1 (Visible)

Time limit: 20 seconds.
1 ≤ **N** ≤ 100.

#### Test set 2 (Hidden)

Time limit: 60 seconds.
1 ≤ **N** ≤ 5 × 104.

### Sample

**Input**

```
3
5 3 6 2 3
EEWNS
4 3 3 1 1
SESE
11 5 8 3 4
NEESSWWNESE
```

**Output**

```
Case #1: 3 2
Case #2: 3 3
Case #3: 3 7
```

Sample Case #1 corresponds to the top-left diagram, Sample Case #2 corresponds to the top-right diagram and Sample Case #3 corresponds to the lower diagram. In each diagram, the yellow square is the square the robot starts in, while the green square is the square the robot finishes in. 

![image](https://tva4.sinaimg.cn/mw690/890e0d7bly1g93bdpdykkj20vn0o4gm8.jpg)

#### Analysis

##### Test set 1 (Visible)

Approaching the problem naively, one might try to simply simulate what has been mentioned in the problem statement i.e. keep on moving the robot in the specified direction till it reaches an un-visited square. This approach is going to have a time complexity of O(**N**2), which although good enough for test set 1.

##### Test set 2 (Hidden)

The problem with the above approach is that it visits a lot of already visited squares which in worst case will be all the previously visited squares (Consider the input where you are given alternating `E` and `W` throughout). If we somehow get to the destination square for each instruction faster, we might be able to reduce the complexity.

Let's say the robot is in some row r and received an instruction `W`. Now, all the already visited squares (if any) it will pass before reaching an unvisited square have to form a contiguous interval in row r. This suggests that we may use intervals to represent all the visited squares in the same row.

With that in mind, consider we have a [set](https://en.wikipedia.org/wiki/Set_(abstract_data_type)) of intervals for each row and each column of the grid to represent which cells have been visited in that particular row or column, let's call them interval-sets. Initially, all these sets are empty except for the set corresponding to row **SR**, which has a single interval (**SC**, **SC**), and the set corresponding to the column **SC**, which has a single interval (**SR**, **SR**).

Now, using this data-structure, let's try to find the destination square for the robot. Let's say it's in square (r, c) and got an instruction `W`. For this, first we search in the interval-set corresponding to row r. We will try to find which interval in this set contains c (there must definitelty be one!). Once we find it, we immediately know what's going to be the new position for the robot! It's apparent that the same method works for all other directions as well.

All that remains now is to find a way to update our data-structure suitably to also include the newly visited square. This can be done in a very standard manner by simply finding the adjacent intervals for that square in both, the corresponding column interval-set and the corresponding row interval-set and then updating them either by extending one of the intervals or merging them or adding a new 1 length interval.

Since we add at most one interval in each case, the number of intervals is O(**N**). Since all operations are about finding/inserting/removing a single interval, all of those can be handled easily in O(log(**N**)) time. So the over all run time of this approach is O(**N**log(**N**)). There is also a O(**N**) solution to this problem using hash tables. It is left as an exercise to the reader.

## Teach me





## Catch Some

### Problem

Bundle is an animal researcher and needs to go observe **K** dogs. She lives on a horizontal street marked at metre increments with consecutive numbers 0, 1, 2, 3 and so on. She begins in her home, which is at position 0. There are also **N** dogs on the street. The i-th dog is **Pi** metres to the right of her home on the street (multiple dogs can share the same position).

Dogs come in different colors, which are denoted by positive integers. The i-th animal is of color **Ai**.

If Bundle is at her home, she can change the current color of her shirt. This is important since the dogs are very shy! Bundle can only observe a dog if she is at the same position as that dog, and is wearing a shirt of the same color as the dog.

It takes Bundle one second to move one metre to the left or right on the street. It takes her no time to change shirts or observe a dog.

What is the least amount of time it will take Bundle to observe **K** dogs? Note that she *does not* have to return home after observing **K** dogs.

### Input

The first line of the input gives the number of test cases, **T**. **T** test cases follow. Each testcase begins with a line containing the two integers **N** and **K**, the number of dogs on the number line and the number of dogs Bundle needs to observe, respectively. The second line contains **N** integers, the i-th of which is **Pi**, the position of the i-th dog. The third line contains **N** integers, the i-th of which is **Ai**, the color of the i-th dog.

### Output

For each test case, output one line containing `Case #x: y`, where `x` is the test case number (starting from 1) and `y` is the least time Bundle needs to observe **K** dogs.

### Limits

Time limit: 30 seconds per test set.
Memory limit: 1GB.
1 ≤ **T** ≤ 100.
1 ≤ **K** ≤ **N**.
1 ≤ **Ai** ≤ 1000.
1 ≤ **Pi** ≤ 105.

#### Test set 1 (Visible)

1 ≤ **N** ≤ 50.

#### Test set 2 (Hidden)

1 ≤ **N** ≤ 1000.

### Sample

**Input**

```
3
4 3
1 2 4 9
3 3 2 3
4 3
1 2 3 4
1 8 1 8
6 6
4 3 3 1 3 10000
1 2 8 9 5 7
```

**Output**

```
Case #1: 8
Case #2: 6
Case #3: 10028
```

In Sample Case #1, there are **N** = 4 dogs and Bundle needs to observe **K** = 3 dogs. One way that she can achieve this is as follows:

- Put on a shirt of color 3.
- Move one metre to the right and observe the dog there.
- Move one metre to the right again and observe the dog there.
- Move two metres to the left, returning to her home.
- Change into a shirt of color 2.
- Move four metres to the right and observe the dog there.

In total, this takes Bundle 8 seconds which is the least time possible, so the answer is 8.



In Sample Case #2, there are **N** = 4 dogs and Bundle needs to observe **K** = 3 dogs. One way that she can achieve this is as follows:

- Put on a shirt of color 1.
- Move one metre to the right and observe the dog there.
- Move one metre to the left, returning to her home.
- Change into a shirt of color 2.
- Move two metres to the right and observe the dog there.
- Move two metres to the right again and observe the dog there. Note that Bundle is unable to observe the dog she passes at position 3, since her shirt is the wrong color (even though she was wearing the right colored shirt previously).

In total, this takes Bundle 6 seconds which is the least time possible, so the answer is 6.



In Sample Case #3, note that:

- Multiple dogs can share the same position and
- Dogs are not necessarily given in ascending order of position.

No explanation is provided for the answer to this case.