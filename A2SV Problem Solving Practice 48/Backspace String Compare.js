/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var backspaceCompare = function (s, t) {
  const process = (str) => {
    const stack = [];
    for (let char of str) {
      if (char === "#") {
        if (stack.length > 0) {
          stack.pop();
        }
      } else {
        stack.push(char);
      }
    }
    return stack.join("");
  };
  return process(s) === process(t);
};
