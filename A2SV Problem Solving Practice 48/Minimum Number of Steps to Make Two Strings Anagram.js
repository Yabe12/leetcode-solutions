/**
 * @param {string} s
 * @param {string} t
 * @return {number}
 */
var minSteps = function(s, t) {

    const sCount = new Map();
    const tCount = new Map();
    
    for (const char of s) {
        sCount.set(char, (sCount.get(char) || 0) + 1);
    }
    
    for (const char of t) {
        tCount.set(char, (tCount.get(char) || 0) + 1);
    }
    
 
    let replacements = 0;
    
    for (const [char, count] of tCount) {
        if (sCount.has(char)) {
          
            if (count > sCount.get(char)) {
                replacements += count - sCount.get(char);
            }
        } else {
            
            replacements += count;
        }
    }
    
    return replacements;
};
