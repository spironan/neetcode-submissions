class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        // we are returning all subsets of n choose k.
        // n choose k is described as n!/k!(n-k)! for the number of combinations
        vector<vector<int>> result{};

        vector<int> subset;
        subset.reserve(k);

        std::function<void(int)> backtrack = [&](int c){
            
            if (c > n) {
                if(subset.size() == k) {
                    result.emplace_back(subset);
                }
                return;
            }

            // // we must pick it.
            // if (k - subset.size() == n - c + 1) 
            // {
            //     subset.emplace_back(c);
            //     backtrack(c + 1);
            // }
            // else 
            // {
                // we can choose!
                subset.emplace_back(c);
                backtrack(c + 1);
                subset.pop_back();
                backtrack(c + 1);
            // }

            // before deciding whether we choose or not, we must make sure the index + elements <= k
            // otherwise we MUST pick.
        };

        backtrack(1);

        return result;

    }
};