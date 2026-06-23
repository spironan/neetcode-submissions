class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        std::array<int, 26> alienbatical{};
        for(int i = 0; i < 26; ++i) {
            alienbatical[order[i] - 'a'] = i;
        }

        for(int i = 1; i < words.size(); ++i) {
            string prev = words[i - 1];
            string curr = words[i];
            int j = 0;
            bool definitelyBigger = false;
            for(j = 0; j < min(curr.size(), prev.size()); ++j) {
                if(alienbatical[curr[j] - 'a'] > alienbatical[prev[j]- 'a']){
                    definitelyBigger = true;
                    break; // one is definitely bigger than the next, no need to check any further
                }
                
                if(alienbatical[curr[j]- 'a'] < alienbatical[prev[j]- 'a']){
                    // cout << prev[j] << " " << alienbatical[prev[j]] << " " << curr[j] << " " << alienbatical[curr[j]] << "\n";
                    return false;
                }
            }

            if(!definitelyBigger && curr.size() < prev.size() && curr[j - 1] == prev[j - 1])
                return false;
        }

        return true;
    }
};