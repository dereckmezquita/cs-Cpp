#include <iostream>
#include <vector>

std::vector<int> return_int_n_times(int num, int times) { // type and name; arguments
    std::vector<int> vec(times, num); // create vector of n size filled with x element by default
    return vec;
}

int main() {
    std::vector<int> res = return_int_n_times(3, 5); // results from function to res
    
    for(int i = 0; i < res.size(); i++) {
        std::cout << res[i] << std::endl;
    }
    
    return 0;
}
