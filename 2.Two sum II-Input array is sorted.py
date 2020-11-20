'''
   @FilePath            : \AlgorithmSlay\2.Two sum II-Input array is sorted.py
   @Author              : AClearZhang
   @Date                : 2020-11-17 14:57:21
   @E-mail              : aclearzhang@qq.com
   @Homepage            : www.aclear.top
   @LastEditors         : AClearZhang
   @LastEditTime        : 2020-11-20 20:31:33
   @Version             : 1.0
   @Description         : 数组刷题
'''
# 题目描述
# 给定一个已按照升序排列 的有序数组，找到两个数使得它们相加之和等于目标数。

# 函数应该返回这两个下标值 index1 和 index2，其中 index1 必须小于 index2。

# 说明:

# 返回的下标值（index1 和 index2）不是从零开始的。
# 你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。
# 示例:

# 输入: numbers = [2, 7, 11, 15], target = 9
# 输出: [1,2]
# 解释: 2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。
from typing import List
class Solution:
    '''
       @description: 
       @param {*} self
       @param {List} numbers
       @param {int} target
       @return {*}
       @notes: 
    '''
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        head = 0
        tail = len(numbers) - 1
        sum_two = numbers[head] + numbers[tail]
        while sum_two != target:
            if sum_two > target:
                tail -= 1
            elif sum_two < target:
                head += 1
            sum_two = numbers[head] + numbers[tail]

        return [head+1, tail+1]





if __name__ == "__main__":
    a = Solution()
    print(a.twoSum([2, 7, 11, 15], 9))