#include <iostream>
#include <cstdlib>
#include <chrono>
#include "prime_number.h"

int main(int argc, char** argv)
{
	const auto start1 = std::chrono::high_resolution_clock::now();
	bool is_prime1 = is_prime_wasm(7919);
	const auto end1 = std::chrono::high_resolution_clock::now();
	
	const auto start2 = std::chrono::high_resolution_clock::now();
	bool is_prime2 = is_prime_js(7919);
	const auto end2 = std::chrono::high_resolution_clock::now();
	
	std::chrono::duration<double, std::milli> dt1 = end1 - start1;
	std::chrono::duration<double, std::milli> dt2 = end2 - start2;
	
	
	std::cout << "Is prime1: "<<is_prime1<<" dt: "<< dt1.count()
		<< "\nIs prime2: "<<is_prime2<<" dt: "<< dt2.count()<<'\n'<<
		"WASM vs JS: "<<dt2.count()/dt1.count()<<"x faster \n";
	
	return EXIT_SUCCESS;
}
