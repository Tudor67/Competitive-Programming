class Solution {
public:
    long long makeSubKSumEqual(vector<int>& arr, int k) {
        const int N = arr.size();

        long long res = 0;
        vector<bool> vis(N, false);

        for(int startIndex = 0; startIndex < k; ++startIndex){
            if(vis[startIndex]){
                continue;
            }

            vector<int> v;
            for(int i = startIndex; !vis[i]; i = (i + k) % N){
                vis[i] = true;
                v.push_back(arr[i]);
            }

            sort(v.begin(), v.end());

            long long median = v[v.size() / 2];
            for(long long elem: v){
                res += abs(median - elem);
            }
        }

        return res;
    }
};