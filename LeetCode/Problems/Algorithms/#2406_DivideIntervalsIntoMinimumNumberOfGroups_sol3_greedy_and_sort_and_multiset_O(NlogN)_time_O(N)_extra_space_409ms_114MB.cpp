class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        const int N = intervals.size();

        vector<int> p(N);
        iota(p.begin(), p.end(), 0);
        sort(p.begin(), p.end(),
             [&](int lhs, int rhs){
                return (intervals[lhs] < intervals[rhs]);
             });
        
        multiset<int> endsMultiset;
        for(int i: p){
            int l = intervals[i][0];
            int r = intervals[i][1];
            multiset<int>::iterator it = endsMultiset.lower_bound(l);
            if(it != endsMultiset.begin()){
                endsMultiset.erase(prev(it));
            }
            endsMultiset.insert(r);
        }

        return endsMultiset.size();
    }
};