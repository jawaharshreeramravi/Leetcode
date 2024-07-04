/*
55. Jump Game
You are given an integer array nums. You are initially positioned at the array's
first index, and each element in the array represents your maximum jump length
at that position.

Return true if you can reach the last index, or false otherwise.



Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump
length is 0, which makes it impossible to reach the last index.


Constraints:

1 <= nums.length <= 104
0 <= nums[i] <= 105
*/

#include <iostream>
#include <vector>

class Solution {
public:
  bool canJump(std::vector<int> &nums) {
    if (nums.size() == 1) {
      return true;
    }
    int i = 0;
    int jump = 0;
    do {
      jump = nums[i];
      if (jump != 0) {
        i = i + jump;
        if (i == (nums.size() - 1)) {
          return true;
        }
      } else {
        break;
      }
    } while (i < nums.size());
    return false;
  }
};

int main() {
  Solution obj;

  std::vector<int> nums1 = {2, 0, 1, 4, 1, 2, 3, 2, 5};
  std::cout << "Can jump to the last index (Example 1): "
            << (obj.canJump(nums1) ? "Yes" : "No") << std::endl;

  std::vector<int> nums2 = {3, 2, 1, 0, 4};
  std::cout << "Can jump to the last index (Example 2): "
            << (obj.canJump(nums2) ? "Yes" : "No") << std::endl;

  return 0;
}