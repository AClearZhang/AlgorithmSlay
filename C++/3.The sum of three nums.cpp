/*
 * @FilePath            : \AlgorithmSlay\C++\3.The sum of three nums.cpp
 * @Author              : AClearZhang
 * @Date                : 2020-11-19 21:59:12
 * @E-mail              : aclearzhang@qq.com
 * @Homepage            : www.aclear.top
 * @LastEditors         : AClearZhang
 * @LastEditTime        : 2020-11-23 22:37:28
 * @Version             : 1.0
 * @Description         : C++ 实现题目三

给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有满足条件且不重复的三元组。

注意：答案中不可以包含重复的三元组。

 

示例：

给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]
 
 */
#include <iostream>
#include <vector>
#include <windows.h>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      // 三数之和； 关键是边界限制，防止重复！
      // 首先写出算法思想
     
     
      // 首先 无数或者<3返回null
      // 然后 排序数组
      // head = 0
      // 最后：for all
      //         > 0 returen
      //         jump, 

      sort(nums.begin(), nums.end());
      if(nums.empty() || nums.size() < 3){
        return vector<int> [];
      }

    }
};


int main(){
  Solution s;
  vector<int> c = {2, 7, 11, 15};
  vector<int> a = s.twoSum(c, 9);
  for (int i = 0; i < a.size(); i++)
  {
      cout << a[i] << " ";
  }
  printf("Hello World!\n");
  system("pause");
  return 0;
}



// #include <stdio.h>
// #include <iostream>
// #include <vector>
// #include <set>
// #include <algorithm>

// using namespace std;


// /*
//  *   Similar like "Two Number" problem, we can have the simlar solution.
//  *
//  *   Suppose the input array is S[0..n-1], 3SUM can be solved in O(n^2) time on average by 
//  *   inserting each number S[i] into a hash table, and then for each index i and j,  
//  *   checking whether the hash table contains the integer - (s[i]+s[j])
//  *
//  *   Alternatively, the algorithm below first sorts the input array and then tests all 
//  *   possible pairs in a careful order that avoids the need to binary search for the pairs 
//  *   in the sorted list, achieving worst-case O(n^n)
//  *
//  *   Solution:  Quadratic algorithm
//  *   http://en.wikipedia.org/wiki/3SUM
//  *
//  */
// vector<vector<int> > threeSum(vector<int> &num) {

//     vector< vector<int> > result;
//     if(num.size() == 0 || num.size() == 1 || num.size() == 2) return result;

//     //sort the array, this is the key
//     sort(num.begin(), num.end());

//     int n = num.size();

//     for (int i=0; i<n-2; i++) {
//         //skip the duplication
//         if (i > 0 && num[i - 1] == num[i]) continue;
//         int a = num[i];
//         int low = i + 1;
//         int high = n - 1;
//         while (low < high) {
//             int b = num[low];
//             int c = num[high];
//             if (a + b + c == 0) {
//                 //got the soultion
//                 vector<int> v;
//                 v.push_back(a);
//                 v.push_back(b);
//                 v.push_back(c);
//                 result.push_back(v);
//                 // Continue search for all triplet combinations summing to zero.
//                 //skip the duplication
//                 while(low < n - 1 && num[low] == num[low + 1]) low++; 
//                 while(high > 0 && num[high] == num[high - 1]) high--; 
//                 low++;
//                 high--;
//             } else if (a+b+c > 0) {
//                 //skip the duplication
//                 while(high > 0 && num[high] == num[high - 1]) high--;
//                 high--;
//             } else {
//                 //skip the duplication
//                 while(low < n - 1 && num[low] == num[low + 1]) low++;
//                 low++;
//             } 
//         }
//     }
//     return result;
// }

// //using combination method could meet <<Time Limit Exceeded>> error
// vector<vector<int> > combination(vector<int> &v, int k);
// bool isSumZero(vector<int>& v);
// int sum(vector<int>& v);

// vector<vector<int> > threeSum2(vector<int> &num) {
//     vector< vector<int> > result;
//     vector< vector<int> > r = combination(num, 3);
//     for (int i = 0; i < r.size(); i++) {
//         if (isSumZero(r[i])) {
//             result.push_back(r[i]);
//         }
//     }
//     return result;
// }

// bool isSumZero(vector < int>& v) {
//     return sum(v) == 0;
// }

// int sum(vector<int>& v) {
//     int s = 0;
//     for(int i = 0; i < v.size(); i++) {
//         s += v[i];
//     }
//     return s;
// }

// vector<vector<int> > combination(vector<int> &v, int k) {

//     vector<vector<int> > result;
//     vector<int> d;
//     int n = v.size();
//     for (int i = 0; i < n; i++) {
//         d.push_back( (i < k) ? 1 : 0 );
//     }

//     //1) from the left, find the [1,0] pattern, change it to [0,1]
//     //2) move all of the 1 before the pattern to the most left side
//     //3) check all of 1 move to the right
//     while(1) {
//         vector<int> tmp;
//         for(int x = 0; x < n; x++) {
//             if (d[x]) tmp.push_back(v[x]);
//         }
//         sort(tmp.begin(), tmp.end());
//         result.push_back(tmp);
//         //step 1), find [1,0] pattern
//         int i;
//         bool found = false;
//         int ones = 0;
//         for(i = 0; i < n - 1; i++) {

//             if (d[i] == 1 && d[i + 1] == 0) {
//                 d[i] = 0; d[i + 1] = 1;
//                 found = true;
//                 //step 2) move all of right 1 to the most left side
//                 for (int j = 0; j < i; j++) {
//                     d[j] = ( ones > 0 ) ? 1 : 0;
//                     ones--;
//                 }
//                 break;
//             }
//             if (d[i] == 1) ones++;
//         }
//         if (!found) {
//             break;
//         }

//     }
//     return result;
// }


// void printMatrix(vector<vector<int> > &matrix)
// {
//     for(int i = 0; i < matrix.size(); i++) {
//         printf("{");
//         for(int j = 0; j < matrix[i].size(); j++) {
//             printf("%3d ", matrix[i][j]) ;
//         }
//         printf("}\n");
//     }
//     cout << endl;
// }


// int main()
// {
//     //int a[] = { -1, 0, 1, 2, -1, 1, -4 };
//     int a[] = { -1, 1, 1, 1, -1, -1, 0,0,0 };
//     vector<int> n(a, a + sizeof(a)/sizeof(int));
//     vector< vector<int> > result = threeSum(n);
//     printMatrix(result);    
//     return 0;
// }