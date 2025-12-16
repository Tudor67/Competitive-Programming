class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        int allMentionsCount = 0;
        vector<int> hs;
        vector<int> count(numberOfUsers);

        for(vector<string>& event: events){
            string& message = event[0];
            int t = stoi(event[1]);
            string& mentionStr = event[2];

            if(message[0] == 'M'){
                if(mentionStr[0] == 'A'){
                    allMentionsCount += 1;
                }else if(mentionStr[0] == 'H'){
                    allMentionsCount += 1;
                    hs.push_back(t);
                }else{
                    istringstream iss(mentionStr);
                    string userStr;
                    while(iss >> userStr){
                        int userId = stoi(userStr.substr(2));
                        count[userId] += 1;
                    }
                }
            }
        }

        sort(hs.begin(), hs.end());

        for(vector<string>& event: events){
            string& message = event[0];
            int t = stoi(event[1]);

            if(message[0] == 'O'){
                int userId = stoi(event[2]);
                count[userId] -= lower_bound(hs.begin(), hs.end(), t + 60) -
                                 lower_bound(hs.begin(), hs.end(), t);
            }
        }

        for(int userId = 0; userId < numberOfUsers; ++userId){
            count[userId] += allMentionsCount;
        }

        return count;
    }
};