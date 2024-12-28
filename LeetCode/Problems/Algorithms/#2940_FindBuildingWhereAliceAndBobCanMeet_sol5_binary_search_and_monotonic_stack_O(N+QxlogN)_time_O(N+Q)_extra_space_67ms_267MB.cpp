class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        const int N = heights.size();
        const int Q = queries.size();

        vector<vector<pair<int, int>>> queriesAt(N);
        for(int queryIndex = 0; queryIndex < Q; ++queryIndex){
            int a = queries[queryIndex][0];
            int b = queries[queryIndex][1];
            
            if(a > b){
                swap(a, b);
            }
            
            int threshold = 1 + max(heights[a], heights[b]);
            if(a == b || heights[a] < heights[b]){
                threshold = heights[b];
            }

            queriesAt[b].push_back({threshold, queryIndex});
        }

        vector<int> res(Q, -1);
        vector<int> st;
        for(int i = N - 1; i >= 0; --i){
            while(!st.empty() && heights[i] >= heights[st.back()]){
                st.pop_back();
            }
            st.push_back(i);

            for(auto [threshold, queryIndex]: queriesAt[i]){
                int l = 0;
                int r = st.size() - 1;
                while(l != r){
                    int mid = (l + r + 1) / 2;
                    if(threshold <= heights[st[mid]]){
                        l = mid;
                    }else{
                        r = mid - 1;
                    }
                }

                if(threshold <= heights[st[r]]){
                    res[queryIndex] = st[r];
                }
            }
        }

        return res;
    }
};