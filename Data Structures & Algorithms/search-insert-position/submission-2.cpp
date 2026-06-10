class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int sz = nums.size();
        int l = 0;
        int r = nums.size();
        int m = (l + r)/2;
        while(nums[m] != target) {
            // if target is bigger than current
            if(target > nums[m]) {
                if((m + 1) >= sz || target < nums[m + 1])
                    return m + 1;
                l = m;
            } else { // target is smaller than or equal current.
                if((m - 1) < 0 || target > nums[m - 1])
                    return m;
                r = m;
            }
            m = (l + r)/2;
        }

        return m;
    }
};