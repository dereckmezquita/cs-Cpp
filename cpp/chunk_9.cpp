#include <iostream>
#include <random>

int main() {
	int bedrooms = 9;
	
	switch(bedrooms) {
		case 1 :
			std::cout << "The house is cheap" << std::endl;
			break;
		case 2 :
			std::cout << "Starter home" << std::endl;
			break;
		case 3 :
			std::cout << "Mid sized house for a family." << std::endl;
			break;
		case 4 :
			std::cout << "Okay big house!" << std::endl;
			break;
		default :
			std::cout << "Why do you need so many rooms!?" << std::endl;
			break;
	}
}
