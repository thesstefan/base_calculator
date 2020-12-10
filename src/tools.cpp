/**
 * @file tools.hpp
 * @author Stefan Stefanache (916/2) 
 * @date 11.12.2020
 */
#include "tools.hpp"

const std::string HEX_BASE_CHARACTERS("0123456789ABCDEF");

const std::vector<std::string> RAPID_CONVERSION_STRINGS {
    "0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111",
    "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"
};

std::string get_base_characters(const unsigned int base) {
    return HEX_BASE_CHARACTERS.substr(0, base);
}

bool is_power_of_two(const unsigned int number) {
    return number && !(number & (number - 1));
}

unsigned int get_the_power_of_two(const unsigned int number) {
    static constexpr int twos[] = {
        1<<0,  1<<1,  1<<2,  1<<3,  1<<4,  1<<5,  1<<6,  1<<7,
        1<<8,  1<<9,  1<<10, 1<<11, 1<<12, 1<<13, 1<<14, 1<<15,
        1<<16, 1<<17, 1<<18, 1<<19, 1<<20, 1<<21, 1<<22, 1<<23,
        1<<24, 1<<25, 1<<26, 1<<27, 1<<28, 1<<29, 1<<30, 1<<31
    };

    return std::lower_bound(std::begin(twos), std::end(twos), number) - std::begin(twos);
}

unsigned int digitToValue(const char character) {
    return HEX_BASE_CHARACTERS.find(character);
}

char valueToDigit(const unsigned int value) {
    return HEX_BASE_CHARACTERS[value];
}
