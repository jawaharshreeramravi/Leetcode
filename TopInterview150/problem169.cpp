/*

169. Majority Element
Easy
Topics
Companies
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You
may assume that the majority element always exists in the array.



Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2


Constraints:

n == nums.length
1 <= n <= 5 * 104
-109 <= nums[i] <= 109


Follow-up: Could you solve the problem in linear time and in O(1) space?
*/

#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
  int majorityElement(std::vector<int> &nums) {
    std::vector<int>::iterator lower;
    std::vector<int>::iterator upper;
    std::sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++) {
      lower = std::lower_bound(nums.begin(), nums.end(), nums[i]);
      upper = std::upper_bound(nums.begin(), nums.end(), nums[i]);

      auto diff = upper - lower;

      if (diff > (nums.size() / 2)) {
        return nums[i];
      }
    }
    return -1;
  }
};

int main() {
  std::vector<int> nums{1, 2, 3, 1, 2, 1, 1, 1};

  Solution obj;

  int result = obj.majorityElement(nums);
  std::cout << "The Majority element is " << result << std::endl;
}