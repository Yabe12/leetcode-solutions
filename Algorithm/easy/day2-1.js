// 
/**
 * @param {string} s
 * @return {number}
 */
var romanToInt = function (s) {
  let x = 0;
  const num = {
      'I': 1,
      'V': 5,
      'X': 10,
      'L': 50,
      'C': 100,
      'D': 500,
      'M': 1000
  }
  for (let i = 0; i <= s.length-1; i++) {
      if (num[s[i]] < num[s[i + 1]]) {
          x -= num[s[i]]
      }
      else {
          x += num[s[i]]
      }
  }

  return x;
};
//  /**
//  * @param {string} s
//  * @return {number}
//  */
// var romanToInt = function (s) {
//   let x = 0;
//   const num = {
//       'I': 1,
//       'V': 5,
//       'X': 10,
//       'L': 50,
//       'C': 100,
//       'D': 500,
//       'M': 1000
//   }
//   for (let i = 0; i <= s.length-1; i++) {
//       if (num[s[i]] < num[s[i + 1]]) {
//           x -= num[s[i]]
//       }
//       else {
//           x += num[s[i]]
//       }
//   }

//   return x;
// };