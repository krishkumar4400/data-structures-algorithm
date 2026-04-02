class Solution {
  peakIndexInMountainArray(nums) {
    let st = 1;
    let end = nums.length - 2;
    while (st <= end) {
      let mid = Math.floor(st + (end - st) / 2);
      if (nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1]) {
        return mid;
      } else if (nums[mid - 1] < nums[mid]) {
        st = mid + 1;
      } else {
        end = mid - 1;
      }
    }
    return -1;
  }
}

const nums = [0, 1, 15, 8, 9, 5, 2];
const s = new Solution();

const ans = s.peakIndexInMountainArray(nums);
console.log(ans);
