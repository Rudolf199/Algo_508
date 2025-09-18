#include <iostream>
#include <vector>

using namespace std;  // плохо

class Solution {
 public:
  int offset(vector<int>& nums) {
    if (nums[0] <= nums.back()) {
      return 0;
    }
    int l = -1;
    int r = nums.size() - 1;
    while (r - l > 1) {
      int m = (r + l) / 2;
      if (nums[m] >= nums.back()) {
        l = m;
      } else {
        r = m;
      }
    }
    return r;
  }
  int search(vector<int>& nums, int target) {
    int ost = offset(nums);
    int l = 0;
    int r = nums.size();
    while (r - l > 1) {
      int m = (r + l) / 2;

      if (nums[(m + ost) % nums.size()] <= target) {
        l = m;

      } else {
        r = m;
      }
    }

    if (nums[(l + ost) % nums.size()] == target) {
      return (l + ost) % nums.size();
    }
    return -1;
  }
};