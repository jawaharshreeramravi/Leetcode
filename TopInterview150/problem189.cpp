/*
189. Rotate Array
Given an integer array nums, rotate the array to the right by k steps, where k
is non-negative.



Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:

Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation:
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]


Constraints:

1 <= nums.length <= 105
-231 <= nums[i] <= 231 - 1
0 <= k <= 105


Follow up:

Try to come up with as many solutions as you can. There are at least three
different ways to solve this problem. Could you do it in-place with O(1) extra
space?
*/

#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
  void rotate(std::vector<int> &nums, int k) {
    int n = nums.size();
    k = k % n;

    std::reverse(nums.begin(), nums.end());
    std::reverse(nums.begin(), nums.begin() + k);
    std::reverse(nums.begin() + k, nums.end());
  }
  // void rotate(std::vector<int> &nums, int k) {
  //   if (!nums.empty()) {
  //     int temp = 0;
  //     for (int i = 0; i < k; i++) {
  //       for (int j = (nums.size() - 1); j >= 0; j--) {
  //         if (j == (nums.size() - 1)) {
  //           temp = nums[nums.size() - 1];
  //           nums[j] = nums[j - 1];
  //         } else if (j == 0) {
  //           nums[j] = temp;
  //         } else {
  //           nums[j] = nums[j - 1];
  //         }
  //       }
  //     }
  //   }
  // }
};

std::ostream &operator<<(std::ostream &os, const std::vector<int> &nums) {
  os << "[";
  for (auto it = nums.begin(); it != nums.end(); ++it) {
    os << *it;
    if (std::next(it) != nums.end()) {
      os << ", ";
    }
  }
  os << "]";
  return os;
}

int main() {
  std::vector<int> nums{1, 2, 3, 4, 5, 6, 7};
  int k = 0;
  std::cout << "Size of nums : " << nums.size() << std::endl;
  std::cout << "Enter the rotate value : ";
  std::cin >> k;
  Solution obj;
  std::cout << "Before Rotate : " << nums << std::endl;
  obj.rotate(nums, k);
  std::cout << "After Rotate : " << nums << std::endl;

  return 0;
}