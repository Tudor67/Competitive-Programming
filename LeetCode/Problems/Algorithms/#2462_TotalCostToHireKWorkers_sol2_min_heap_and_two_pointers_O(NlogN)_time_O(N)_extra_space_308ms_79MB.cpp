class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        const int N = costs.size();

        enum Direction { LEFT, RIGHT };
        using T3 = tuple<int, int, Direction>;
        priority_queue<T3, vector<T3>, greater<T3>> minHeap;

        int l = 0;
        while(l <= candidates - 1){
            minHeap.push({costs[l], l, Direction::RIGHT});
            l += 1;
        }

        int r = N - 1;
        while(N - candidates <= r && l <= r){
            minHeap.push({costs[r], r, Direction::LEFT});
            r -= 1;
        }
        
        long long res = 0;
        while(k >= 1){
            k -= 1;

            int i = get<1>(minHeap.top());
            int direction = get<2>(minHeap.top());
            minHeap.pop();

            res += costs[i];

            if(direction == Direction::RIGHT && l <= r){
                minHeap.push({costs[l], l, Direction::RIGHT});
                l += 1;
            }else if(direction == Direction::LEFT && l <= r){
                minHeap.push({costs[r], r, Direction::LEFT});
                r -= 1;
            }
        }

        return res;
    }
};