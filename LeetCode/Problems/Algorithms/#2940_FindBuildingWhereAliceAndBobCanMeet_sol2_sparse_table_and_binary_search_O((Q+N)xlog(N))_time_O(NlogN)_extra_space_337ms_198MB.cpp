class SparseTable{
private:
    vector<vector<int>> a;
    vector<int> pow2Of;
    vector<int> log2Of;

public:
    SparseTable(const vector<int>& VALUES){
        const int N = VALUES.size();
        const int LOG_N = ceil(log2(N));

        pow2Of.assign(LOG_N + 1, 1);
        for(int i = 1; i <= LOG_N; ++i){
            pow2Of[i] = 2 * pow2Of[i - 1];
        }

        log2Of.assign(N + 1, 0);
        for(int i = 2; i <= N; ++i){
            log2Of[i] = log2Of[i / 2] + 1;
        }

        a.assign(LOG_N + 1, vector<int>(N));
        for(int i = 0; i < N; ++i){
            a[0][i] = VALUES[i];
        }

        for(int k = 1; k <= LOG_N; ++k){
            for(int i = 0; i + pow2Of[k] < N; ++i){
                if(a[k - 1][i] >= a[k - 1][i + pow2Of[k - 1]]){
                    a[k][i] = a[k - 1][i];
                }else{
                    a[k][i] = a[k - 1][i + pow2Of[k - 1]];
                }
            }
        }
    }

    int getMax(const int L, const int R){
        int k = log2Of[R - L + 1];
        return max(a[k][L], a[k][R - pow2Of[k] + 1]);
    }
};

class Solution {
private:
    int query(int a, int b, vector<int>& heights, SparseTable& sparseTable){
        if(a > b){
            swap(a, b);
        }

        // Case 1
        if(a == b){
            return b;
        }

        // Case 2
        if(heights[a] < heights[b]){
            return b;
        }

        // Case 3
        int threshold = max(heights[a], heights[b]);
        int l = b;
        int r = (int)heights.size() - 1;
        while(l != r){
            int mid = (l + r) / 2;
            if(sparseTable.getMax(b, mid) <= threshold){
                l = mid + 1;
            }else{
                r = mid;
            }
        }

        if(heights[r] > threshold){
            return r;
        }

        // Case 4
        return -1;
    }

public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        const int N = heights.size();
        const int Q = queries.size();

        SparseTable sparseTable(heights);

        vector<int> res(Q);
        for(int i = 0; i < Q; ++i){
            int a = queries[i][0];
            int b = queries[i][1];
            res[i] = query(a, b, heights, sparseTable);
        }

        return res;
    }
};