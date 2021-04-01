class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        const int STAMP_LENGTH = stamp.length();
        const int TARGET_LENGTH = target.length();
        
        vector<int> indices;
        vector<bool> ok(TARGET_LENGTH, false);
        
        int prevCount = -1;
        int curCount = 0;
        while(prevCount < curCount){
            for(int i = 0; i + STAMP_LENGTH - 1 < TARGET_LENGTH; ++i){
                bool canBeStamped = true;
                bool isAlreadyStamped = true;
                for(int k = 0; k < STAMP_LENGTH; ++k){
                    if(!ok[i + k] && stamp[k] != target[i + k]){
                        canBeStamped = false;
                        break;
                    }
                    isAlreadyStamped &= ok[i + k];
                }
                if(canBeStamped && !isAlreadyStamped){
                    fill(ok.begin() + i, ok.begin() + i + STAMP_LENGTH, true);
                    indices.push_back(i);
                }
            }
            prevCount = curCount;
            curCount = count(ok.begin(), ok.end(), true);
        }
        
        reverse(indices.begin(), indices.end());

        if(count(ok.begin(), ok.end(), true) != TARGET_LENGTH){
            indices.clear();
        }
        
        return indices;
    }
};