/**
 * @param {string} s
 * @return {character}
 */
var repeatedCharacter = function(s) {
    const seen = new Set(); 

    for (const char of s) {
        if (seen.has(char)) {
            return char; 
        }
        seen.add(char); 
    }

};
