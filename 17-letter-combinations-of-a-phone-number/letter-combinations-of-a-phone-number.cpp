class Solution {
public:
    void solve(int index, string digits, map<char, string>& mp, string current, vector<string>& result) {
    // Base case
    if (index == digits.size()) {
        result.push_back(current);
        return;
    }

    string letters = mp[digits[index]];

    for (char ch : letters) {
        solve(index + 1, digits, mp, current + ch, result);
    }
}

vector<string> letterCombinations(string digits) {
    if (digits.empty()) return {};

    map<char, string> mp;

    mp['2'] = "abc";
    mp['3'] = "def";
    mp['4'] = "ghi";
    mp['5'] = "jkl";
    mp['6'] = "mno";
    mp['7'] = "pqrs";
    mp['8'] = "tuv";
    mp['9'] = "wxyz";

    vector<string> result;

    solve(0, digits, mp, "", result);

    return result;
}
};