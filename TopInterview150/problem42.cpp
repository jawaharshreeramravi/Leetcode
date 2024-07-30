/*
42. Trapping Rain Water
Given n non-negative integers representing an elevation map where the width of
each bar is 1, compute how much water it can trap after raining.

Example 1:

Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array
[0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section)
are being trapped. Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9


Constraints:

n == height.length
1 <= n <= 2 * 104
0 <= height[i] <= 105
*/

#include <iostream>
#include <vector>

int trap(std::vector<int> &height) {
  int left = 0, right = height.size() - 1;
  int left_max = 0, right_max = 0;
  int result = 0;

  while (left < right) {
    if (height[left] < height[right]) {
      if (height[left] >= left_max)
        left_max = height[left];
      else
        result += left_max - height[left];
      left++;
    } else {
      if (height[right] >= right_max)
        right_max = height[right];
      else
        result += right_max - height[right];
      right--;
    }
  }

  return result;
}

int main() {
  std::vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  std::cout << "Trapped water: " << trap(height) << std::endl;
  return 0;
}
