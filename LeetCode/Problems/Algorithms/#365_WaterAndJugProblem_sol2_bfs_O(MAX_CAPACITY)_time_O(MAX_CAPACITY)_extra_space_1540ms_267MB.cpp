class Solution {
private:
    struct PairHash{
        size_t operator()(const pair<int, int>& P) const{
            size_t a = P.first;
            size_t b = P.second;
            return (a << 20) | b;
        }
    };

public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        // Sanity check
        if(jug1Capacity + jug2Capacity < targetCapacity){
            return false;
        }

        // BFS
        queue<pair<int, int>> q;
        unordered_set<pair<int, int>, PairHash> vis;
        q.push({jug1Capacity, jug2Capacity});
        vis.insert({jug1Capacity, jug2Capacity});

        while(!q.empty()){
            int c1 = q.front().first;
            int c2 = q.front().second;
            q.pop();

            if(c1 + c2 == targetCapacity){
                return true;
            }

            for(pair<int, int> p: vector<pair<int, int>> {{jug1Capacity, c2}, {c1, jug2Capacity},
                                                          {0, c2}, {c1, 0},
                                                          {min(jug1Capacity, c1 + c2), max(0, c1 + c2 - jug1Capacity)},
                                                          {max(0, c1 + c2 - jug2Capacity), min(jug2Capacity, c1 + c2)}}){
                if(!vis.count(p)){
                    q.push(p);
                    vis.insert(p);
                }
            }
        }

        return false;
    }
};