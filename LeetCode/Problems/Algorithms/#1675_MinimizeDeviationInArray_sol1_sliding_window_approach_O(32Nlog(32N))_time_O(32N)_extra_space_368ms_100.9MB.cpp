class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        const int N = nums.size();
        
        vector<pair<int, int>> v;
        for(int i = 0; i < N; ++i){
            int num = nums[i];
            v.push_back({num, i});
            if(num % 2 == 1){
                v.push_back({2 * num, i});
            }else{
                while(num % 2 == 0){
                    num /= 2;
                    v.push_back({num, i});
                }
            }
        }
        
        sort(v.begin(), v.end());
        
        int answer = INT_MAX;
        int distinctIds = 0;
        vector<int> count(N + 1, 0);
        for(int i = 0, j = 0; j < v.size(); ++j){
            count[v[j].second] += 1;
            distinctIds += (count[v[j].second] == 1);
            while(count[v[i].second] >= 2){
                count[v[i].second] -= 1;
                i += 1;
            }
            if(distinctIds == N){
                answer = min(v[j].first - v[i].first, answer);
            }
        }
        
        return answer;
    }
};