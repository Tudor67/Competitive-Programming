class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        const int STAMP_LENGTH = stamp.length();
        const int TARGET_LENGTH = target.length();
        
        vector<int> indices;
        vector<bool> done(TARGET_LENGTH, false);
        
        // windowMatches[pos]: set of matched positions in range [pos, pos + 1, ..., pos + STAMP_LENGTH - 1]
        // windowMismatches[pos]: set of mismatched positions in range [pos, pos + 1, ..., pos + STAMP_LENGTH - 1]
        // we consider a match if and only if (currentCharAt[x] == target[x] || done[x])
        // we consider a mismatch if and only if (currentCharAt[x] != target[x] && !done[x])
        vector<vector<int>> windowMatches(TARGET_LENGTH - STAMP_LENGTH + 1);
        vector<unordered_set<int>> windowMismatches(TARGET_LENGTH - STAMP_LENGTH + 1);
        for(int i = 0; i + STAMP_LENGTH - 1 < TARGET_LENGTH; ++i){
            for(int k = 0; k < STAMP_LENGTH; ++k){
                if(stamp[k] == target[i + k]){
                    windowMatches[i].push_back(i + k);
                }else{
                    windowMismatches[i].insert(i + k);
                }
            }
        }
        
        queue<int> q;
        for(int i = 0; i + STAMP_LENGTH - 1 < TARGET_LENGTH; ++i){
            if(windowMismatches[i].empty()){
                indices.push_back(i);
                for(int k = 0; k < STAMP_LENGTH; ++k){
                    done[i + k] = true;
                    q.push(i + k);
                }
            }
        }
        
        int doneCount = count(done.begin(), done.end(), true);
        while(!q.empty() && doneCount != TARGET_LENGTH){
            int i = q.front();
            q.pop();
            
            int leftPos = max(0, i - STAMP_LENGTH + 1);
            int rightPos = min(TARGET_LENGTH - STAMP_LENGTH, i);
            
            for(int j = leftPos; j <= rightPos; ++j){
                if(windowMismatches[j].count(i)){
                    windowMismatches[j].erase(i);
                    if(windowMismatches[j].empty()){
                        indices.push_back(j);
                        for(int pos: windowMatches[j]){
                            if(!done[pos]){
                                done[pos] = true;
                                q.push(pos);
                                doneCount += 1;
                            }
                        }
                    }
                }
            }
        }
        
        reverse(indices.begin(), indices.end());

        if(count(done.begin(), done.end(), true) != TARGET_LENGTH){
            indices.clear();
        }
        
        return indices;
    }
};