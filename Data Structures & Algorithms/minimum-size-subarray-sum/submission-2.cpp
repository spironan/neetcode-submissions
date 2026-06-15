class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, r = 0;
        int n = nums.size();
        int minLength = n + 1;

        int runningSum = 0;
        for(int r = 0; r < n; ++r) {
            runningSum += nums[r];
            while(runningSum >= target) {
                minLength = min(r - l, minLength);
                runningSum -= nums[l++];
            }
        }


        return minLength > n ? 0 : minLength + 1;
    }
};