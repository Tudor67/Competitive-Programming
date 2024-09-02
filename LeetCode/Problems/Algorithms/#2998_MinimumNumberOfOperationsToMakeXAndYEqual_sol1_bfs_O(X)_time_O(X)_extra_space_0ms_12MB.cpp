class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        if(x <= y){
            return (y - x);
        }

        const int INF = 1e9;
        vector<int> minDist(2 * x + 1, INF);
        queue<int> q;
        minDist[x] = 0;
        q.push(x);

        while(!q.empty() && minDist[y] == INF){
            int num = q.front();
            q.pop();

            for(int nextNum: {num - 1, num + 1}){
                if(0 <= nextNum && nextNum < (int)minDist.size() && minDist[nextNum] == INF){
                    minDist[nextNum] = minDist[num] + 1;
                    q.push(nextNum);
                }
            }

            for(int d: {5, 11}){
                int nextNum = num / d;
                if(num % d == 0 && minDist[nextNum] == INF){
                    minDist[nextNum] = minDist[num] + 1;
                    q.push(nextNum);
                }
            }
        }

        return minDist[y];
    }
};