class Solution {
private:
    using Segment = pair<int, int>;

    Segment computeIntersection(const Segment& LHS, const Segment& RHS){
        return {max(LHS.first, RHS.first), min(LHS.second, RHS.second)};
    }

public:
    int findMinArrowShots(vector<vector<int>>& points) {
        const int N = points.size();

        vector<Segment> sortedSegments(N);
        for(int i = 0; i < N; ++i){
            sortedSegments[i] = {points[i][0], points[i][1]};
        }

        sort(sortedSegments.begin(), sortedSegments.end(),
             [](const Segment& LHS, const Segment& RHS){
                 return (LHS.second < RHS.second);
             });
        
        int res = 1;
        Segment intersectionSegment = sortedSegments[0];
        for(int i = 1; i < N; ++i){
            intersectionSegment = computeIntersection(intersectionSegment, sortedSegments[i]);
            if(intersectionSegment.first > intersectionSegment.second){
                res += 1;
                intersectionSegment = sortedSegments[i];
            }
        }

        return res;
    }
};