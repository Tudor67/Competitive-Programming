class Solution {
public:
    string removeKdigits(string num, int k) {
        const int N = num.length();
        
        // Step 1: remove digits
        vector<int> removed(N, false);
        priority_queue<pair<char, int>> pq;
        pq.push({num[0], 0});
        
        for(int i = 1; i < N; ++i){
            while(k > 0 && !pq.empty() && pq.top().first > num[i]){
                int max_pos = -pq.top().second;
                removed[max_pos] = true;
                pq.pop();
                k -= 1;
            }
            pq.push({num[i], -i});
        }
        
        while(k > 0){
            int max_pos = -pq.top().second;
            removed[max_pos] = true;
            pq.pop();
            k -= 1;
        }
        
        // remove leading zeros (if any)
        int start_pos = 0;
        while(start_pos < N && (num[start_pos] == '0' || removed[start_pos])){
            start_pos += 1;
        }
        
        // Step 2: create answer
        string answer;
        for(int i = start_pos; i < N; ++i){
            if(!removed[i]){
                answer += num[i];
            }
        }
        
        if(answer.empty()){
            answer = "0";
        }
        
        return answer;
    }
};