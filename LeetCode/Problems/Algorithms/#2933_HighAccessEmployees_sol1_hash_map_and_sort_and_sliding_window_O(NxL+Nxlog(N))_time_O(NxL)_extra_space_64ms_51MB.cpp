class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& accessTimes) {
        const int N = accessTimes.size();
        
        unordered_map<string, vector<int>> employeeToTimes;
        for(int i = 0; i < N; ++i){
            string employee = accessTimes[i][0];
            string hhmm = accessTimes[i][1];
            int t = stoi(hhmm.substr(0, 2)) * 60 + stoi(hhmm.substr(2));
            employeeToTimes[employee].push_back(t);
        }
        
        vector<string> res;
        for(const pair<const string, vector<int>>& P: employeeToTimes){
            string employee = P.first;
            vector<int> times = P.second;
            
            if((int)times.size() >= 3){
                sort(times.begin(), times.end());
                for(int i = 2; i < (int)times.size(); ++i){
                    if(times[i] - times[i - 2] < 60){
                        res.push_back(employee);
                        break;
                    }
                }
            }
        }
        
        return res;
    }
};