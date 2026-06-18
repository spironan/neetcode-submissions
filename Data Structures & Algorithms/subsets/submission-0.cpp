class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        res.reserve(pow(2,nums.size()));

        vector<int> arr{};
        arr.reserve(nums.size());
        
        std::function<void(int)> backtrack = [&](int i){
            if(i >= nums.size()) {
                res.emplace_back(arr);
                return;
            }
            
            // we add it to the list
            arr.emplace_back(nums[i]);
            // continue as though we picked
            backtrack(i + 1);
            // we skip this element
            arr.pop_back(); 
            // continue as though we skipped
            backtrack(i + 1);
        };
        
        backtrack(0);
       
        return res;
    }
};
