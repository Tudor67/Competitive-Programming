class Solution {
private:
    void addVal(vector<long long>& delta, int l, int r, long long val){
        delta[l] += val;
        delta[r + 1] -= val;
    }

public:
    vector<long long> countOfPairs(int n, int x, int y) {
        // Step 0: nodes [x .. y] form a cycle of size (y - x + 1)
        if(x > y){
            swap(x, y);
        }

        // Step 1: standard case (cycleSize <= 2)
        //         res[i] = 2 * (n - 1 - i)
        int cycleSize = y - x + 1;
        if(cycleSize <= 2){
            vector<long long> res(n);
            for(int i = 0; i < n; ++i){
                res[i] = 2 * (n - 1 - i);
            }
            return res;
        }

        // Step 2: compute the contribution of shortest paths starting and ending outside the range [x + 1 .. y - 1]
        vector<long long> delta(n + 1);
        for(int node = 1; node <= n; ++node){
            if(node <= x){
                addVal(delta, 1, n - (cycleSize - 1) - (node - 1), 2);
            }else if(y <= node){
                addVal(delta, 1, n - node, 2);
            }
        }

        // remove the contribution (shortest dist = 1, contrib = 2) of the pairs [x, y] and [y, x]
        addVal(delta, 1, 1, -2);

        // Step 3: compute the contribution of shortest paths starting and ending inside the cycle [x .. y]
        addVal(delta, 1, cycleSize / 2, 2 * cycleSize);

        if(cycleSize % 2 == 0){
            addVal(delta, cycleSize / 2, cycleSize / 2, -cycleSize);
        }

        // Step 4: compute the contribution of shortest paths starting inside the cycle [x .. y]
        //                                                 and ending outside the cycle [x .. y]
        for(int dist = 1; dist <= cycleSize / 2; ++dist){
            int val = 4;
            if((dist == 1) || (dist == cycleSize / 2 && cycleSize % 2 == 0)){
                val = 2;
            }
            addVal(delta, dist + 1, dist + (x - 1), val);
            addVal(delta, dist + 1, dist + (n - y), val);
        }

        // Step 5: compute the prefix sum of the difference array delta
        //         and update the result
        vector<long long> res(n);
        for(int dist = 1; dist < n; ++dist){
            delta[dist] += delta[dist - 1];
            res[dist - 1] = delta[dist];
        }

        return res;
    }
};