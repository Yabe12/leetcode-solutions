
```
/**
 * @return {Function}
 */
var createHelloWorld = function() {
  
    return function(...args) {
          return  "Hello World";
    };
}
const f = createHelloWorld ();
console.log(f())

/**
 * const f = createHelloWorld();
 * f(); // "Hello World"
 */
```


/**
 * @return {Function}
 */
var createHelloWorld = function() {
  
    return function(...args) {
          return  "Hello World";
    };
}
const f = createHelloWorld ();
console.log(f())

/**
 * const f = createHelloWorld();
 * f(); // "Hello World"
 */