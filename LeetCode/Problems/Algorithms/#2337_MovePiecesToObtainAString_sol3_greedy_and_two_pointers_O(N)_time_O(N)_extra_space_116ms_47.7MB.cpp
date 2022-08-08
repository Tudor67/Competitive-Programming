class Solution {
public:
    bool canChange(string start, string target) {
        const int N = start.length();
        
        vector<pair<char, int>> startPieces;
        vector<pair<char, int>> targetPieces;
        for(int i = 0; i < N; ++i){
            if(start[i] != '_'){
                startPieces.emplace_back(start[i], i);
            }
            if(target[i] != '_'){
                targetPieces.emplace_back(target[i], i);
            }
        }
        
        bool isPossible = (startPieces.size() == targetPieces.size());
        for(int i = 0; isPossible && i < (int)startPieces.size(); ++i){
            if(startPieces[i].first == targetPieces[i].first){
                if((startPieces[i].first == 'L' && startPieces[i].second < targetPieces[i].second) ||
                   (startPieces[i].first == 'R' && startPieces[i].second > targetPieces[i].second)){
                    isPossible = false;
                }
            }else{
                isPossible = false;
            }
        }
        
        return isPossible;
    }
};