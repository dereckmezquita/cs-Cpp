#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {2, 4, 3, 6, 1, 9};
    
    int even_sum = 0;
    int odd_prod = 1;
    
    for(int i = 0; i < vec.size(); i++) {
        if(vec[i] % 2 == 0) {
            even_sum += vec[i];
        } else {
            odd_prod *= vec[i];
        }
    }
    
    std::cout << even_sum << std::endl;
    std::cout << odd_prod << std::endl;
    
    return 0;
}
