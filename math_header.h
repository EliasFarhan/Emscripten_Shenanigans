#pragma once

#include <emscripten/val.h>

extern "C"
{
bool is_prime_wasm(unsigned int number);
bool is_prime_js(unsigned int number);

float average_wasm(const float* numbers, size_t length);
float average_js(emscripten::val numbers);

float sin_taylor(float x, size_t n);


}

template<typename T>
T factorial(T n)
{
    T result = 1;
    for(T i = 2; i <= n; i++)
    {
        result *= i;
    }
    return result;
}

template<typename T>
T seq_pow(T x, size_t n)
{
    T result = 1;
    for(size_t i = 0; i < n; i++)
    {
        result *= x;
    }
    return result;
}
