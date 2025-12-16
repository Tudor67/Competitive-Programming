class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        vector<int> p(events.size());
        iota(p.begin(), p.end(), 0);
        sort(p.begin(), p.end(),
             [&](int lhs, int rhs){
                char lhsEventType = events[lhs][0][0];
                int lhsTime = stoi(events[lhs][1]);
                char rhsEventType = events[rhs][0][0];
                int rhsTime = stoi(events[rhs][1]);
                return (pair<int, char>{-lhsTime, lhsEventType} >
                        pair<int, char>{-rhsTime, rhsEventType});
             });
        
        vector<int> count(numberOfUsers);
        vector<int> onTime(numberOfUsers);

        for(int i: p){
            string& message = events[i][0];
            int t = stoi(events[i][1]);
            string& mentionStr = events[i][2];

            if(message == "MESSAGE"){
                if(mentionStr == "ALL"){
                    for(int user = 0; user < numberOfUsers; ++user){
                        count[user] += 1;
                    }
                }else if(mentionStr == "HERE"){
                    for(int user = 0; user < numberOfUsers; ++user){
                        if(onTime[user] <= t){
                            count[user] += 1;
                        }
                    }
                }else{
                    istringstream iss(mentionStr);
                    string userStr;
                    while(iss >> userStr){
                        int user = stoi(userStr.substr(2));
                        count[user] += 1;
                    }
                }
            }else if(message == "OFFLINE"){
                onTime[stoi(mentionStr)] = t + 60;
            }
        }
        
        return count;
    }
};