class Solution {
public:
    int racecar(int target) {
        const int INF = 2 * target + 1;
        set<tuple<int, int, int>> stateSet;
        stateSet.insert({0, 0, 1});
        
        while(!stateSet.empty()){
            int cost = get<0>(*stateSet.begin());
            int pos = get<1>(*stateSet.begin());
            int speed = get<2>(*stateSet.begin());
            
            stateSet.erase(stateSet.begin());
            
            if(0 <= pos + speed && pos + speed < INF){
                stateSet.insert({cost + 1, pos + speed, 2 * speed});
            }
            if(speed > 0 && pos + speed > target){
                stateSet.insert({cost + 1, pos, -1});
            }
            if(speed < 0 && pos + speed < target){
                stateSet.insert({cost + 1, pos, 1});
            }
            
            if(pos + speed == target){
                return cost + 1;
            }
        }
        
        return 0;
    }
};