class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        const int N = releaseTimes.size();
        int maxT = releaseTimes[0];
        char maxK = keysPressed[0];
        for(int i = 1; i < N; ++i){
            int t = releaseTimes[i] - releaseTimes[i - 1];
            if(t > maxT || (t == maxT && keysPressed[i] > maxK)){
                maxT = t;
                maxK = keysPressed[i];
            }
        }
        return maxK;
    }
};