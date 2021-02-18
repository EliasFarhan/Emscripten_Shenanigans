#include <chrono>
#include <cmath>
#include "math_header.h"
#include <emscripten.h>

extern "C"
{
EMSCRIPTEN_KEEPALIVE
bool is_prime_wasm(unsigned int number)
{
	if(number < 2)
		return false;
	const unsigned int n = std::sqrt(number);
	if(number % 2 == 0)
		return false;
	for(unsigned i = 3; i <= n; i+=2)
	{
		if(number % i == 0)
			return false;
	}
	return true;
}
EMSCRIPTEN_KEEPALIVE
float average_wasm(const float* numbers, size_t length)
{
	float sum = 0.0f;
	for(size_t i = 0; i < length; i++)
	{
		sum += numbers[i];
	}
	return sum / length;
}
EMSCRIPTEN_KEEPALIVE
float sin_taylor(float x, size_t n)
{
	float result = 0.0f;
	for(size_t i = 0; i <= n; i++)
	{
		const float top = i%2==0 ? 1.0f : -1.0f;
		const float bottom = factorial(2.0f*i+1.0f);
		const float right = seq_pow(x, 2*i+1);
		result += top/bottom*right;
	}
	return result;
}

}
