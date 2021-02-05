#pragma once

#include <emscripten/val.h>

extern "C"
{
bool is_prime_wasm(unsigned int number);
bool is_prime_js(unsigned int number);

float average_wasm(const float* numbers, size_t length);
float average_js(emscripten::val numbers);
}
