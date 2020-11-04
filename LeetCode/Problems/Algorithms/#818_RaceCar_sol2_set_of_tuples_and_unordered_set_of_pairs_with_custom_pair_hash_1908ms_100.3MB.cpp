class Solution {
private:
    struct PairHash{
        size_t operator()(const pair<int, int>& P) const {
            size_t hashFirst = hash<int>()(P.first);
            size_t hashSecond = hash<int>()(P.second);
            return (hashFirst ^ hashSecond);
        }
    };
    
public:
    int racecar(int target) {
        const int INF = 2 * target + 1;
        
        set<tuple<int, int, int>> minSet;
        unordered_set<pair<int, int>, PairHash> vis;
        minSet.insert({0, 0, 1});
        
        while(!minSet.empty()){
            int cost = get<0>(*minSet.begin());
            int pos = get<1>(*minSet.begin());
            int speed = get<2>(*minSet.begin());
            
            minSet.erase(minSet.begin());
            vis.insert({pos, speed});

            if(vis.find({pos, (speed > 0 ? -1: 1)}) == vis.end()){
                minSet.insert({cost + 1, pos, (speed > 0 ? -1: 1)});
            }
            
            if(0 <= pos + speed && pos + speed < INF &&
               vis.find({pos + speed, 2 * speed}) == vis.end()){
                minSet.insert({cost + 1, pos + speed, 2 * speed});
            }

            if(pos + speed == target){
                return cost + 1;
            }
        }
        
        return 0;
    }
};