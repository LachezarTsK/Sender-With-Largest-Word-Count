
import java.util.HashMap;
import java.util.Map;

public class Solution {

    public String largestWordCount(String[] messages, String[] senders) {
        final int inputSize = messages.length;
        int largestWordCount = 0;
        String lexicographicallyLargestName = "";
        Map<String, Integer> nameToWordCount = new HashMap<>();

        for (int i = 0; i < inputSize; ++i) {
            nameToWordCount.putIfAbsent(senders[i], 0);
            nameToWordCount.put(senders[i], nameToWordCount.get(senders[i]) + countNumberOfWords(messages[i]));

            if (largestWordCount < nameToWordCount.get(senders[i])) {
                largestWordCount = nameToWordCount.get(senders[i]);
                lexicographicallyLargestName = senders[i];
            } else if (largestWordCount == nameToWordCount.get(senders[i]) && lexicographicallyLargestName.compareTo(senders[i]) < 0) {
                lexicographicallyLargestName = senders[i];
            }
        }
        return lexicographicallyLargestName;
    }

    private int countNumberOfWords(String message) {
        int wordCount = 1;
        for (int i = 0; i < message.length(); ++i) {
            if (message.charAt(i) == ' ') {
                ++wordCount;
            }
        }
        return wordCount;
    }
}
