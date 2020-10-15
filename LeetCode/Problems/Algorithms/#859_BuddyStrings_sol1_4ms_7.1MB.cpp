class Solution {
public:
    bool buddyStrings(string A, string B) {
        if(A.length() != B.length() || min(A.length(), B.length()) < 2){
            return false;
        }
        
        vector<int> badPositions;
        for(int i = 0; i < A.length(); ++i){
            if(A[i] != B[i]){
                badPositions.push_back(i);
            }
            if(badPositions.size() == 3){
                break;
            }
        }
        
        bool canSwap = false;
        if(badPositions.empty()){
            vector<bool> vis(128, false);
            bool containsDuplicate = false;
            for(char c: A){
                if(vis[c]){
                    containsDuplicate = true;
                    break;
                }
                vis[c] = true;
            }
            canSwap = containsDuplicate;
        }else if(badPositions.size() == 2 && A[badPositions[0]] == B[badPositions[1]] &&
                                             A[badPositions[1]] == B[badPositions[0]]){
            canSwap = true;
        }
        
        return canSwap;
    }
};