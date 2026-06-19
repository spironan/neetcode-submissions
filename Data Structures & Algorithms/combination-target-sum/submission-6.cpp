class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        std::vector<vector<int>> res;
        vector<int> arr;
        
        std::function<void(int, int)> backtrack = [&](int i, int t) {
            
            // return condition
            if(t == 0) {
                res.emplace_back(arr);
                return;
            }
            if(i >= n || nums[i] > t) {
                return;
            }

            //we can choose to pick it
            // we can further decide how many times to pick it
            // the criteria is the subtracted target must continue to be larger than current
            // or choose to skip it
            
            // we skip it.
            backtrack(i + 1, t);
            
            int count = 0;
            int num = nums[i];
            while(t >= num) {
                t -= num;
                count++;
                arr.emplace_back(num);
                // we pick it
                backtrack(i + 1, t);
            }

            // we remove
            while(count--) {
                arr.pop_back();
            }
            
        };

        backtrack(0, target);

        return res;
    }
};
