class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        const int STAMP_LENGTH = stamp.length();
        const int TARGET_LENGTH = target.length();
        
        vector<int> indices;
        vector<bool> done(TARGET_LENGTH, false);
        
        // windowDone[pos]: count(done.begin() + pos, done.begin() + pos + STAMP_LENGTH, true) == STAMP_LENGTH
        vector<bool> windowDone(TARGET_LENGTH - STAMP_LENGTH + 1, false);
        
        // windowMismatches[pos]: set of mismatched positions in range [pos, pos + 1, ..., pos + STAMP_LENGTH - 1]
        // we consider a mismatch if and only if (currentCharAt[x] != target[x] && !done[x])
        vector<unordered_set<int>> windowMismatches(TARGET_LENGTH - STAMP_LENGTH + 1);
        for(int i = 0; i + STAMP_LENGTH - 1 < TARGET_LENGTH; ++i){
            for(int k = 0; k < STAMP_LENGTH; ++k){
                if(stamp[k] != target[i + k]){
                    windowMismatches[i].insert(i + k);
                }
            }
        }
        
        queue<int> q;
        for(int i = 0; i + STAMP_LENGTH - 1 < TARGET_LENGTH; ++i){
            if(windowMismatches[i].empty() && !done[i]){
                fill(done.begin() + i, done.begin() + i + STAMP_LENGTH, true);
                windowDone[i] = true;
                indices.push_back(i);
                q.push(i);
            }
        }
        
        int doneCount = count(done.begin(), done.end(), true);
        while(!q.empty() && doneCount != TARGET_LENGTH){
            int i = q.front();
            q.pop();
            
            int leftPos = max(0, i - STAMP_LENGTH + 1);
            int rightPos = min(TARGET_LENGTH - STAMP_LENGTH, i + STAMP_LENGTH - 1);
            
            for(const pair<int, int>& START_POS_DIR: vector<pair<int, int>>{{leftPos, 1}, {rightPos, -1}}){
                const int START_POS = START_POS_DIR.first;
                const int DIRECTION = START_POS_DIR.second;
                for(int j = START_POS; j != i; j += DIRECTION){
                    assert(0 <= j && j + STAMP_LENGTH - 1 < TARGET_LENGTH);
                    for(int k = 0; k < STAMP_LENGTH; ++k){
                        if(j <= i + k && i + k <= j + STAMP_LENGTH - 1){
                            windowMismatches[j].erase(i + k);
                        }
                    }
                    if(windowMismatches[j].empty() && !windowDone[j]){
                        doneCount += count(done.begin() + j, done.begin() + j + STAMP_LENGTH, false);
                        fill(done.begin() + j, done.begin() + j + STAMP_LENGTH, true);
                        windowDone[j] = true;
                        indices.push_back(j);
                        q.push(j);
                        break;
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