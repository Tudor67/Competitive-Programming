class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> answer(queries.size());
        
        for(int q_id = 0; q_id < queries.size(); ++q_id){
            string query = queries[q_id];
            bool match = true;
            int j = 0;
            for(int i = 0; match && i < query.length(); ++i){
                // Case 1
                if(j == pattern.length()){
                    if(islower(query[i])){
                        continue;
                    }else{
                        match = false;
                    }
                }
                // Case 2
                if(query[i] == pattern[j]){
                    ++j;
                }else if(isupper(query[i])){
                    match = false;
                }
            }
            answer[q_id] = (match && j == pattern.length());
        }
        
        return answer;
    }
};