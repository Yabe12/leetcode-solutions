/**
 * @param {string} s
 * @return {string}
 */
var longestNiceSubstring = function(s) {
    const isNice = (str) => {
        const lowerSet = new Set();
        const upperSet = new Set();
        
        for (const char of str) {
            if (char >= 'a' && char <= 'z') {
                lowerSet.add(char);
            } else if (char >= 'A' && char <= 'Z') {
                upperSet.add(char);
            }
        }
        
        for (const char of lowerSet) {
            if (!upperSet.has(char.toUpperCase())) {
                return false;
            }
        }
        
        for (const char of upperSet) {
            if (!lowerSet.has(char.toLowerCase())) {
                return false;
            }
        }
        
        return true;
    };
    
    let longestSubstring = '';
    
    for (let start = 0; start < s.length; start++) {
        for (let end = start + 1; end <= s.length; end++) {
            const substring = s.slice(start, end);
            if (isNice(substring) && substring.length > longestSubstring.length) {
                longestSubstring = substring;
            }
        }
    }
    
    return longestSubstring;
};
