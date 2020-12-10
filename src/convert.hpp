/**
 * @file convert.hpp
 * @brief General base conversion dispatcher implementation.
 * @author Stefan Stefanache (916/2) 
 * @date 11.12.2020
 */
#pragma once

#include "number.hpp"

#include "convert_fast.hpp"
#include "convert_substitution.hpp"
#include "convert_succesive.hpp"

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
template <unsigned int SrcBase, unsigned int DstBase>
Number<DstBase> convert_base(const Number<SrcBase>& number_to_convert) {
    if (is_power_of_two(SrcBase) && is_power_of_two(DstBase)) 
        return convert_fast<SrcBase, DstBase>(number_to_convert);

    if (SrcBase < DstBase)
        return convert_substitution<SrcBase, DstBase>(number_to_convert);

    if (SrcBase > DstBase)
        return convert_succesive<SrcBase, DstBase>(number_to_convert);

    return number_to_convert;
}
