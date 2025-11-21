class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        const int N = intervals.size();

        vector<int> p(N);
        iota(p.begin(), p.end(), 0);
        sort(p.begin(), p.end(),
             [&](int lhs, int rhs){
                return pair<int, int>{intervals[lhs][1], -intervals[lhs][0]} <
                       pair<int, int>{intervals[rhs][1], -intervals[rhs][0]};
             });

        vector<int> selectedNums;
        for(int i: p){
            if(selectedNums.empty() || selectedNums.back() < intervals[i][0]){
                selectedNums.push_back(intervals[i][1] - 1);
                selectedNums.push_back(intervals[i][1]);
            }else if(selectedNums[(int)selectedNums.size() - 2] < intervals[i][0]){
                selectedNums.push_back(intervals[i][1]);
            }
        }

        return selectedNums.size();
    }
};