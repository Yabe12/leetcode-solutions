// 
/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function(strs) {
  if (strs.length === 0) return ""; 
  let prefix = strs[0];
  let pre = prefix.length;

  for (let i = 1; i < strs.length; i++) { 
      let s = strs[i];
      while (prefix !== s.substring(0, pre)) { 
          pre--; 
          if (pre === 0) return ""; 
          prefix = prefix.substring(0, pre);
      }
  }

  return prefix; 
};
