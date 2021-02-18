var math_wasm = require('./bin/math_wasm.js');
math_wasm().then((instance) => {

    var hrstart = process.hrtime()
    var value = instance._sin_taylor(3.141, 1);
    var hrend = process.hrtime(hrstart);
    console.log(value+" "+hrend[1]);
});