class Solution {
public:
    string frequencySort(string s) {
        vector<int> cnt(128, 0);
        for(char c: s){
            ++cnt[c];
        }
        
        priority_queue<pair<int, char>> pq;
        for(unsigned char c = 0; c < cnt.size(); ++c){
            if(cnt[c]){
                pq.push({cnt[c], c});
            }
        }
        
        string answer;
        while(!pq.empty()){
            answer += string(pq.top().first, pq.top().second);
            pq.pop();
        }
        
        return answer;
    }
};