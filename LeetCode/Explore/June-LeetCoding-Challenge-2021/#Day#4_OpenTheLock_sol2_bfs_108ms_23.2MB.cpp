class Solution {
public:
    int openLock(vector<string>& deadendsStr, string targetStr) {
        const int TARGET = stoi(targetStr);
        unordered_set<int> deadendsSet;
        for(const string& DEADEND_STR: deadendsStr){
            deadendsSet.insert(stoi(DEADEND_STR));
        }
        
        unordered_set<int> visSet;
        queue<pair<int, int>> q;
        if(!deadendsSet.count(0)){
            q.push({0, 0});
            visSet.insert(0);
        }
        
        while(!q.empty()){
            int state = q.front().first;
            int dist = q.front().second;
            q.pop();
            
            if(state == TARGET){
                return dist;
            }
            
            for(const int& DIRECTION: {-1, 1}){
                for(int pow10 = 1; pow10 <= 1e3; pow10 *= 10){
                    int nextDigit = ((state / pow10) % 10 + DIRECTION + 10) % 10;
                    int nextState = (state / (10 * pow10)) * 10 * pow10 + nextDigit * pow10 + (state % pow10);
                    if(!visSet.count(nextState) && !deadendsSet.count(nextState)){
                        q.push({nextState, 1 + dist});
                        visSet.insert(nextState);
                    }
                }
            }
        }
        
        return -1;
    }
};