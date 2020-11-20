'''
   @FilePath            : \AlgorithmSlay\3.The sum of three nums.py
   @Author              : AClearZhang
   @Date                : 2020-11-19 21:55:24
   @E-mail              : aclearzhang@qq.com
   @Homepage            : www.aclear.top
   @LastEditors         : AClearZhang
   @LastEditTime        : 2020-11-20 21:19:48
   @Version             : 1.0
   @Description         :  注意以下题干描述

    给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有满足条件且不重复的三元组。
    注意：答案中不可以包含重复的三元组。
    示例：

    给定数组 nums = [-1, 0, 1, 2, -1, -4]，

    满足要求的三元组集合为：
    [
    [-1, 0, 1],
    [-1, -1, 2]
    ]

'''
from typing import List
# class Solution:
#     '''
#        @description: 
#        @param {*} self
#        @param {List} nums
#        @return {*}
#        @notes: 寻找三元组。返回下标
#     '''
#     def threeSum(self, nums: List[int]) -> List[List[int]]:
#         # 先排序 再双指针寻找
#         # sort_num = sorted(range(len(nums)),key=lambda k: nums[k])
#         sort_num = sorted(nums)
#         answer = []
#         # answer = ()
#         head = 0
#         # tail = len(nums) - 1
#         while head < len(nums) - 2:
#             tail = len(nums) - 1
#             if head!=0 and sort_num[head] == sort_num[head-1]: #多次添加
#                 head+=1
#                 while sort_num[head] == sort_num[head-1] and head!=tail-1:
#                     head+=1
#             while tail > head + 1:
               
#                 if (tail!=len(nums)-1) and sort_num[tail] == sort_num[(tail+1)%len(nums)]:
#                     tail -= 1
#                     while sort_num[tail] == sort_num[(tail+1)%len(nums)] and tail!=head+1:
#                         tail -= 1
#                 #print("now head:{},tail:{}, sort_num:{}, answer:{}".format(head,tail, sort_num, answer))
#                 other = 0 - (sort_num[head] + sort_num[tail])
#                 if other > 0:
#                     mid = tail - 1
#                     while mid != head:
#                         if sort_num[mid] < other:
#                             # 无了
#                             tail = tail - 1
#                             break
#                         elif sort_num[mid] > other:
#                             mid = mid - 1
#                         elif sort_num[mid] == other:
#                             # 对了
#                             answer.append([sort_num[head], sort_num[mid], sort_num[tail]])
#                            # print(answer)
#                             tail = tail - 1
#                             break
#                 elif other < 0:
#                     mid = head + 1
#                     while mid != tail:
#                         if sort_num[mid] < other:
#                             mid+=1
#                         elif sort_num[mid] > other:
#                             # 无了
#                             tail-=1
#                             break
#                         elif sort_num[mid] == other:
#                             # 对了
#                             answer.append([sort_num[head], sort_num[mid], sort_num[tail]])
#                             #print(answer)
#                             tail-=1
#                             break
#                 elif other == 0:
#                     mid = head + 1
#                     while mid != tail:
#                         if sort_num[mid] == 0:
#                             answer.append([sort_num[head], 0, sort_num[tail]])
#                             #print(answer)
#                             # tail-=1
#                             break
#                         mid+=1
#                     tail-=1
#             head+=1
#         return answer


# Solution2：
# 关键之处在于边界，以及去重
from typing import List
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        if( not nums or n < 3):
            return []
        res = []
        sort_num = sorted(nums)
        for i,v in enumerate(sort_num):
            if(sort_num[i] > 0): # 遗漏了！如果当前数字大于0，则三数之和一定大于0，所以结束循环
                return res
            if i >= 1 and sort_num[i] == sort_num[i-1]: #去重
                continue
            L = i+1; R = n-1
            while L<R:
                sum = sort_num[i] + sort_num[L] + sort_num[R]
                if sum == 0:
                    res.append([sort_num[i], sort_num[L], sort_num[R]])
                    # 去重并寻找下一个不是次数的数值
                    L+=1; R-=1; # 可以这样 因为排好序了，已经不可能只移动一边了！ YES！
                    while(L<R and sort_num[L] == sort_num[L-1]): L+=1
                    while(R>L and sort_num[R] == sort_num[R+1]): R-=1
                elif sum>0:
                    R-=1
                elif sum < 0 :
                    L+=1

                # # 去重L&R
                # while(L<R and sort_num[L+1] == sort_num[L]): L+=1
                # while(L<R and sort_num[R    -1] == sort_num[R]): R-=1
                # sum = sort_num[i] + sort_num[L] + sort_num[R]
                # if sum==0:
                #     res.append([sort_num[i],sort_num[L],sort_num[R]])
                # elif sum > 0:
                #     R-=1
                # elif sum < 0:
                #     L+=1
        return res
                





if __name__ == "__main__":
    a = Solution()
    # print(a.threeSum([-1,0,1,2,-1,-4]))
    # print(a.threeSum([0,0,0,0]))
    print(a.threeSum([1,0, -1]))
    # print(a.threeSum([-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6]))


