class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        
        int n = nums.size();
        std::vector<vector<int>> res;
        res.reserve(10);
        
        std::function<void(int, vector<int>, int)> backtrack = [&](int i, vector<int> arr, int t) {
            
            // return condition
            if(t == 0) {
                res.emplace_back(arr);
                return;
            }
            if(i >= n || nums[i] > target) {
                return;
            }

            //we can choose to pick it
            // we can further decide how many times to pick it
            // the criteria is the subtracted target must continue to be larger than current
            // or choose to skip it
            
            // we skip it.
            backtrack(i + 1, arr, t);
            
            int num = nums[i];
            while(t >= num) {
                t -= num;
                arr.emplace_back(num);
                // we pick it
                backtrack(i + 1, arr, t);
            }
            
        };

        vector<int> arr;
        arr.reserve(10);
        backtrack(0, arr, target);

        return res;
    }
};
