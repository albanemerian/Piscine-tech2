#include <iostream>
#include "Algorithm.hpp"

class MyInt {
    private:
        int value;
    
    public:
        MyInt(int v) : value(v) {}
        
        bool operator<(const MyInt& r) const {
            return value < r.value;
        }
        
        // This operator is deliberately deleted to match the error
        bool operator>(const MyInt& r) const = delete;
        
        friend std::ostream& operator<<(std::ostream& os, const MyInt& mi) {
            return os << mi.value;
        }
};

// int main()
// {
//     // Test with basic types
//     int a = 42;
//     int b = 24;
    
//     std::cout << "Before swap: a = " << a << ", b = " << b << std::endl;
//     swap(a, b);
//     std::cout << "After swap: a = " << a << ", b = " << b << std::endl;
    
//     std::cout << "Min of " << a << " and " << b << " is: " << min(a, b) << std::endl;
//     std::cout << "Max of " << a << " and " << b << " is: " << max(a, b) << std::endl;
//     std::cout << "Clamp 15 between 10 and 20: " << clamp(15, 10, 20) << std::endl;
    
//     // Test with MyInt - this will trigger the compilation errors
//     MyInt mi1(5);
//     MyInt mi2(10);
    
//     // These lines will cause compilation errors due to deleted operator>
//     std::cout << "Max of MyInt: " << max(mi1, mi2) << std::endl;
//     std::cout << "Clamp MyInt: " << clamp(mi1, mi1, mi2) << std::endl;
    
//     return 0;
// }
