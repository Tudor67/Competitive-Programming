class Solution {
private:
    long long getSum(vector<long long>& prefSum, int l, int r){
        if(l > r){
            return 0;
        }
        if(l == 0){
            return prefSum[r];
        }
        return prefSum[r] - prefSum[l - 1];
    }
    
public:
    vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& removeQueries) {
        const int N = nums.size();
        
        vector<long long> prefSum(N);
        prefSum[0] = nums[0];
        for(int i = 1; i < N; ++i){
            prefSum[i] = prefSum[i - 1] + nums[i];
        }
        
        set<tuple<long long, int, int>> slrSet;
        slrSet.emplace(getSum(prefSum, 0, N - 1), 0, N - 1);
        set<int> qSet = {-1, N};
        
        vector<long long> res(N);
        for(int i = 0; i < N - 1; ++i){
            int mid = removeQueries[i];
            set<int>::iterator it = qSet.upper_bound(mid);
            int l = *prev(it) + 1;
            int r = *it - 1;
            
            slrSet.erase({getSum(prefSum, l, r), l, r});
            if(l <= mid - 1){
                slrSet.emplace(getSum(prefSum, l, mid - 1), l, mid - 1);
            }
            if(mid + 1 <= r){
                slrSet.emplace(getSum(prefSum, mid + 1, r), mid + 1, r);
            }
            
            qSet.insert(mid);
            
            res[i] = get<0>(*prev(slrSet.end()));
        }
        
        return res;
    }
};