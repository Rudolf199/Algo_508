#include <iostream>
#include <vector>

/*
Реализация lower, upper bound

В индексах l = 0, r = n если ответ итоговый будет лежать в l

Если в r то l = -1, r = n - 1
*/

bool good_upper(int a, int b) { return a > b; }

bool good_lower(int a, int b) { return a <= b; }
int upper_bound(std::vector<int>& nums, int target) {
  auto r = nums.size() - 1;
  auto l = -1;
  while (r - l > 1) {
    auto m = (r + l) / 2;
    if (good_upper(nums[m], target)) {
      r = m;
    } else {
      l = m;
    }
  }
  if (nums[r] > target) {
    return nums[r];
  }
  return -1;
}

int lower_bound(std::vector<int>& nums, int target) {
  auto r = nums.size();
  auto l = 0;
  while (r - l > 1) {
    auto m = (r + l) / 2;
    if (good_lower(nums[m], target)) {
      l = m;
    } else {
      r = m;
    }
  }
  if (nums[l] <= target) {
    return nums[l];
  }
  return -1;
}

int main() {
  std::vector<int> nums = {1, 2, 3, 3, 5, 8, 12, 13, 14, 17};
  std::cout << upper_bound(nums, 12) << "\n";
  std::cout << lower_bound(nums, 7) << "\n";
  std::cout << lower_bound(nums, 5) << "\n";
  return 0;
}