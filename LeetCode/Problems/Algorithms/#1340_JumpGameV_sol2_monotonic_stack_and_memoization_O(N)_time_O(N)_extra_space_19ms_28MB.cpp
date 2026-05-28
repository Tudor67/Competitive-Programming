class Solution {
private:
    using Graph = vector<vector<int>>;
    const int INF = 1e9;

    int computeMaxLen(int i, const Graph& G, vector<int>& memo){
        if(memo[i] != INF){
            return memo[i];
        }
        int maxLen = 1;
        for(int j: G[i]){
            maxLen = max(maxLen, 1 + computeMaxLen(j, G, memo));
        }
        memo[i] = maxLen;
        return maxLen;
    }

public:
    int maxJumps(vector<int>& arr, int d) {
        const int N = arr.size();

        // Step 1: nextGreater and prevGreater with monotonic stacks
        stack<int> st;
        vector<int> nextGreater(N, INF);
        for(int i = 0; i < N; ++i){
            while(!st.empty() && arr[st.top()] < arr[i]){
                nextGreater[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        while(!st.empty()){
            st.pop();
        }

        vector<int> prevGreater(N, INF);
        for(int i = N - 1; i >= 0; --i){
            while(!st.empty() && arr[i] > arr[st.top()]){
                prevGreater[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        // Step 2: build graph G (keep only valid edges/arcs)
        Graph G(N);
        for(int i = 0; i < N; ++i){
            for(int j: {prevGreater[i], nextGreater[i]}){
                if(j != INF && abs(i - j) <= d){
                    G[i].push_back(j);
                }
            }
        }

        // Step 3: compute the longest increasing path using memoization
        int maxLen = 0;
        vector<int> memo(N, INF);
        for(int i = 0; i < N; ++i){
            maxLen = max(maxLen, computeMaxLen(i, G, memo));
        }

        return maxLen;
    }
};