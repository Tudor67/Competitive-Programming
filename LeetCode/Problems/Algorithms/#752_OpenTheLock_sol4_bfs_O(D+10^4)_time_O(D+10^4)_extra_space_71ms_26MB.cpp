class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        const int D = deadends.size();
        const int SOURCE = 0;
        const int TARGET = stoi(target);

        unordered_set<int> deadendsSet;
        for(const string& DEADEND: deadends){
            deadendsSet.insert(stoi(DEADEND));
        }

        unordered_map<int, int> dist;
        queue<int> q;
        if(!deadendsSet.count(SOURCE)){
            dist[0] = SOURCE;
            q.push(SOURCE);
        }

        while(!q.empty()){
            int state = q.front();
            q.pop();

            if(state == TARGET){
                return dist[state];
            }

            for(int p10 = 1; p10 <= 1000; p10 *= 10){
                for(int direction: {-1, 1}){
                    int digit = (state / p10) % 10;
                    int nextDigit = (digit + direction + 10) % 10;
                    int nextState = state - digit * p10 + nextDigit * p10;
                    if(!deadendsSet.count(nextState) && !dist.count(nextState)){
                        dist[nextState] = dist[state] + 1;
                        q.push(nextState);
                    }
                }
            }
        }

        return -1;
    }
};