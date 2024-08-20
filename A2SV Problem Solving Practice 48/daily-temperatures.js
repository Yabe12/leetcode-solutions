/**
 * @param {number[]} temperatures
 * @return {number[]}
 */
var dailyTemperatures = function (temperatures) {
  var n = temperatures.length;
  var answer = new Array(n).fill(0);
  var stack = [];

  for (var i = 0; i < n; i++) {
    var temp = temperatures[i];
    while (stack.length > 0 && temperatures[stack[stack.length - 1]] < temp) {
      var index = stack.pop();
      answer[index] = i - index;
    }
    stack.push(i);
  }

  return answer;
};
