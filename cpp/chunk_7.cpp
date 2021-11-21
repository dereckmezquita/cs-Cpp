#include <iostream>

int main() {
	double score = 0;
	
	score = score + 20;
	std::cout << score << std::endl;
	
	score = score - 2;
	std::cout << score << std::endl;
	
	score = score * 3;
	std::cout << score << std::endl;
	
	score = score / 2;
	std::cout << score << std::endl;
	
	score = (int) score % 3;
	std::cout << score << std::endl;
	
	return 0;
}
