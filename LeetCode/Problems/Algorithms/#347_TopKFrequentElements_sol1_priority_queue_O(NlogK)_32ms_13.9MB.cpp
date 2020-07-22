class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        for(int num: nums){
            cnt[num] += 1;
        }
        
        priority_queue<pair<int, int>> pq;
        for(int num: nums){
            if(cnt.count(num)){
                pq.push({-cnt[num], num});
                if(pq.size() > k){
                    pq.pop();
                }
                cnt.erase(num);
            }
        }
        
        vector<int> answer;
        while(!pq.empty()){
            answer.push_back(pq.top().second);
            pq.pop();
        }
        
        return answer;
    }
};