/*
** EPITECH PROJECT, 2025
** B-PDG-300-NAN-3-1-PDGD06-albane.merian
** File description:
** StupidUnitConverter
*/

#include <iostream>
#include <cstring>
#include <vector>
#include <iomanip>


char** split_by_spaces(char *line) {

    std::vector<char*> tokens;
    char *token = std::strtok(line, " ");

    while (token != nullptr) {
        tokens.push_back(token);
        token = std::strtok(nullptr, " ");
    }

    char **result = new char*[tokens.size() + 1];
    for (size_t i = 0; i < tokens.size(); ++i) {
        result[i] = tokens[i];
    }
    result[tokens.size()] = nullptr;
    return result;
}

int miaou_miaou(char *temperature, char *scale)
{
    float value = 0;
    float temp = atof(temperature);

    if (strcmp(scale, "Celsius") == 0) {
        value = (9.0 / 5.0) * temp + 32;
        std::cout << std::setw(16) << std::right << std::fixed << std::setprecision(3) << value << std::setw(16) << "Fahrenheit" << std::endl;
    } else if (strcmp(scale, "Fahrenheit") == 0) {
        value = (5.0 / 9.0) * (temp - 32);
        std::cout << std::setw(16) << std::right << std::fixed << std::setprecision(3) << value << std::setw(16) << "Celsius" << std::endl;
    }
    return 0;   
}

int miaou(void)
{
    char **table = NULL;

    std::string line;
    while (std::getline(std::cin, line)) {
        table = split_by_spaces(const_cast<char*>(line.c_str()));
        if (table[0] != NULL || table[1] != NULL)
            miaou_miaou(table[0], table[1]);
    }
    return 0;
}

int main(int argc, char **argv)
{
    if (argc == 1 || argv[1] == NULL) {
        miaou();
        return 0;
    }
    return 84;
}
