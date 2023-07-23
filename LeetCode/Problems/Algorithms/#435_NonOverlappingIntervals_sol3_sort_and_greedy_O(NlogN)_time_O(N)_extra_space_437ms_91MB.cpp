class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        const int N = intervals.size();

        vector<int> p(N);
        iota(p.begin(), p.end(), 0);
        sort(p.begin(), p.end(),
             [&](int lhs, int rhs){
                 return (intervals[lhs][1] < intervals[rhs][1]);
             });

        int res = 0;
        int prevEnd = intervals[p[0]][1] - 1;
        for(int i = 1; i < N; ++i){
            if(prevEnd < intervals[p[i]][0]){
                prevEnd = intervals[p[i]][1] - 1;
            }else{
                res += 1;
            }
        }

        return res;
    }
};