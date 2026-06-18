class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res{{}}; // includes the empty set at the start.

        for(auto num : nums) {
            int size = res.size();
            for(int i = 0; i < size; ++i) {
                vector<int> subset = res[i];
                subset.emplace_back(num);
                res.emplace_back(subset);
            }
        }
        return res;
    }
};
