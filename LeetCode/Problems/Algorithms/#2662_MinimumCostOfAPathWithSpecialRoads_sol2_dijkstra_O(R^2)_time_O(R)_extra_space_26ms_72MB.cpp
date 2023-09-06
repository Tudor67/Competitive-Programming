class Solution {
private:
    using Position = pair<int, int>; // position (x, y)

    int computeDistance(const Position& A, const Position& B){
        return abs(A.first - B.first) + abs(A.second - B.second);
    }

public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
        const int R = specialRoads.size();
        const int INF = 1e9;

        Position startPosition = {start[0], start[1]};
        Position targetPosition = {target[0], target[1]};

        vector<int> dist(2 * R, INF);
        vector<bool> processed(2 * R, false);
        for(int i = 0; i < R; ++i){
            Position A = {specialRoads[i][0], specialRoads[i][1]};
            dist[i] = computeDistance(startPosition, A);
        }

        for(int iteration = 0; iteration < 2 * R; ++iteration){
            int minDist = INF;
            int minDistIndex = INF;
            for(int i = 0; i < 2 * R; ++i){
                if(!processed[i] && dist[i] < minDist){
                    minDist = dist[i];
                    minDistIndex = i;
                }
            }

            processed[minDistIndex] = true;
            if(minDistIndex < R){
                int cost = min(computeDistance({specialRoads[minDistIndex][0], specialRoads[minDistIndex][1]},
                                               {specialRoads[minDistIndex][2], specialRoads[minDistIndex][3]}),
                               specialRoads[minDistIndex][4]);
                dist[minDistIndex + R] = min(dist[minDistIndex + R], dist[minDistIndex] + cost);
            }else{
                Position B = {specialRoads[minDistIndex - R][2], specialRoads[minDistIndex - R][3]};
                for(int i = 0; i < R; ++i){
                    Position Ai = {specialRoads[i][0], specialRoads[i][1]};
                    dist[i] = min(dist[i], dist[minDistIndex] + computeDistance(B, Ai));
                }
            }
        }

        int res = computeDistance(startPosition, targetPosition);
        for(int i = 0; i < R; ++i){
            Position B = {specialRoads[i][2], specialRoads[i][3]};
            res = min(res, dist[i + R] + computeDistance(B, targetPosition));
        }

        return res;
    }
};