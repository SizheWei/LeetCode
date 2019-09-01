# Solutions for Algorithms problems on [Leetcode](https://leetcode.com/problemset/all/)

## Coding Language

Most of the solutions were written in C++. If some problems solved in other kinds of languages, I will list them here.

## Weekly Contest 152

### [Problem 1](https://github.com/SizheWei/LeetCode/tree/master/WeeklyContest_152_1/WeeklyContest_152_1)

Easy

n个数字，按照质数与合数进行重新排序，质数只能放在质数的位置上；问有多少种情况？

solution：遍历，找出有多少个质数（2～n-1是否整除），最后质数个数的阶乘*合数个数的阶乘（阶乘计算用一个循环）

### [Problem 2](https://github.com/SizheWei/LeetCode/tree/master/WeeklyContest_152_2/WeeklyContest_152_2)

Easy, but failed:

一个容器中存放每日消耗的卡路里数，每连续k天消耗卡路里按照+1，0，-1三种表现计分，最后统计分数；

solution：大循环所有天数，小循环每个天数的后k天，统计+1与-1的天数，最后加和为结果。

F：Time Limit Exceeded.

