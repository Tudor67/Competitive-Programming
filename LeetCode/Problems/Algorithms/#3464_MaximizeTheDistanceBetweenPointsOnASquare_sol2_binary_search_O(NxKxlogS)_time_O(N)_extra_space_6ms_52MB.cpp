class Solution {
private:
    bool isValid(vector<long long>& p, long long side, int k, long long distThr){
        const int N = p.size();

        vector<int> nxt(N);
        for(int l = 0, r = 0; l < N; ++l){
            while(r < N && p[l] + distThr > p[r]){
                ++r;
            }
            nxt[l] = r;
        }

        for(int i = 0; i < N; ++i){
            long long start = p[i];
            long long end = start + 4LL * side - distThr;

            bool found = true;
            int currIdx = i;
            for(int step = 1; step < k; ++step){
                currIdx = nxt[currIdx];
                if(currIdx == N || p[currIdx] > end){
                    found = false;
                    break;
                }
            }

            if(found){
                return true;
            }
        }

        return false;
    }

public:
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        const int N = points.size();

        vector<long long> p(N);
        for(int i = 0; i < N; ++i){
            int x = points[i][0];
            int y = points[i][1];
            if(x == 0){
                p[i] = y;
            }else if(y == side){
                p[i] = side + x;
            }else if(x == side){
                p[i] = 3LL * side - y;
            }else{
                p[i] = 4LL * side - x;
            }
        }

        sort(p.begin(), p.end());

        long long l = 1;
        long long r = side;
        while(l != r){
            long long mid = (l + r + 1) / 2;
            if(isValid(p, side, k, mid)){
                l = mid;
            }else{
                r = mid - 1;
            }
        }

        return r;
    }
};