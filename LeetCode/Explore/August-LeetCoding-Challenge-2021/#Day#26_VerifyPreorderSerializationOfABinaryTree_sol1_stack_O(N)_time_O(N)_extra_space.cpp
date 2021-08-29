class Solution {
public:
    bool isValidSerialization(string preorder) {
        const int N = preorder.size();
        string st;
        int i = 0;
        while(i < N){
            if(preorder[i] == '#'){
                st.push_back('#');
                i += 2;
            }else{
                st.push_back('x');
                while(i < N && isdigit(preorder[i])){
                    i += 1;
                }
                i += 1;
            }
            while(st.size() >= 3 && st[st.size() - 3] == 'x' && st[st.size() - 2] == '#' && st[st.size() - 1] == '#'){
                st.pop_back();
                st.pop_back();
                st.pop_back();
                st.push_back('#');
            }
        }
        return (st == "#");
    }
};