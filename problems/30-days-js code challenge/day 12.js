function memoize(fn) {
    const cache = new Map();
    let callCount = 0;

    function memoized(...args) {
        const key = JSON.stringify(args); // Convert arguments to a string for caching
        if (cache.has(key)) {
            return cache.get(key);
        }
        callCount++;
        const result = fn(...args);
        cache.set(key, result);
        return result;
    }

    memoized.getCallCount = function() {
        return callCount;
    };

    return memoized;
}

// Function implementations
const sum = (a, b) => a + b;
const factorial = (n) => (n <= 1 ? 1 : n * factorial(n - 1));
const fib = (n) => (n <= 1 ? 1 : fib(n - 1) + fib(n - 2));

// Memoize functions
const memoSum = memoize(sum);
const memoFactorial = memoize(factorial);
const memoFib = memoize(fib);

// Main function to handle the actions
function executeActions(fnName, actions, values) {
    let results = [];

    let fn;
    switch (fnName) {
        case "sum":
            fn = memoSum;
            break;
        case "factorial":
            fn = memoFactorial;
            break;
        case "fib":
            fn = memoFib;
            break;
    }

    for (let i = 0; i < actions.length; i++) {
        if (actions[i] === "call") {
            const args = values[i];
            results.push(fn(...args));
        } else if (actions[i] === "getCallCount") {
            results.push(fn.getCallCount());
        }
    }

    return results;
}
