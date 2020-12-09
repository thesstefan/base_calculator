#pragma once

#include <string>
#include <stdexcept>

#include "misc.hpp"

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
};
