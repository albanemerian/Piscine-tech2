#include <iostream>
#include <fstream>
#include <string>

void catFile(const std::string &filename)
{
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "MyCat: " << filename << ": No such file or directory" << std::endl;
        exit(84);
    }
    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }
    file.close();
}

void catStdin(void)
{
    std::string line;
    while (std::getline(std::cin, line)) {
        std::cout << line << std::endl;
    }
}

int main(int argc, char *argv[])
{
    if (argc == 1)
        catStdin();
    else {
        for (int i = 1; i < argc; ++i) {
            catFile(argv[i]);
        }
    }
    return 0;
}
