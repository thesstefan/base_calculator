/**
 * @file convert.hpp
 * @brief Base conversion algorithms.
 * @author Stefan Stefanache (916/2) 
 * @date 11.12.2020
 */
#pragma once

#include "number.hpp"

/**
 * @brief Converts number in another base using rapid conversion 
 *
 * @warning This should be used only if both the source base
 *          and the destination base are powers of 2.
 *
 * @param dstBase the destination base
 * @param number the Number to be converted
 *
 * @exception std::runtime_error if dstBase is not supported 
 *                               or the bases are not powers of two
 *
 * @return converted Number in dstBase
 */
Number convert_fast(unsigned int dstBase, const Number& number);

/**
 * @brief Converts number in another base using the substitution method
 *
 * @warning This should be used only if dstBase > srcBase
 *
 * @param dstBase the destination base
 * @param number the Number to be converted
 *
 * @exception std::runtime_error if dstBase is not supported 
 *                                  or dstBase <= srcBase
 *
 * @return converted Number in dstBase
 */
Number convert_substitution(unsigned int dstBase, const Number& number);

/**
 * @brief Converts number in another base using the successive division method
 *
 * @warning This should be used only if dstBase < srcBase
 *
 * @param dstBase the destination base
 * @param number the Number to be converted
 *
 * @exception std::runtime_error if dstBase is not supported 
 *                                  or dstBase >= srcBase
 *
 * @return converted Number in dstBase
 */
Number convert_successive_division(unsigned int dstBase, const Number& number);

/**
 * @brief General base conversion dispatcher.
 *
 * Under the hood, the following conversion implementations are used:
 *      - convert_fast if the source and destination bases are powers of two
 *      - convert_substitution if srcBase < dstBase
 *      - convert_successive if srcBase > dstBase
 *
 * @param dstBase the destination base
 * @param number the Number to be converted
 *
 * @exception std::runtime_error if dstBase is not supported 
 * @sa isBaseSupported()
 *
 * @return converted Number instance
 */
Number convert_base(unsigned int dstBase, const Number& number);
