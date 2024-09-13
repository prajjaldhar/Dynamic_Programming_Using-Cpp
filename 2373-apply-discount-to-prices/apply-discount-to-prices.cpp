class Solution {
public:
    bool isPrice(const string &word) {
    // Check if the word starts with a '$' and the rest are digits
    if (word[0] != '$') return false;
    if (word.size() == 1) return false;  // "$" is not a valid price
    for (int i = 1; i < word.size(); ++i) {
        if (!isdigit(word[i])) return false;
    }
    return true;
}
    string discountPrices(string sentence, int discount) {
        istringstream iss(sentence);
        string word;
        ostringstream oss;
        bool firstWord = true;

        while (iss >> word) {
            if (!firstWord) {
                oss << " ";  // Add a space before appending a new word
            }
            firstWord = false;

            // Check if the current word is a valid price
            if (isPrice(word)) {
                // Convert the word to a numeric value after removing the '$'
                string priceStr = word.substr(1);
                double price = stod(priceStr);

                // Apply the discount
                double discountedPrice = price * (1 - discount / 100.0);

                // Format the discounted price to 2 decimal places
                oss << "$" << fixed << setprecision(2) << discountedPrice;
            } else {
                // Not a price, just append the word as it is
                oss << word;
            }
        }
        return oss.str();
    }
};