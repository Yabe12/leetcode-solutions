// 


/**
 * @param {string} haystack
 * @param {string} needle
 * @return {number}
 */
var strStr = function(haystack, needle) {
  for (i=0 ; i <= haystack.length ; i++){
      if (haystack.substring(i, i+ needle.length) === needle){
          return i;
      }
  }
  return -1;
};