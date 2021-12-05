#include <iostream>
#include <vector>

std::vector<int> first_three_multiples(int num) {
  return {(num * 1), (num * 2), (num * 3)};
}

int main() {
	std::vector<int> res = first_three_multiples(3);
	std::cout << res[1] << std::endl;
	return 0;
}
