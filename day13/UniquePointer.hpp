/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD13-albane.merian
** File description:
** UniquePointer
*/

#ifndef UNIQUEPOINTER_HPP_
#define UNIQUEPOINTER_HPP_

template <typename Type>
class UniquePointer {
    public:
        UniquePointer() {
            ptr = nullptr;
        }
        UniquePointer(Type *ptr) {
            this->ptr = ptr;
        }
        ~UniquePointer() {
            if (ptr != nullptr)
                delete ptr;
        }
        void reset() {
            if (ptr != nullptr)
                delete ptr;
            ptr = nullptr;
        }
        Type *get() {
            return ptr;
        }
        Type *operator->() {
            return ptr;
        }

        UniquePointer& operator=(Type* newPtr) {
            if (ptr != newPtr) {
                delete ptr;
                ptr = newPtr;
            }
            return *this;
        }
        UniquePointer(const UniquePointer&) = delete;
        UniquePointer& operator=(const UniquePointer&) = delete;

    protected:
    private:
        Type *ptr;
};

#endif /* !UNIQUEPOINTER_HPP_ */
