#include <chrono>
#include <cmath>
#include "math_header.h"

extern "C"
{

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

float average_wasm(const float* numbers, size_t length)
{
	float sum = 0.0f;
	for(size_t i = 0; i < length; i++)
	{
		sum += numbers[i];
	}
	return sum / length;
}

}
