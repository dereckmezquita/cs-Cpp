#include <iostream>
#include <vector>

std::vector<int> return_int_n_times(int num, int times) { // type and name; arguments
    std::vector<int> vec(times, num); // create vector of n size filled with x element by default
    return vec;
}

void print_vec(std::vector<int> vec) { // void because nothing is returned it simple prints
    int i = 0;
    
    while(i < vec.size()) {
        std::cout << vec[i]; // print i element
        
        if(i != (vec.size() - 1)) { // check we are not at end
            std::cout << ", "; // if not at end print ", "
        }
        
        i++; // increase i
    }
    
    std::cout << std::endl;
}

int main() {
    std::vector<int> res = return_int_n_times(3, 5); // results from function to res
    
    // replace with print function
    // for(int i = 0; i < res.size(); i++) {
    //    std::cout << res[i] << std::endl;
    // }
    
    print_vec(res);
    
    return 0;
}
