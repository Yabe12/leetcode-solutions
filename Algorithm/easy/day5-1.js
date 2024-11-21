//

// *******1st********************************
/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLastWord = function(s) {
  let x= s.length-1;
const words = s.trim().split(" " );
 return words[words.length - 1].length;
};
