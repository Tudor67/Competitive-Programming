class SparseTable{
private:
    vector<int> log2Of;
    vector<int> pow2Of;
    vector<vector<int>> maximum;

public:
    SparseTable(const vector<int>& HEIGHTS){
        const int N = HEIGHTS.size();
        const int LOG_N = log2(N) + 1;

        log2Of.assign(N + 1, 0);
        for(int i = 2; i <= N; ++i){
            log2Of[i] = 1 + log2Of[i / 2];
        }

        pow2Of.assign(LOG_N + 1, 1);
        for(int i = 1; i <= LOG_N; ++i){
            pow2Of[i] = 2 * pow2Of[i - 1];
        }

        maximum.assign(LOG_N + 1, vector<int>(N));
        maximum[0] = HEIGHTS;
        for(int k = 1; k <= LOG_N; ++k){
            for(int i = 0; i + pow2Of[k] - 1 < N; ++i){
                maximum[k][i] = max(maximum[k - 1][i], maximum[k - 1][i + pow2Of[k - 1]]);
            }
        }
    }

    int computeMax(int l, int r){
        int k = log2Of[r - l + 1];
        return max(maximum[k][l], maximum[k][r - pow2Of[k] + 1]);
    }
};

class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        const int N = heights.size();
        const int Q = queries.size();

        SparseTable sparseTable(heights);

        vector<int> res(Q, -1);
        for(int queryIndex = 0; queryIndex < Q; ++queryIndex){
            int a = queries[queryIndex][0];
            int b = queries[queryIndex][1];

            if(a > b){
                swap(a, b);
            }

            if(a == b || heights[a] < heights[b]){
                res[queryIndex] = b;
            }else{
                int threshold = heights[a] + 1;
                int startIndex = b + 1;
                int l = startIndex;
                int r = N;
                while(l != r){
                    int mid = (l + r) / 2;
                    if(threshold <= sparseTable.computeMax(startIndex, mid)){
                        r = mid;
                    }else{
                        l = mid + 1;
                    }
                }

                if(r < N && threshold <= heights[r]){
                    res[queryIndex] = r;
                }
            }
        }

        return res;
    }
};