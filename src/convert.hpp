#pragma once

#include "number.hpp"

#include "convert_fast.hpp"
#include "convert_substitution.hpp"
#include "convert_succesive.hpp"

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
