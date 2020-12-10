/**
 * @file number.hpp
 * @brief Implements generic base number interface.
 * @author Stefan Stefanache (916/2) 
 * @date 11.12.2020
 */
#pragma once

#include <string>
#include <stdexcept>

#include "tools.hpp"

/**
 * @brief Class implementing the Number data-type interface.
 *
 * @tparam Base the base to be used.
 *
 * The class implements value handling in various bases
 * (currently 2-16 are supported).
 *
 * Basic functionality includes value validation and
 * arithmetic operations:
 *      - addition
 *      - subtraction (with subtrehand > minuend)
 *      - multiplication (by digit)
 *      - division (by digit)
 */
template <unsigned int Base>
class Number {
    private:
        /** The value of the Number. **/
        std::string value_string;

        /** Returns string without excess '0's on the left **/
        static std::string get_removed_zero_padding(const std::string& value_string);
        /** 
         * Returns string with added '0's on the left. 
         * (so that it has the target specified length)
         */
        static std::string get_zero_padded(const std::string& value_string, 
                                           size_t target_length);
    public:
        /** Member containing the Number Base. **/
        const unsigned int base = Base;

        /** 
         * Constructor the Number instance.
         *
         * @param value_string the value of the created number 
         *                    
         * @sa validate_value_string() 
         *
         * @exception std::runtime_error on validation vail
         */
        Number<Base>(const std::string& value_string);

        /** Copy constructor **/
        Number<Base>(const Number<Base>& other);
        /** Move constructor **/
        Number<Base>(Number<Base>&& other);

        /** Returns the value string of the Number. **/
        std::string get_value() const;

        /** 
         * Validates a value string in the given template Base
         *
         * A valid value string is defined as one that has each
         * "digit" contained in the set of characters used by the
         * base.
         *
         * @return true on success, false on fail
         */
        static bool validate_value_string(const std::string& value_string);

        /**
         * Equality operator
         *
         * Checks if two Number instances (same base)
         * have the same string value.
         *
         * @return true on equality, false otherwise
         */
        bool operator==(const Number<Base>& other) const;

        /** Assignment operator **/
        Number<Base>& operator=(const Number<Base> &other);
        /** Move assignment operator **/
        Number<Base>& operator=(Number<Base> &&other);

        /**
         * Addition operator
         *
         * Implements the addition operation, using the 
         * algorithm studied in class.
         *
         * @param other the Number instance to add with
         *
         * @return the Number representing the sum of the numbers.
         */
        Number<Base> operator+(const Number<Base> &other) const;


        /**
         * Subtraction operator
         *
         * Implements the subtraction operation, using the 
         * algorithm studied in class.
         *
         * The subtrahend (this) must be equal or bigger than the 
         * minuend (other). 
         *
         * @param other the Number instance to be subtracted
         *
         * @exception std::runtime_error on subtrahend < minuend.
         *
         * @return the Number representing the sum of the numbers.
         */
        Number<Base> operator-(const Number<Base> &other) const;

        /**
         * Multiplication operator
         *
         * Implements the multiplication operation, using the 
         * algorithm studied in class.
         *
         * The multiplication can be done only by a digit 
         * (other)
         *
         * @param other the digit Number instance to multiply by 
         *
         * @exception std::runtime_error on other not being a digit
         *
         * @return the Number representing the sum of the numbers.
         */
        Number<Base> operator*(const Number<Base> &digit) const;

        /**
         * Division operator
         *
         * Implements the division operation, using the 
         * algorithm studied in class.
         *
         * The division can be done only by a digit 
         * (other)
         *
         * @param other the digit Number instance to multiply by 
         *
         * @exception std::runtime_error on other not being a digit
         *
         * @return pair of Number instances, where
         *         first is the quotinent and second the remainder
         */
        std::pair<Number<Base>, Number<Base>> operator/(const Number<Base> &digit) const;
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
std::string Number<Base>::get_removed_zero_padding(const std::string& value_string) {
    std::string result = value_string;

    while (result[0] == '0' && result.size() > 1)
        result.erase(result.begin());

    return result;
}

template <unsigned int Base>
std::string Number<Base>::get_zero_padded(const std::string& value_string,
                                          size_t target_length) {
    std::string padded_string = value_string;

    while (padded_string.size() < target_length)
        padded_string.insert(padded_string.begin(), '0');

    return padded_string;
}

template <unsigned int Base>
Number<Base>::Number(const std::string& value_string) : 
    value_string(get_removed_zero_padding(value_string)) {
    static_assert(!(Base < 2 || Base > 16), "Base must be in the range 2-16");

    if (!validate_value_string(value_string))
        throw std::runtime_error("Invalid value in base");
}

template <unsigned int Base>
Number<Base>::Number(const Number<Base>& other) : 
    value_string(other.value_string) {}

template <unsigned int Base>
Number<Base>::Number(Number<Base>&& other) : 
    value_string(std::move(other.value_string)) {}

template <unsigned int Base>
std::string Number<Base>::get_value() const {
    return this->value_string;
}

template <unsigned int Base>
Number<Base>& Number<Base>::operator=(const Number<Base> &other) {
    this->value_string = other.value_string;

    return *this;
}

template <unsigned int Base>
Number<Base>& Number<Base>::operator=(Number<Base> &&other) {
    this->value_string = std::move(other.value_string);

    return *this;
}

template <unsigned int Base>
bool Number<Base>::operator==(const Number<Base>& other) const {
    return this->value_string == other.get_value();
}

template <unsigned int Base>
Number<Base> Number<Base>::operator+(const Number<Base>& other) const {
    const std::string base_characters = get_base_characters(Base);

    const std::string value = 
        get_zero_padded(this->value_string, other.get_value().size());
    const std::string other_value = 
        get_zero_padded(other.get_value(), this->value_string.size());

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
        get_zero_padded(this->value_string, other.get_value().size());
    const std::string other_value = 
        get_zero_padded(other.get_value(), this->value_string.size());

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

template <unsigned int Base>
Number<Base> Number<Base>::operator*(const Number<Base>& digit) const {
    if (digit.get_value().size() != 1) 
        throw std::runtime_error("Multiplication can only be done by DIGIT");

    std::string result_value = "";
    unsigned int remainder = 0;
    unsigned int multiplication_digit = digitToValue(digit.get_value()[0]);

    for (int char_index = this->value_string.size() - 1; char_index >= 0; char_index--) {
        unsigned int product = digitToValue(this->value_string[char_index]) * multiplication_digit
                               + remainder;

        remainder = product / Base;

        result_value.insert(result_value.begin(), valueToDigit(product % Base));
    }

    if (remainder)
        result_value.insert(result_value.begin(), valueToDigit(remainder));

    return Number<Base>(result_value);
}

template <unsigned int Base>
std::pair<Number<Base>, Number<Base>> Number<Base>::operator/(const Number<Base>& digit) const {
    if (digit.get_value().size() != 1) 
        throw std::runtime_error("Division can only be done by DIGIT");

    std::string result_value = "";
    unsigned int division_digit = digitToValue(digit.get_value()[0]);
    unsigned int transport_digit = 0;

    for (int char_index = 0; char_index < this->value_string.size(); char_index++) {
        unsigned int special_value = digitToValue(this->value_string[char_index]) +
                                     transport_digit * Base;

        transport_digit = special_value % division_digit;
        result_value += valueToDigit(special_value / division_digit);
    }

    return std::make_pair<Number<Base>, Number<Base>>
        (Number<Base>(result_value), Number<Base>(std::string{valueToDigit(transport_digit)}));
}
