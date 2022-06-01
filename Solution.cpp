
#include <vector>
#include <string>
#include <iterator>
#include <string_view>
#include <unordered_map>
using namespace std;

class Solution {
    
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        const size_t inputSize = messages.size();
        int largestWordCount = 0;
        string lexicographicallyLargestName;
        unordered_map<string, int> nameToWordCount;

        for (int i = 0; i < inputSize; ++i) {

            nameToWordCount[senders[i]] = nameToWordCount[senders[i]] + countNumberOfWords(messages[i]);

            if (largestWordCount < nameToWordCount[senders[i]]) {
                largestWordCount = nameToWordCount[senders[i]];
                lexicographicallyLargestName = senders[i];
            } else if (largestWordCount == nameToWordCount[senders[i]] && lexicographicallyLargestName < senders[i]) {
                lexicographicallyLargestName = senders[i];
            }
        }
        return lexicographicallyLargestName;
    }

private:
    //  C++17, 'string_view': a good alternative to both 'const string&' and 'const char*'.
    // 'string_view' is cheap to copy: it contains only a pointer to the input and its length.
    int countNumberOfWords(string_view message) {
        return count_if(message.begin(), message.end(), [](int character){return character == ' '; }) + 1;
    }
};
