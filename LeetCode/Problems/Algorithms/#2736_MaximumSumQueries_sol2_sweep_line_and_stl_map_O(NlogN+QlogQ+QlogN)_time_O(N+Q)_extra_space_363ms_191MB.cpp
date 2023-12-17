class Solution {
public:
    vector<int> maximumSumQueries(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        const int N = nums1.size();
        const int Q = queries.size();
        
        // sort cells (nums1[i], nums2[i]) in decreasing order of nums2[i]
        vector<pair<int, int>> c(N);
        for(int i = 0; i < N; ++i){
            c[i] = {nums1[i], nums2[i]};
        }
        
        sort(c.begin(), c.end(),
             [](const pair<int, int>& LHS, const pair<int, int>& RHS){
                 return LHS.second > RHS.second;
             });
        
        // sort queries in decreasing order of x2 coordinate
        vector<int> p(Q);
        iota(p.begin(), p.end(), 0);
        sort(p.begin(), p.end(),
            [&](int lhs, int rhs){
                return queries[lhs][1] > queries[rhs][1];
            });
        
        // sweep line
        // process queries in decreasing order of x2 coordinate
        vector<int> res(Q, -1);
        map<int, int> mono;

        int cIdx = 0;
        for(int qIdx: p){
            int q1 = queries[qIdx][0];
            int q2 = queries[qIdx][1];
            
            while(cIdx < N && q2 <= c[cIdx].second){
                int x1 = c[cIdx].first;
                int x2 = c[cIdx].second;
                map<int, int>::iterator it = mono.insert({x1, x1 + x2}).first;
                if(it != prev(mono.end())){
                    it = next(it);
                }
                while(it != mono.begin() && prev(it)->second <= it->second){
                    it = mono.erase(prev(it));
                }
                cIdx += 1;
            }
            
            map<int, int>::iterator it = mono.lower_bound(q1);
            if(it != mono.end()){
                res[qIdx] = it->second;
            }
        }
        
        return res;
    }
};