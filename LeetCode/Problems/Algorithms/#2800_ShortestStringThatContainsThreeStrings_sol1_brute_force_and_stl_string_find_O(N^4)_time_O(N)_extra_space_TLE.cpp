class Solution {
public:
    string minimumString(string a, string b, string c) {
        string res = a + b + c;

        vector<string> v = {a, b, c};

        vector<int> p(3);
        iota(p.begin(), p.end(), 0);
        do{
            a = v[p[0]];
            b = v[p[1]];
            c = v[p[2]];

            string s;
            for(int i = 0; i <= (int)b.length(); ++i){
                for(int j = 0; j <= (int)c.length(); ++j){
                    s.clear();
                    copy(a.begin(), a.end(), back_inserter(s));
                    copy(b.begin() + i, b.end(), back_inserter(s));
                    copy(c.begin() + j, c.end(), back_inserter(s));
                    if(s.find(b) != string::npos && s.find(c) != string::npos){
                        if(s.size() < res.size() || (s.size() == res.size() && s < res)){
                            res = s;
                        }
                    }
                }
            }
        }while(next_permutation(p.begin(), p.end()));

        return res;
    }
};