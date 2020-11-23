/*
 * @FilePath            : \AlgorithmSlay\C++\1.TwoSum.cpp
 * @Author              : AClearZhang
 * @Date                : 2020-11-22 22:57:29
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2020-11-23 20:23:57
 * @Version             : 1.0
 * @Description         : 两数之和  C++
 * 
 * 给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。

 

示例:

给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/two-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 * 
 */
#include <iostream>
#include <map>
#include <vector>
#include <windows.h>

using namespace std;

//方法一 暴力法：
class Solution1
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    { // &代表C++的引用
        int i, j;
        for (i = 0; i < nums.size() - 1; i++)
        {
            for (j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    return {i, j};
                }
            }
        }
        return {i, j};
    };
};
//方法二： 两边哈希表
// value存放索引，key 存放实际数值.
class Solution2
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        map<int, int> valueKey;
        vector<int> answer(2, -1); //最初返回值，初始化为 -1的容器
        for (int i = 0; i < nums.size(); i++)
        {
            //插入 map
            valueKey.insert(pair<int,int>(nums[i],i));
        }
        //再一遍索引遍历有没有
        for (int j = 0; j < nums.size(); j++)
        {
            if (valueKey.count(target - nums[j]) > 0 && valueKey[target - nums[j]] != j)
            {
                //存在这个key值，且不与自己重复则找到了
                answer[0] = j;
                answer[1] = valueKey[target - nums[j]];
                return answer;
            }
        }
        return answer;
    }
};

//方法三 一遍哈希表：即使用map 索引。减少时间复杂度
// 教我们如何用哈希表处理问题、
// 改进：在进行迭代并将元素插入到表中的同时，我们还会回过头来检查表中是否已经存在当前元素所对应的目标元素。如果它存在，那我们已经找到了对应解，并立即将其返回。
class Solution3
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        map<int, int> a;      //提供一对一的hash
        vector<int> b(2, -1); //用来承载结果，初始化一个大小为2，值为-1的容器b
        for (int i = 0; i < nums.size(); i++)
        {
            if (a.count(target - nums[i]) > 0)
            {
                b[0] = a[target - nums[i]];  //注意 两边哈希和一遍哈希不一样！ 这里！//因为这里是反着的.
                b[1] = i;
                break;
            }
            a[nums[i]] = i; //反过来放入map中，用来获取结果下标
        }
        return b;
    };
};

int main()
{

    Solution2 s;
    vector<int> c = {2, 7, 11, 15};
    vector<int> a = s.twoSum(c, 9);
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    system("pause");
    return 0;
}
