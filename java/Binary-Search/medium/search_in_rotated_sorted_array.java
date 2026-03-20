public class search_in_rotated_sorted_array {
    public static void main(String[] args) {
        int [] nums =  {4,5,6,7,0,1,2};
        int target = 4;
        Solution s = new Solution();
        int ans = s.search(nums, target);
        System.out.println("Answer = " + ans);
    }
}

class Solution {
    public int search(int nums[], int target) {
        int st = 0;
        int end = nums.length;

        while (st <= end) {
            int mid = st + (end-st) / 2;

            if(nums[mid] == target) {
                return mid;
            }

            if(nums[st] <= nums[mid]) { // left sorted
                if(nums[st] <= target && target <= nums[mid]) {
                    end = mid-1;
                } else {
                    st = mid+1;
                }
            } else { // right sorted
                if(nums[mid] <= target && target <= nums[end]) {
                    st = mid+1;
                } else {
                    end = mid-1;
                }
            }
        }
        return -1;
    }
}