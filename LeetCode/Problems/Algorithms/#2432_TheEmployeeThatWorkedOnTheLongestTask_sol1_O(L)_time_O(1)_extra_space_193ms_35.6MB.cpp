class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        const int L = logs.size();
        
        int resID = logs[0][0];
        int resTime = logs[0][1];
        for(int i = 1; i < L; ++i){
            int currentID = logs[i][0];
            int currentTime = logs[i][1] - logs[i - 1][1];
            if(resTime < currentTime || (resTime == currentTime && currentID < resID)){
                resID = currentID;
                resTime = currentTime;
            }
        }
        
        return resID;
    }
};