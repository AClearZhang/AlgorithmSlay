/*
 * @FilePath            : \Algorithm&Interview\AlgorithmSlay\C++\319.BulbSwitcher.cpp
 * @Author              : AClearZhang
 * @Date                : 2021-03-09 17:43:39
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2021-03-09 17:44:09
 * @Version             : 1.0
 * @Description         : 灯泡开关I
 *319. 灯泡开关
初始时有 n 个灯泡处于关闭状态。

对某个灯泡切换开关意味着：如果灯泡状态为关闭，那该灯泡就会被开启；而灯泡状态为开启，那该灯泡就会被关闭。

第 1 轮，每个灯泡切换一次开关。即，打开所有的灯泡。

第 2 轮，每两个灯泡切换一次开关。 即，每两个灯泡关闭一个。

第 3 轮，每三个灯泡切换一次开关。

第 i 轮，每 i 个灯泡切换一次开关。 而第 n 轮，你只切换最后一个灯泡的开关。

找出 n 轮后有多少个亮着的灯泡。

 

示例 1：



输入：n = 3
输出：1 
解释：
初始时, 灯泡状态 [关闭, 关闭, 关闭].
第一轮后, 灯泡状态 [开启, 开启, 开启].
第二轮后, 灯泡状态 [开启, 关闭, 开启].
第三轮后, 灯泡状态 [开启, 关闭, 关闭]. 

你应该返回 1，因为只有一个灯泡还亮着。
示例 2：

输入：n = 0
输出：0
示例 3：

输入：n = 1
输出：1 
 */
#include <math.h>

class Solution {
public:
    int bulbSwitch(int n) {
        return sqrt(n);
    }
};
