class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res{};
        vector<int> arr{};
        int n = candidates.size();
        std::function<void(int,int)> backtrack = [&](int i, int t){
            if(t == 0) {
                res.emplace_back(arr);
                return;
            }
            
            if(i >= n || candidates[i] > t) {
                return;
            }
            
            // we pick it first
            int num = candidates[i];
            int count = 0;
            
            t -= num;
            arr.emplace_back(num);
            backtrack(i + 1, t);

            // reset
            arr.pop_back();
            t += num;

            // proceed to last element
            while(i + 1 < n && candidates[i] == candidates[i + 1])
                ++i;

            // we skip it
            backtrack(i + 1, t);
        };
        backtrack(0, target);


        return res;
    }
};
