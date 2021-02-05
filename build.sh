mkdir obj bin
em++ -O3 math_wasm.cpp -c -o obj/math_wasm.o -fno-exceptions -flto
echo "Compiling math_wasm.cpp"
em++ -O3 prime.cpp -c -o obj/prime.o  -fno-exceptions -flto
echo "Compiling prime.cpp"
em++ -O3 average.cpp -c -o obj/average.o --bind -fno-exceptions -flto
echo "Compiling average.cpp"
#linking
em++ obj/math_wasm.o obj/prime.o -o bin/prime.js --js-library math_js.js -fno-exceptions -flto
echo "Link prime.js"
em++ obj/math_wasm.o obj/average.o -o bin/average.js --js-library math_js.js -fno-exceptions -flto --bind
echo "Link average.js"
