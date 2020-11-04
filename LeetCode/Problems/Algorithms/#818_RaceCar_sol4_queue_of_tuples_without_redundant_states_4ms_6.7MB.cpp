class Solution {
public:
    int racecar(int target) {
        const int INF = 2 * target + 1;
        queue<tuple<int, int, int>> q;
        q.push({0, 0, 1});
        
        while(!q.empty()){
            int cost = get<0>(q.front());
            int pos = get<1>(q.front());
            int speed = get<2>(q.front());
            
            q.pop();
            
            if(0 <= pos + speed && pos + speed < INF){
                q.push({cost + 1, pos + speed, 2 * speed});
            }
            if(speed > 0 && pos + speed > target){
                q.push({cost + 1, pos, -1});
            }
            if(speed < 0 && pos + speed < target){
                q.push({cost + 1, pos, 1});
            }
            
            if(pos + speed == target){
                return cost + 1;
            }
        }
        
        return 0;
    }
};