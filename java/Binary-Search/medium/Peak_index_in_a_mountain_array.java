
public class Peak_index_in_a_mountain_array {
    public static void main(String[] args) {
        int[] nums = { 0, 1, 5, 8, 9, 5, 2 };
        Solution1 s = new Solution1();
        int ans = s.peakIndexInMountainArray(nums);
        System.out.println("Ans = " + ans);
    }
}

class Solution1 {
    public int peakIndexInMountainArray(int[] nums) {
        int st = 1, end = nums.length - 2;
        while (st <= end) {
            int mid = st + (end - st) / 2;
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