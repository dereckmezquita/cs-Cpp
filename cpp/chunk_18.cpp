#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <chrono>

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::vector<std::string> dna = {"ATG", "CAA"};
	
	std::cout << dna[dna.size() - 1] << std::endl;
	
	dna.push_back("HIYA");
	
	std::cout << dna[dna.size() - 1] << std::endl;
	
	dna.pop_back();
	
	std::cout << dna[dna.size() - 1] << std::endl;
	
	return 0;
}
