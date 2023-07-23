class Solution {
private:
    bool collide(int firstAsteroid, int secondAsteroid){
        return (firstAsteroid > 0 && secondAsteroid < 0);
    }

public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        const int N = asteroids.size();

        vector<int> st;
        for(int a: asteroids){
            while(!st.empty() && collide(st.back(), a) && st.back() < -a){
                st.pop_back();
            }
            if(st.empty() || !collide(st.back(), a)){
                st.push_back(a);
            }else if(st.back() == -a){
                st.pop_back();
            }
        }

        return st;
    }
};