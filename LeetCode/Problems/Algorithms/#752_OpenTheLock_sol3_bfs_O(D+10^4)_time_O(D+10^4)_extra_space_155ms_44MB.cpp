class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        const int D = deadends.size();

        unordered_set<string> deadendsSet(deadends.begin(), deadends.end());
        unordered_map<string, int> dist;
        queue<string> q;
        if(!deadendsSet.count("0000")){
            dist["0000"] = 0;
            q.push("0000");
        }

        while(!q.empty()){
            string state = q.front();
            q.pop();

            if(state == target){
                return dist[state];
            }

            for(int i = 0; i < 4; ++i){
                string nextState = state;

                nextState[i] = char('0' + (state[i] - '0' + 1) % 10);
                if(!deadendsSet.count(nextState) && !dist.count(nextState)){
                    dist[nextState] = dist[state] + 1;
                    q.push(nextState);
                }

                nextState[i] = char('0' + (state[i] - '0' - 1 + 10) % 10);
                if(!deadendsSet.count(nextState) && !dist.count(nextState)){
                    dist[nextState] = dist[state] + 1;
                    q.push(nextState);
                }
            }
        }

        return -1;
    }
};