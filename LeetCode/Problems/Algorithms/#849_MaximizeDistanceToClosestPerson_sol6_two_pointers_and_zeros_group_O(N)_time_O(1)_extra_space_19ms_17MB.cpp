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
        int zeros = 0;
        for(int i = startPos; i <= endPos; ++i){
            if(seats[i] == 0){
                zeros += 1;
            }else{
                maxDist = max(maxDist, (zeros + 1) / 2);
                zeros = 0;
            }
        }
        
        return maxDist;
    }
};