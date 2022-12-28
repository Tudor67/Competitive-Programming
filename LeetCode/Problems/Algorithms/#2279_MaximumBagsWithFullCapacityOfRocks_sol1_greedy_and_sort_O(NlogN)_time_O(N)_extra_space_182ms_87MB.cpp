class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        const int N = rocks.size();

        vector<int> need(N);
        for(int i = 0; i < N; ++i){
            need[i] = capacity[i] - rocks[i];
        }

        sort(need.begin(), need.end());

        int res = 0;
        for(int i = 0; i < N; ++i){
            if(need[i] <= additionalRocks){
                additionalRocks -= need[i];
                res += 1;
            }
        }

        return res;
    }
};