/**
 * @return {Function}
 */
var createHelloWorld = function() {
    
    return (...args) => "Hello World";
};

/**
 * const f = createHelloWorld();
 * f(); // "Hello World"
 */