#  11. Container With Most Water

https://leetcode.com/problems/container-with-most-water/solution/

## 题目描述
一个数组，代表高度，数组中每两个元素序号之间的插值代表宽度，找到这组数组能够构成的最大的容器的容积。

## 思路
### Brute Force
两层循环，把所有可能的容积遍历一遍

$$O(n^2)$$

### Two Pointer Approach
左右各有一个 pointer，哪个矮一些，就把哪一个pointer往里面挪一位，直到两个指针汇合。

$$O(n)$$
