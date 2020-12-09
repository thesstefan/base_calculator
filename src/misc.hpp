#pragma once

#include <string>
#include <vector>

std::string get_base_characters(const unsigned int base);

bool is_power_of_two(const unsigned int number);

unsigned int digitToValue(const char character);
char valueToDigit(const unsigned int value);

unsigned int get_the_power_of_two(const unsigned int number);

constexpr unsigned int BINARY_DIGIT_MAX_LENGTH = 4;

extern const std::string HEX_BASE_CHARACTERS;
extern const std::vector<std::string> RAPID_CONVERSION_STRINGS;
