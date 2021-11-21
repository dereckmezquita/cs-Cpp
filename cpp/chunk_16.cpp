#include <iostream>
#include <vector>

int main() {
	std::vector<int> vec(3);
	
	for(int i = 0; i < 3; i++) {
		vec[i] = i * 3;
	}
	
	std::cout << vec[1] << std::endl;
}
