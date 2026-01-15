class SegmentTree{
private:
    const int N;
    vector<pair<int, int>> tree;
    vector<int> lazy;

    void propagate(int node, int l, int r){
        tree[node].first += lazy[node];
        if(l != r){
            lazy[2 * node + 1] += lazy[node];
            lazy[2 * node + 2] += lazy[node];
        }
        lazy[node] = 0;
    }

    void aggregate(int node){
        tree[node] = min(tree[2 * node + 1], tree[2 * node + 2]);
        if(tree[2 * node + 1].first == tree[2 * node + 2].first){
            tree[node].second = tree[2 * node + 1].second + tree[2 * node + 2].second;
        }
    }

    void initTree(int node, int l, int r, const vector<int>& VALS){
        if(l == r){
            tree[node] = {0, VALS[min(r + 1, N - 1)] - VALS[r]};
        }else{
            int mid = (l + r) / 2;
            initTree(2 * node + 1, l, mid, VALS);
            initTree(2 * node + 2, mid + 1, r, VALS);
            aggregate(node);
        }
    }

    void add(int node, int l, int r, const int L, const int R, const int C){
        propagate(node, l, r);
        if(R < l || r < L){
            return;
        }
        if(L <= l && r <= R){
            lazy[node] += C;
            propagate(node, l, r);
            return;
        }
        int mid = (l + r) / 2;
        add(2 * node + 1, l, mid, L, R, C);
        add(2 * node + 2, mid + 1, r, L, R, C);
        aggregate(node);
    }

public:
    SegmentTree(const vector<int>& VALS): N(VALS.size()){
        int minLeaves = 1;
        while(minLeaves < N){
            minLeaves *= 2;
        }
        tree.assign(2 * minLeaves, {0, 0});
        lazy.assign(2 * minLeaves, 0);
        initTree(0, 0, N - 1, VALS);
    }

    int getGapSize(){
        if(tree[0].first == 0){
            return tree[0].second;
        }
        return 0;
    }

    void add(const int L, const int R, const int C){
        add(0, 0, N - 1, L, R, C);
    }
};

class Solution {
private:
    int compress(vector<int>& sortedValues, int val){
        return lower_bound(sortedValues.begin(), sortedValues.end(), val) - sortedValues.begin();
    }

public:
    double separateSquares(vector<vector<int>>& squares) {
        const int N = squares.size();

        // group segments by y coordinate
        using Event = array<int, 3>;
        map<int, vector<Event>> yToEvents;
        for(int i = 0; i < N; ++i){
            int x = squares[i][0];
            int y = squares[i][1];
            int len = squares[i][2];
            yToEvents[y].push_back({x, x + len, 1});
            yToEvents[y + len].push_back({x, x + len, -1});
        }

        // coordinate compression for x coordinates
        vector<int> xs(2 * N);
        for(int i = 0; i < N; ++i){
            int x = squares[i][0];
            int len = squares[i][2];
            xs[i] = x;
            xs[i + N] = x + len;
        }

        sort(xs.begin(), xs.end());
        xs.resize(unique(xs.begin(), xs.end()) - xs.begin());
        
        const int TOTAL_WIDTH = xs.back() - xs.front();

        // prepare the segment tree (using the compressed x coordinates)
        SegmentTree tree(xs);

        // sweep line
        vector<pair<int, int>> yws;
        for(auto& [currY, events]: yToEvents){
            yws.push_back({currY, TOTAL_WIDTH - tree.getGapSize()});
            for(Event& event: events){
                int x1 = event[0];
                int x2 = event[1];
                int eventType = event[2];
                tree.add(compress(xs, x1), compress(xs, x2) - 1, eventType);
            }
        }

        // compute the totalArea
        double totalArea = 0;
        for(int i = 1; i < (int)yws.size(); ++i){
            double prevY = yws[i - 1].first;
            double currY = yws[i].first;
            double currW = yws[i].second;
            totalArea += (currY - prevY) * currW;
        }

        // find the first y coordinate for which currArea >= totalArea / 2
        // and compute the result y'
        double currArea = 0;
        for(int i = 1; i < (int)yws.size(); ++i){
            double prevY = yws[i - 1].first;
            double currY = yws[i].first;
            double currW = yws[i].second;
            currArea += (currY - prevY) * currW;
            if(currArea >= totalArea / 2){
                return currY - (currArea - totalArea / 2) / currW;
            }
        }

        return -1;
    }
};