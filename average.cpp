#include <iostream>
#include <cstdlib>
#include <chrono>
#include <random>
#include "math_header.h"
#include <emscripten.h>

extern "C"
{
EM_JS(void, call_alert, (), {
  alert('hello world!');
  throw 'all done';
});
}
int main(int argc, char** argv)
{
    std::vector<float> numbers(1024);
    std::default_random_engine generator;
    std::uniform_real_distribution<float> distribution(-100.0f,100.0f);
    std::for_each(numbers.begin(), numbers.end(), [&distribution, &generator](float& n){ n = distribution(generator);});

	const auto start1 = std::chrono::high_resolution_clock::now();
	float avg1 = average_wasm(numbers.data(), numbers.size());
	const auto end1 = std::chrono::high_resolution_clock::now();
	
    emscripten::val numbers_js = emscripten::val::array(numbers);
    
	const auto start2 = std::chrono::high_resolution_clock::now();
    EM_ASM({
        console.log(typeof $0);
    }, numbers_js);
	float avg2 = average_js(numbers_js);
	const auto end2 = std::chrono::high_resolution_clock::now();
	
	std::chrono::duration<double, std::milli> dt1 = end1 - start1;
	std::chrono::duration<double, std::milli> dt2 = end2 - start2;
	
	
	std::cout << "Avg: "<<avg1<<" dt: "<< dt1.count()
		<< "ms\nAvg: "<<avg2<<" dt: "<< dt2.count()<<"ms\n"<<
		"WASM vs JS: "<<dt2.count()/dt1.count()<<"x faster \n";
	
	return EXIT_SUCCESS;
}
