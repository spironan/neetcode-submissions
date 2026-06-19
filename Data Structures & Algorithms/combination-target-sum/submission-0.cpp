class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        std::vector<vector<int>> res;
        
        vector<int> arr;
        std::function<void(int, vector<int>, int)> backtrack = [&](int i, vector<int> arr, int t) {
            
            //we can choose to pick it
            // we can further decide how many times to pick it
            // the criteria is the subtracted target must continue to be larger than current
            // or choose to skip it
            if(t == 0){
                res.emplace_back(arr);
                return;
            }
            if(i >= n) {
                return;
            }
            int num = nums[i];
            // we skip it.
            backtrack(i + 1, arr, t);
            
            while(t >= num) {
                t -= num;
                arr.emplace_back(num);
                // we pick it
                backtrack(i + 1, arr, t);
            }
            
        };

        backtrack(0, arr, target);

        return res;
    }
};
