class Solution {
public:
    string minWindow(string s, string t) {

        unordered_map<char,int> freq;
        unordered_map<char,int> freq1;

        int have = 0;

        for(int i = 0; i < t.size(); i++){
            freq[t[i]]++;
        }

        int h = freq.size();
        int l = 0;

        int bestStart = 0;
        int bestLen = INT_MAX;

        for(int r = 0; r < s.size(); r++){

            freq1[s[r]]++;

            if(freq.count(s[r]) && freq1[s[r]] == freq[s[r]]){
                have++;
            }

            while(have == h){

                // Just remember indices, DON'T create substring
                if(r - l + 1 < bestLen){
                    bestLen = r - l + 1;
                    bestStart = l;
                }

                freq1[s[l]]--;

                if(freq.count(s[l]) && freq1[s[l]] < freq[s[l]]){
                    have--;
                }

                l++;
            }
        }

        if(bestLen == INT_MAX)
            return "";

        return s.substr(bestStart, bestLen);
    }
};