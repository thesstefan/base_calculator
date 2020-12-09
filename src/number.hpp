#pragma once

#include <string>
#include <stdexcept>
#include <iostream>

#include "tools.hpp"

template <unsigned int Base>
class Number {
    private:
        const std::string value_string;

    public:
        const unsigned int base = Base;

        Number<Base>(const std::string& value_string);

        std::string get_value() const;

        static bool validate_value_string(const std::string& value_string);
        static std::string zero_padded_string(const std::string& value_string, 
                                              size_t target_length);

        bool operator==(const Number<Base>& other) const;

        Number<Base> operator+(const Number<Base> &other) const;
        Number<Base> operator-(const Number<Base> &other) const;
};

template <unsigned int Base>
bool Number<Base>::validate_value_string(const std::string& value_string) { 
    const std::string base_characters = get_base_characters(Base);

    for (const auto& character : value_string)
       if (base_characters.find(character) == std::string::npos)
           return false;

    return true;
}

template <unsigned int Base>
Number<Base>::Number(const std::string& value_string) : value_string(value_string) {
    static_assert(!(Base < 2 || Base > 16), "Base must be in the range 2-16");

    if (!validate_value_string(value_string))
        throw std::runtime_error("Invalid value in base");
}

template <unsigned int Base>
std::string Number<Base>::get_value() const {
    return this->value_string;
}

template <unsigned int Base>
bool Number<Base>::operator==(const Number<Base>& other) const {
    return this->value_string == other.get_value();
}

template <unsigned int Base>
std::string Number<Base>::zero_padded_string(const std::string& value_string,
                                                 size_t target_length) {
    std::string padded_string = value_string;

    while (padded_string.size() < target_length)
        padded_string.insert(padded_string.begin(), '0');

    return padded_string;
}

template <unsigned int Base>
Number<Base> Number<Base>::operator+(const Number<Base>& other) const {
    const std::string base_characters = get_base_characters(Base);

    const std::string value = 
        zero_padded_string(this->value_string, other.get_value().size());
    const std::string other_value = 
        zero_padded_string(other.get_value(), this->value_string.size());

    std::string result_value = "";
    unsigned int remainder = 0;
    for (int char_index = value.size() - 1; char_index >= 0; char_index--) {
        unsigned int digit_sum_value = digitToValue(value[char_index]) + 
                                       digitToValue(other_value[char_index]) +
                                       remainder;

        result_value.insert(result_value.begin(), 
                            valueToDigit(digit_sum_value % Base));

        remainder = digit_sum_value >= Base ? 1 : 0;
    }

    if (remainder) 
        result_value.insert(result_value.begin(), '1');

    return Number<Base>(result_value);
}

template <unsigned int Base>
Number<Base> Number<Base>::operator-(const Number<Base>& other) const {
    if (other.get_value().size() > this->value_string.size()) 
        throw std::runtime_error("Difference can't be negative");

    const std::string base_characters = get_base_characters(Base);

    const std::string value = 
        zero_padded_string(this->value_string, other.get_value().size());
    const std::string other_value = 
        zero_padded_string(other.get_value(), this->value_string.size());

    std::string result_value = "";
    unsigned int remainder = 0;
    for (int char_index = value.size() - 1; char_index >= 0; char_index--) {
        int digit_sum_value = digitToValue(value[char_index]) -
                              digitToValue(other_value[char_index]) -
                              remainder;

        if (digit_sum_value >= 0)
            result_value.insert(result_value.begin(), valueToDigit(digit_sum_value));
        else
            result_value.insert(result_value.begin(),
                                valueToDigit((base_characters.size() + digit_sum_value)));

        remainder = digit_sum_value < 0 ? 1 : 0;
    }

    if (remainder) 
        throw std::runtime_error("Difference can't be negative");

    return Number<Base>(result_value);
}
