class Solution {
public:
    int ladderLength(string begi, string endw, vector<string>& s) {

        unordered_set<string> st(s.begin(), s.end());

        if (st.find(endw) == st.end()) {
            return 0;
        }

        queue<string> q;
        q.push(begi);

        int count = 1;

        while (!q.empty()) {

            int size = q.size();

            while (size--) {

                string word = q.front();
                q.pop();

                if (word == endw) {
                    return count;
                }

                for (int i = 0; i < word.size(); i++) {

                    char orig = word[i];

                    for (char ch = 'a'; ch <= 'z'; ch++) {

                        word[i] = ch;

                        if (st.find(word) != st.end()) {
                            q.push(word);
                            st.erase(word);
                        }
                    }

                    word[i] = orig;
                }
            }

            count++;
        }

        return 0;
    }
};