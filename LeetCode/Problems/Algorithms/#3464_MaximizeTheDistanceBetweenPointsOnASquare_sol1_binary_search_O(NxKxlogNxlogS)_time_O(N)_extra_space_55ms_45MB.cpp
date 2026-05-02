class Solution {
private:
    bool isValid(vector<long long>& p, long long side, int k, long long distThr){
        const int N = p.size();

        for(long long start: p){
            long long pos = start;
            long long end = start + 4LL * side - distThr;
            for(int step = 1; step < k; ++step){
                auto it = lower_bound(p.begin(), p.end(), pos + distThr);
                if(it == p.end() || *it > end){
                    pos = -1;
                    break;
                }
                pos = *it;
            }

            if(pos >= 0){
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