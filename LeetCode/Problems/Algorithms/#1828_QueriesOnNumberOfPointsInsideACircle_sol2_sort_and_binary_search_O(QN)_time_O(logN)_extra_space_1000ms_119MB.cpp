class Solution {
private:
    int computeDistSq(const vector<int>& A, const vector<int>& B){
        return (A[0] - B[0]) * (A[0] - B[0]) + (A[1] - B[1]) * (A[1] - B[1]);
    }

public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        const int N = points.size();
        const int Q = queries.size();

        sort(points.begin(), points.end());

        vector<int> answer(Q);
        for(int i = 0; i < Q; ++i){
            int x = queries[i][0];
            int y = queries[i][1];
            int r = queries[i][2];
            int startIndex = lower_bound(points.begin(), points.end(), vector<int>{x - r, y}) - points.begin();
            int endIndex = upper_bound(points.begin(), points.end(), vector<int>{x + r, y}) - points.begin();
            for(int index = startIndex; index < endIndex; ++index){
                if(computeDistSq(points[index], {x, y}) <= r * r){
                    answer[i] += 1;
                }
            }
        }

        return answer;
    }
};