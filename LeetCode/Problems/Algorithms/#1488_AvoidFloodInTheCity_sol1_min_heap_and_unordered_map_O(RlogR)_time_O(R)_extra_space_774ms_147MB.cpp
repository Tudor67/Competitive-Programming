class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        const int R = rains.size();
        
        unordered_map<int, vector<int>> posOf;
        for(int i = R - 1; i >= 0; --i){
            if(rains[i] > 0){
                posOf[rains[i]].push_back(i);
            }
        }
        
        vector<int> answer(R);
        unordered_set<int> fullLakes;
        priority_queue<int, vector<int>, greater<int>> nextPositionsOfFullLakes;
        for(int i = 0; i < R; ++i){
            if(rains[i] == 0){
                if(nextPositionsOfFullLakes.empty()){
                    answer[i] = 1;
                }else{
                    int pos = nextPositionsOfFullLakes.top();
                    nextPositionsOfFullLakes.pop();
                    fullLakes.erase(rains[pos]);
                    answer[i] = rains[pos];
                }
            }else{
                if(fullLakes.count(rains[i])){
                    answer.clear();
                    break;
                }else{
                    fullLakes.insert(rains[i]);
                    posOf[rains[i]].pop_back();
                    if(!posOf[rains[i]].empty()){
                        nextPositionsOfFullLakes.push(posOf[rains[i]].back());
                    }
                }
                answer[i] = -1;
            }
        }
        
        return answer;
    }
};