/**
 * @file tools.hpp
 * @brief Implements various helper functions used in
 *        Number and convert implementations.
 * @author Stefan Stefanache (916/2) 
 * @date 11.12.2020
 */
#pragma once

#include <string>
#include <vector>

/**
 * @brief Returns std::vector of characters used in the given 
 *        base.
 *
 * e.g. get_base_characters(4) returns { '0', '1', '2', '3' }
 *
 * @param base the base to be used.
 */
std::string get_base_characters(const unsigned int base);

/**
 * @brief Checks if the given base is supported.
 *
 * Currently only bases in the interval 2-16 are supported.
 */
bool isBaseSupported(const unsigned int base);

/** @brief Checks if a given number is a power of two. **/
bool is_power_of_two(const unsigned int number);

/** 
 * @brief Returns the decimal value of a digit.
 *
 * e.g. digitToValue('E') = 14
 */
unsigned int digitToValue(const char character);

/**
 * @brief Returns the coresponding digit for a decimal value.
 *
 * e.g. valueToDigit(14) = 'E'
 */
char valueToDigit(const unsigned int value);

/**
 * @brief Returns log_2(n) if the given number is a power of 2.
 *      
 * Otherwise, returns 0
 */
unsigned int get_the_power_of_two(const unsigned int number);

/** @brief The maximum binary digit "pack" size used in fast conversion. */
constexpr unsigned int BINARY_DIGIT_MAX_LENGTH = 4;

/** @brief The characters used in hexadecimal representations. */
extern const std::string HEX_BASE_CHARACTERS;
/** @brief The binary digit packs used in fast conversion. */
extern const std::vector<std::string> RAPID_CONVERSION_STRINGS;
