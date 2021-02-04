emcc -O3 prime_number_wasm.cpp -c -o prime_number_wasm.o
emcc -O3 main.cpp -c -o main.o
emcc prime_number_wasm.o main.o -o prime.js --js-library prime_number.js
