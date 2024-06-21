class Solution {
private:
    bool isPossible(vector<int>& sortedPositions, int remainingBalls, int distanceThreshold){
        remainingBalls -= 1;
        int prevPosition = sortedPositions.front();
        for(int position: sortedPositions){
            if(position - prevPosition >= distanceThreshold){
                remainingBalls -= 1;
                prevPosition = position;
            }
        }
        return (remainingBalls <= 0);
    }

public:
    int maxDistance(vector<int>& positions, int m) {
        const int N = positions.size();

        vector<int> sortedPositions = positions;
        sort(sortedPositions.begin(), sortedPositions.end());

        int l = 0;
        int r = sortedPositions.back();
        while(l != r){
            int mid = (l + r + 1) / 2;
            if(isPossible(sortedPositions, m, mid)){
                l = mid;
            }else{
                r = mid - 1;
            }
        }

        return r;
    }
};