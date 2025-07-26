#include <iostream>
#include "IObject.hpp"
#include "SharedPointer.hpp"

class TestObject : public IObject {
    public:
        TestObject(const std::string& name) : _name(name) {
            std::cout << _name << " is alive" << std::endl;
        }
        
        ~TestObject() {
            std::cout << _name << " is dead" << std::endl;
        }
        
        void touch() override {
            std::cout << _name << " is touched" << std::endl;
        }
        
    private:
        std::string _name;
};

int main()
{
    SharedPointer ptr3;
    std::cout << "use_count (ptr3): " << ptr3.use_count() << std::endl;
    
    SharedPointer ptr1(new TestObject("Pikachu"));
    std::cout << "use_count (ptr3): " << ptr3.use_count() << std::endl;
    ptr1.reset();

    SharedPointer ptr4(new TestObject("Bulbizar"));
    SharedPointer ptr5(new TestObject("Salameche"));
    ptr4.reset();
    ptr5.reset();

    SharedPointer ptr6(new TestObject("Carapuce"));
    SharedPointer ptr7(new TestObject("Carabaffe"));
    ptr6.reset();
    ptr7.reset();

    ptr1.reset(new TestObject("Pikachu"));
    SharedPointer ptr2(ptr1);
    ptr3 = ptr1;
    
    std::cout << "use_count (ptr1): " << ptr1.use_count() << std::endl;
    std::cout << "use_count (ptr2): " << ptr2.use_count() << std::endl;
    std::cout << "use_count (ptr3): " << ptr3.use_count() << std::endl;
    
    ptr2 = ptr1;
    std::cout << "use_count (ptr1): " << ptr1.use_count() << std::endl;
    std::cout << "use_count (ptr2): " << ptr2.use_count() << std::endl;
    ptr3.reset();
    std::cout << "use_count (ptr3): " << ptr3.use_count() << std::endl;
    
    ptr2.reset();
    std::cout << "use_count (ptr1): " << ptr1.use_count() << std::endl;
    std::cout << "use_count (ptr2): " << ptr2.use_count() << std::endl;
    std::cout << "use_count (ptr3): " << ptr3.use_count() << std::endl;
    
    ptr1.reset();
    std::cout << "use_count (ptr1): " << ptr1.use_count() << std::endl;
    std::cout << "use_count (ptr2): " << ptr2.use_count() << std::endl;
    std::cout << "use_count (ptr3): " << ptr3.use_count() << std::endl;

    SharedPointer ptr8(new TestObject("Pikachu"));
    ptr8->touch();
    (*ptr8).touch();
    ptr8.reset();

    ptr1.reset(new TestObject("Pikachu"));
    ptr2.reset(new TestObject("Mew"));
    ptr1.reset();
    ptr2.reset();

    return 0;
}
