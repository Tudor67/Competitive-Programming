class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        const int N = seats.size();
        
        int startPos = 0;
        while(startPos < N && seats[startPos] == 0){
            startPos += 1;
        }
        
        int endPos = N - 1;
        while(startPos < endPos && seats[endPos] == 0){
            endPos -= 1;
        }
        
        int maxDist = max(startPos, N - 1 - endPos);
        int i = startPos;
        int j = startPos + 1;
        while(j <= endPos){
            if(seats[j] == 1){
                maxDist = max(maxDist, (j - i) / 2);
                i = j;
            }
            j += 1;
        }
        
        return maxDist;
    }
};