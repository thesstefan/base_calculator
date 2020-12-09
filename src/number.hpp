#pragma once

#include <string>
#include <stdexcept>
#include <iostream>

#include "tools.hpp"

template <unsigned int Base>
class Number {
    private:
        std::string value_string;

        static bool validate_value_string(const std::string& value_string) {
            const std::string base_characters = get_base_characters(Base);

            for (const auto& character : value_string)
               if (base_characters.find(character) == std::string::npos)
                   return false;

            return true;
        }

    public:
        const unsigned int base = Base;

        Number<Base>(const std::string& value_string) {
            static_assert(!(Base < 2 || Base > 16), "Base must be in the range 2-16");

            if (!validate_value_string(value_string))
                throw std::runtime_error("Invalid value in base");

            this->value_string = value_string;
        }

        std::string get_value() const {
            return this->value_string;
        }

        bool operator==(const Number<Base>& other) const {
            return this->value_string == other.get_value();
        }

        Number<Base> operator+(const Number<Base> &other) const {
            const std::string base_characters = get_base_characters(Base);

            std::string value = this->value_string;
            std::string other_value = other.get_value();

            while (value.size() < other_value.size())
                value.insert(value.begin(), '0');

            while (other_value.size() < value.size())
                other_value.insert(other_value.begin(), '0');

            std::string result_value = "";
            unsigned int remainder = 0;
            for (int char_index = value.size() - 1; char_index >= 0; char_index--) {
                unsigned int digit_sum_value = digitToValue(value[char_index]) + 
                                               digitToValue(other_value[char_index]) +
                                               remainder;

                result_value.insert(result_value.begin(), 
                                    valueToDigit(digit_sum_value % Base));

                if (digit_sum_value >= Base)
                    remainder = 1;
                else 
                    remainder = 0;
            }

            if (remainder) 
                result_value.insert(result_value.begin(), '1');

            return Number<Base>(result_value);
        }
};
