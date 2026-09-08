class Solution {
public:
    bool isIsomorphic(string s, string t) {

        int Smap[256] = {0};
        int Tmap[256] = {0};

        for (int i = 0; i < s.length(); i++) {

            if (Smap[s[i]] != 0 || Tmap[t[i]] != 0) {

                if (Smap[s[i]] != t[i] + 1 ||
                    Tmap[t[i]] != s[i] + 1) {
                    return false;
                }

            } else {

                Smap[s[i]] = t[i] + 1;
                Tmap[t[i]] = s[i] + 1;
            }
        }

        return true;
    }
};