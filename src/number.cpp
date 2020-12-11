#include "number.hpp"

bool Number::validate_value_string(const unsigned int base, 
                                   const std::string& value_string) { 
    const std::string base_characters = get_base_characters(base);

    for (const auto& character : value_string)
       if (base_characters.find(character) == std::string::npos)
           return false;

    return true;
}

std::string Number::get_removed_zero_padding(const std::string& value_string) {
    std::string result = value_string;

    while (result[0] == '0' && result.size() > 1)
        result.erase(result.begin());

    return result;
}

std::string Number::get_zero_padded(const std::string& value_string,
                                          size_t target_length) {
    std::string padded_string = value_string;

    while (padded_string.size() < target_length)
        padded_string.insert(padded_string.begin(), '0');

    return padded_string;
}

Number::Number(const unsigned int base,
               const std::string& value_string) : 
    value_string(get_removed_zero_padding(value_string)), base(base) {

    if (base < 2 || base > 16)
        throw std::runtime_error("Base must be in the range 2-16");

    if (!validate_value_string(base, value_string))
        throw std::runtime_error("Invalid value in base");
}

Number::Number(const Number& other) : 
    value_string(other.value_string), base(other.base) {}

Number::Number(Number&& other) : 
    value_string(std::move(other.value_string)), base(std::move(other.base)) {}

std::string Number::get_value() const {
    return this->value_string;
}

Number& Number::operator=(const Number &other) {
    if (this->base != other.base)
        throw std::runtime_error("Operands must be of the same size");

    this->value_string = other.value_string;

    return *this;
}

Number& Number::operator=(Number &&other) {
    if (this->base != other.base)
        throw std::runtime_error("Operands must be of the same size");

    this->value_string = std::move(other.value_string);

    return *this;
}

bool Number::operator==(const Number& other) const {
    return this->base == other.base &&
           this->value_string == other.get_value();
}

Number Number::operator+(const Number& other) const {
    if (this->base != other.base)
        throw std::runtime_error("Operands must be of the same size");

    const std::string base_characters = get_base_characters(this->base);

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
                            valueToDigit(digit_sum_value % this->base));

        remainder = digit_sum_value >= this->base ? 1 : 0;
    }

    if (remainder) 
        result_value.insert(result_value.begin(), '1');

    return Number(this->base, result_value);
}

Number Number::operator-(const Number& other) const {
    if (this->base != other.base)
        throw std::runtime_error("Operands must be of the same size");

    if (other.get_value().size() > this->value_string.size()) 
        throw std::runtime_error("Difference can't be negative");

    const std::string base_characters = get_base_characters(this->base);

    const std::string value = 
        get_zero_padded(this->value_string, other.get_value().size());
    const std::string other_value = 
        get_zero_padded(other.get_value(), this->value_string.size());

    std::string result_value = "";
    unsigned int remainder = 0;
    for (int char_index = value.size() - 1; char_index >= 0; char_index--) {
        int digit_diff_value = digitToValue(value[char_index]) -
                              digitToValue(other_value[char_index]) -
                              remainder;

        if (digit_diff_value >= 0)
            result_value.insert(result_value.begin(), valueToDigit(digit_diff_value));
        else
            result_value.insert(result_value.begin(),
                                valueToDigit((base_characters.size() + digit_diff_value)));

        remainder = digit_diff_value < 0 ? 1 : 0;
    }

    if (remainder) 
        throw std::runtime_error("Difference can't be negative");

    return Number(this->base, result_value);
}

Number Number::operator*(const Number& digit) const {
    if (this->base != digit.base)
        throw std::runtime_error("Operands must be of the same size");

    if (digit.get_value().size() != 1) 
        throw std::runtime_error("Multiplication can only be done by DIGIT");

    std::string result_value = "";
    unsigned int remainder = 0;
    unsigned int multiplication_digit = digitToValue(digit.get_value()[0]);

    for (int char_index = this->value_string.size() - 1; char_index >= 0; char_index--) {
        unsigned int product = digitToValue(this->value_string[char_index]) * multiplication_digit
                               + remainder;

        remainder = product / this->base;

        result_value.insert(result_value.begin(), valueToDigit(product % this->base));
    }

    if (remainder)
        result_value.insert(result_value.begin(), valueToDigit(remainder));

    return Number(this->base, result_value);
}

std::pair<Number, Number> Number::operator/(const Number& digit) const {
    if (this->base != digit.base)
        throw std::runtime_error("Operands must be of the same size");

    if (digit.get_value().size() != 1) 
        throw std::runtime_error("Division can only be done by DIGIT");

    std::string result_value = "";
    unsigned int division_digit = digitToValue(digit.get_value()[0]);
    unsigned int transport_digit = 0;

    for (int char_index = 0; char_index < this->value_string.size(); char_index++) {
        unsigned int special_value = digitToValue(this->value_string[char_index]) +
                                     transport_digit * this->base;

        transport_digit = special_value % division_digit;
        result_value += valueToDigit(special_value / division_digit);
    }

    return std::make_pair<Number, Number>
        (Number(this->base, result_value), 
         Number(this->base, std::string{valueToDigit(transport_digit)}));
}
