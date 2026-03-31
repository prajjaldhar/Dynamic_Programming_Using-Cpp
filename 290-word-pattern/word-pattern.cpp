class Solution {
public:
    bool wordPattern(string pattern, string s) {
            vector<string> words;
    string word;
    
    // Split string by space
    stringstream ss(s);
    while (ss >> word) {
        words.push_back(word);
    }

    // Length mismatch → false
    if (pattern.size() != words.size()) return false;

    map<char, string> mp1;   // char → word
    map<string, char> mp2;   // word → char

    for (int i = 0; i < pattern.size(); i++) {
        char ch = pattern[i];
        string w = words[i];

        // Check mapping consistency
        if (mp1.count(ch) && mp1[ch] != w) return false;
        if (mp2.count(w) && mp2[w] != ch) return false;

        mp1[ch] = w;
        mp2[w] = ch;
    }

    return true;

    }
};