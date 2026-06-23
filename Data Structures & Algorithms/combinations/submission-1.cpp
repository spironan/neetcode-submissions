class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        // we are returning all subsets of n choose k.
        // n choose k is described as n!/k!(n-k)! for the number of combinations
        vector<vector<int>> result{};

        vector<int> subset;
        subset.reserve(k);

        std::function<void(int)> backtrack = [&](int c){
            
            if(subset.size() == k) {
                result.emplace_back(subset);
                return;
            }

            for(int i = c; i <=n; ++i) {
                subset.emplace_back(i);
                backtrack(i + 1);
                subset.pop_back();
            }

        };

        backtrack(1);

        return result;

    }
};