class Solution {
public:
bool isMatch(string word, string pattern) {
    map<char, char> mp1; // word → pattern
    map<char, char> mp2; // pattern → word

    for (int i = 0; i < word.size(); i++) {
        char w = word[i];
        char p = pattern[i];

        if (mp1.count(w) && mp1[w] != p) return false;
        if (mp2.count(p) && mp2[p] != w) return false;

        mp1[w] = p;
        mp2[p] = w;
    }

    return true;
}

vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
    vector<string> result;

    for (string word : words) {
        if (isMatch(word, pattern)) {
            result.push_back(word);
        }
    }

    return result;
}
};