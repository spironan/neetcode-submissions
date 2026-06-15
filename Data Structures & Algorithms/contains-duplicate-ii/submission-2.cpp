class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // there must be two int within distance k that are the same value.
        // we can either 
        // proof there is a single duplicate within dist k OR
        // proof by counter-proof, that there exist NO duplicates within dist k
        unordered_set<int> window{};
        // queue<int> q{};
        // for(auto num: nums) {
        //     if(window.contains(num)) {
        //         return true;    
        //     }
        //     window.emplace(num);
        //     q.emplace(num);
        //     if(window.size() > k) {
        //         window.erase(q.front());
        //         q.pop();
        //     }
        // }
        // return false;
        int L = 0, R = 0;
        for(int R = 0; R < nums.size(); ++R) {
            if(R - L > k) {
                window.erase(nums[L++]);
            }
            if(window.contains(nums[R])) {
                return true;
            }
            window.insert(nums[R]);
        }

        return false;
    }
};