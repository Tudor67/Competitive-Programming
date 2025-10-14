class Solution {
private:
    int find(int i, vector<int>& nxt){
        if(i != nxt[i]){
            nxt[i] = find(nxt[i], nxt);
        }
        return nxt[i];
    }

public:
    vector<int> avoidFlood(vector<int>& rains) {
        const int R = rains.size();

        vector<int> nxt(R + 1);
        nxt[R] = R;
        for(int i = 0; i < R; ++i){
            if(rains[i] == 0){
                nxt[i] = i;
            }else{
                nxt[i] = i + 1;
            }
        }

        vector<int> ans(R, -1);
        unordered_map<int, int> prevIndexOf;

        for(int i = 0; i < R; ++i){
            if(rains[i] == 0){
                ans[i] = 1;
                continue;
            }
            
            int lake = rains[i];
            if(prevIndexOf.count(lake)){
                int j = find(prevIndexOf[lake], nxt);
                if(j > i){
                    return {};
                }
                ans[j] = lake;
                nxt[j] = j + 1;
            }

            prevIndexOf[lake] = i;
        }

        return ans;
    }
};