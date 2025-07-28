class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        vector<vector<int>> endsFor(n + 1);
        multiset<int> endsMS = {n + 1};
        for(vector<int>& pair: conflictingPairs){
            int a = min(pair[0], pair[1]);
            int b = max(pair[0], pair[1]);
            endsFor[a].push_back(b);
            endsMS.insert(b);
        }

        long long res = 0;
        vector<long long> extra(n + 1);
        for(int i = 1; i <= n; ++i){
            res += *endsMS.begin() - i;
            if((int)endsMS.size() >= 2){
                extra[*endsMS.begin()] += *next(endsMS.begin()) - *endsMS.begin();
            }
            while(!endsFor[i].empty()){
                endsMS.erase(endsMS.find(endsFor[i].back()));
                endsFor[i].pop_back();
            }
        }

        return res + *max_element(extra.begin(), extra.end());
    }
};