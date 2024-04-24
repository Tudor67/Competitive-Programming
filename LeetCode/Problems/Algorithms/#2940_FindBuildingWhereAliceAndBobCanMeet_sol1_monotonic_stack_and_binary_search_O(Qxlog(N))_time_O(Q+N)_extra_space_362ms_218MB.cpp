class Solution {
private:
    int query(vector<int>& currentQuery, vector<int>& heights, vector<int>& st){
        int a = currentQuery[0];
        int b = currentQuery[1];

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
        int l = 0;
        int r = (int)st.size() - 1;
        while(l != r){
            int mid = (l + r + 1) / 2;
            if(threshold < heights[st[mid]]){
                l = mid;
            }else{
                r = mid - 1;
            }
        }

        if(threshold < heights[st[r]]){
            return st[r];
        }

        // Case 4
        return -1;
    }

public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        const int N = heights.size();
        const int Q = queries.size();
        
        unordered_map<int, vector<int>> queryIndicesAt;
        for(int queryIndex = 0; queryIndex < Q; ++queryIndex){
            int a = queries[queryIndex][0];
            int b = queries[queryIndex][1];
            queryIndicesAt[max(a, b)].push_back(queryIndex);
        }
        
        vector<int> res(Q);
        vector<int> st;
        for(int i = N - 1; i >= 0; --i){
            while(!st.empty() && heights[i] >= heights[st.back()]){
                st.pop_back();
            }
            st.push_back(i);
            
            for(int queryIndex: queryIndicesAt[i]){
                res[queryIndex] = query(queries[queryIndex], heights, st);
            }
        }
        
        return res;
    }
};