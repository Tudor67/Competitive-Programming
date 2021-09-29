class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> uniqueEmails;
        for(const string& ORIGINAL_EMAIL: emails){
            string email;
            bool isDomainName = false;
            bool visitedPlus = false;
            for(char c: ORIGINAL_EMAIL){
                isDomainName |= (c == '@');
                visitedPlus |= (c == '+');
                if(isDomainName || (!visitedPlus && c != '.')){
                    email += c;
                }
            }
            uniqueEmails.insert(email);
        }
        return uniqueEmails.size();
    }
};