/**
 * @file convert.hpp
 * @brief General base conversion dispatcher implementation.
 * @author Stefan Stefanache (916/2) 
 * @date 11.12.2020
 */
#pragma once

#include "number.hpp"

Number convert_fast(unsigned int dstBase, const Number& number);
Number convert_substitution(unsigned int dstBase, const Number& number);
Number convert_successive_division(unsigned int dstBase, const Number& number);

/**
 * @brief General base conversion dispatcher.
 *
 * Under the hood, the following conversion implementations are used:
 *      - convert_fast if SrcBase and DstBase are powers of two
 *      - convert_substitution if SrcBase < DstBase
 *      - convert_successive if SrcBase > DstBase
 *
 * @tparam SrcBase the source base
 * @tparam DstBase the destination base
 *
 * @param number_to_convert the Number to be converted
 * @return converted Number instance
 */
Number convert_base(unsigned int dstBase, const Number& number);
