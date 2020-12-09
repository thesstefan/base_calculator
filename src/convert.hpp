#pragma once

#include "number.hpp"
#include "misc.hpp"

/*
template <unsigned int SrcBase, unsigned int DstBase>
Number<DstBase> convert_base_substitution(const Number<SrcBase>& number_to_convert) {
    static_assert(!(SrcBase < DstBase), "Use the substitution method only for SrcBase < DstBase");
}

template <unsigned int SrcBase, unsigned int DstBase>
Number<DstBase> convert_base_succesive_division(const Number<SrcBase>& number_to_convert) {
    static_assert(!(SrcBase > DstBase), "Use the succesive division method only \
                                         for SrcBase > DstBase");
}
*/

template <unsigned int SrcBase, unsigned int DstBase>
Number<DstBase> convert_base(const Number<SrcBase>& number_to_convert) {
    if (SrcBase % 2 && DstBase % 2) 
        // Both bases are divisible by 2
        return convert_base_fast<SrcBase, DstBase>(number_to_convert);

    if (SrcBase < DstBase)
        return convert_base_substitution<SrcBase, DstBase>(number_to_convert);

    if (SrcBase > DstBase)
        return convert_base_succesive_division<SrcBase, DstBase>(number_to_convert);

    // Same base (SrcBase == DstBase)
    return number_to_convert;
}
