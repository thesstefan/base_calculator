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
 * The class implements number handling in various bases
 * (currently 2-16 are supported).
 *
 * Basic functionality includes value validation and
 * arithmetic operations:
 *      - addition
 *      - subtraction (with subtrehand > minuend)
 *      - multiplication (by digit)
 *      - division (by digit)
 */
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
        /** The base of the Number. **/
        const unsigned int base;

        /** 
         * Constructor the Number instance.
         *
         * @param value_string the value of the created number 
         * @param base the base of the created number
         *                    
         * @sa validate_value_string() 
         *
         * @exception std::runtime_error on validation vail
         */
        Number(const unsigned int base, const std::string& value_string);

        /** Copy constructor **/
        Number(const Number& other);
        /** Move constructor **/
        Number(Number&& other);

        /** Returns the value string of the Number. **/
        std::string get_value() const;

        /** 
         * Checks if a value string is valid in the given base 
         *
         * A valid value string is defined as one that has each
         * "digit" contained in the set of characters used by the
         * base.
         *
         * @param base the base to be checked in
         * @param value_string the value string to be checked
         *
         * @return true on success, false on fail
         */
        static bool validate_value_string(const unsigned int base,
                                          const std::string& value_string);
        
        /**
         * Equality operator
         *
         * Checks if two Number instances 
         * have the same base and string value.
         *
         * @return true on equality, false otherwise
         */
        bool operator==(const Number& other) const;

        /** 
         * Assignment operator 
         *
         * @exception std::runtime_error on different bases
         **/
        Number& operator=(const Number &other);

        /** Move assignment operator 
         *
         * @exception std::runtime_error on different bases
         **/
        Number& operator=(Number &&other);

        /**
         * Addition operator
         *
         * Implements the addition operation, using the 
         * algorithm studied in class.
         *
         * @param other the Number instance to add with
         *
         * @exception std::runtime_error on subtrahend < minuend 
         *                               and on different bases
         *
         * @return the Number representing the sum of the numbers.
         */
        Number operator+(const Number &other) const;

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
         *                               and on different bases
         *
         * @return the Number representing the sum of the numbers.
         */
        Number operator-(const Number &other) const;

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
         *                               and on different bases
         *
         * @return the Number representing the sum of the numbers.
         */
        Number operator*(const Number &digit) const;

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
         *                               and on different bases
         *
         * @return pair of Number instances, where
         *         first is the quotinent and second the remainder
         */
        std::pair<Number, Number> operator/(const Number &digit) const;
};
