#include <iostream>

int main() {
    bool yeet = true;
    std::string mom_location = "home";
    int people = 9;
    
    if(yeet & (mom_location != "home")) {
        std::cout << "Mother's home no yeeting!" << std::endl;
    } else if(((bool) people % 3) & yeet) {
        std::cout << "We have enough yeets for all and mother is not home! YEET!" << std::endl;
    } else {
        std::cout << "We don't have enough yeets, but we have some!" << std::endl;
    }
    return 0;
}
