class Solution {
private:
    vector<int> blacklist;
    vector<int> pref_sum; // pref_sum on the lengths of valid intervals
    
public:
    Solution(int N, vector<int>& initial_blacklist) {
        blacklist = initial_blacklist;
        blacklist.push_back(-1);
        blacklist.push_back(N);
        sort(blacklist.begin(), blacklist.end());
        
        pref_sum.resize(blacklist.size(), 0);
        for(int i = 1; i < blacklist.size(); ++i){
            pref_sum[i] = pref_sum[i - 1] + (blacklist[i] - 1 - blacklist[i - 1]);
        }
        
        srand(time(NULL));
    }
    
    int pick() {
        int valid_idx = rand() % pref_sum.back();
        int pos = upper_bound(pref_sum.begin(), pref_sum.end(), valid_idx) - pref_sum.begin() - 1;
        int valid_val = blacklist[pos] + 1 + (valid_idx - pref_sum[pos]);
        return valid_val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(N, blacklist);
 * int param_1 = obj->pick();
 */