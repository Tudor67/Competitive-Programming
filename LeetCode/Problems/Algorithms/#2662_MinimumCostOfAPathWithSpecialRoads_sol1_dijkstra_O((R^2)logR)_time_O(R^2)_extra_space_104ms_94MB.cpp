class Solution {
private:
    using Position = pair<int, int>;   // position (x, y)
    using State = pair<int, Position>; // (distance to (x, y), position (x, y))
    using Graph = map<Position, vector<pair<int, Position>>>;

    int computeDistance(const Position& A, const Position& B){
        return abs(A.first - B.first) + abs(A.second - B.second);
    }

public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
        const int R = specialRoads.size();

        Position startPosition = {start[0], start[1]};
        Position targetPosition = {target[0], target[1]};

        Graph G;
        G[startPosition].push_back({computeDistance(startPosition, targetPosition), targetPosition});
        
        for(const vector<int>& R: specialRoads){
            Position A = {R[0], R[1]};
            Position B = {R[2], R[3]};
            int cost = R[4];

            G[A].push_back({min(cost, computeDistance(A, B)), B});
            G[startPosition].push_back({computeDistance(startPosition, A), A});
            G[B].push_back({computeDistance(B, targetPosition), targetPosition});
        }

        for(int i = 0; i < R; ++i){
            for(int j = 0; j < R; ++j){
                for(Position Bi: {Position{specialRoads[i][2], specialRoads[i][3]}}){
                    for(Position Aj: {Position{specialRoads[j][0], specialRoads[j][1]}}){
                        G[Bi].push_back({computeDistance(Bi, Aj), Aj});
                    }
                }
            }
        }

        map<Position, int> dist;
        set<State> statesSet;
        dist[startPosition] = 0;
        statesSet.insert({dist[startPosition], startPosition});

        while(!statesSet.empty() && statesSet.begin()->second != targetPosition){
            Position currentPosition = statesSet.begin()->second;
            statesSet.erase(statesSet.begin());

            for(const pair<int, Position>& P: G[currentPosition]){
                int cost = P.first;
                Position nextPosition = P.second;
                if(!dist.count(nextPosition) || dist[currentPosition] + cost < dist[nextPosition]){
                    statesSet.erase({dist[nextPosition], nextPosition});
                    dist[nextPosition] = dist[currentPosition] + cost;
                    statesSet.insert({dist[nextPosition], nextPosition});
                }
            }
        }

        return dist[targetPosition];
    }
};