
/**
 * @param {string[]} messages
 * @param {string[]} senders
 * @return {string}
 */
var largestWordCount = function (messages, senders) {
    const inputSize = messages.length;
    let largestWordCount = 0;
    let lexicographicallyLargestName = "";
    const nameToWordCount = new Map();

    for (let i = 0; i < inputSize; ++i) {
        if (!nameToWordCount.has(senders[i])) {
            nameToWordCount.set(senders[i], 0);
        }
        nameToWordCount.set(senders[i], nameToWordCount.get(senders[i]) + countNumberOfWords(messages[i]));

        if (largestWordCount < nameToWordCount.get(senders[i])) {
            largestWordCount = nameToWordCount.get(senders[i]);
            lexicographicallyLargestName = senders[i];
        } else if (largestWordCount === nameToWordCount.get(senders[i]) && lexicographicallyLargestName < senders[i]) {
            lexicographicallyLargestName = senders[i];
        }
    }
    return lexicographicallyLargestName;
};

/**
 * @param {string} message
 * @return {number}
 */
function  countNumberOfWords(message) {
    let wordCount = 1;
    for (let i = 0; i < message.length; ++i) {
        if (message.charAt(i) === ' ') {
            ++wordCount;
        }
    }
    return wordCount;
}
