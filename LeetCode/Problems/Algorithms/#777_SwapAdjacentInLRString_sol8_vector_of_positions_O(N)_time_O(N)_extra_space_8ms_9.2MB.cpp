class Solution {
public:
    bool canTransform(string start, string end) {
        const int N = start.length();
        
        vector<pair<char, int>> startPairs;
        vector<pair<char, int>> endPairs;
        for(int i = 0; i < N; ++i){
            if(start[i] != 'X'){
                startPairs.emplace_back(start[i], i);
            }
            if(end[i] != 'X'){
                endPairs.emplace_back(end[i], i);
            }
        }
        
        if(startPairs.size() != endPairs.size()){
            return false;
        }
        
        for(int i = 0; i < (int)startPairs.size(); ++i){
            if(startPairs[i].first != endPairs[i].first){
                return false;
            }
            if(startPairs[i].first == 'L' && startPairs[i].second < endPairs[i].second){
                return false;
            }
            if(startPairs[i].first == 'R' && startPairs[i].second > endPairs[i].second){
                return false;
            }
        }
        
        return true;
    }
};