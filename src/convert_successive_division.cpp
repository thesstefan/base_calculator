#include <stdexcept>

#include "convert.hpp"
#include "tools.hpp"

Number convert_successive_division(unsigned int dstBase, const Number& number) {
    if (!(number.base > dstBase))
        throw std::runtime_error(
            "Use the succesive division method only for SrcBase > DstBase");

    const Number base(number.base, std::string{valueToDigit(dstBase)});
    Number quotinent(number.base, number.get_value());

    std::string result_string = "";
    while (quotinent.get_value() != "0") {
        auto division_pair = quotinent / base;

        quotinent = division_pair.first;
        result_string.insert(result_string.begin(), 
                             division_pair.second.get_value()[0]);
    }

    return Number(dstBase, result_string);
}
