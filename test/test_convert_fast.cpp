#include <catch2/catch.hpp>

#include "../src/convert_fast.hpp"

TEST_CASE("Fast conversion using the powers of two", "[convert_fast]") {
    SECTION( "Conversion from base 2" ) {
        Number<2> binary_number = Number<2>("1110101010111110101111101000010101");

        REQUIRE( convert_fast<2, 16>(binary_number).get_value() == "3AAFAFA15" );
        REQUIRE( convert_fast<2, 8>(binary_number).get_value() == "165276575025" );
        REQUIRE( convert_fast<2, 4>(binary_number).get_value() == "32222332233220111" );
        REQUIRE( convert_fast<2, 2>(binary_number).get_value() == 
                "1110101010111110101111101000010101" );
    }

    SECTION( "Conversion from base 4" ) {
        Number<4> base4_number = Number<4>("312032132131");

        REQUIRE( convert_fast<4, 16>(base4_number).get_value() == "D8E79D" );
        REQUIRE( convert_fast<4, 8>(base4_number).get_value() == "66163635" );
        REQUIRE( convert_fast<4, 4>(base4_number).get_value() == "312032132131" );
        REQUIRE( convert_fast<4, 2>(base4_number).get_value() == 
                "110110001110011110011101" );
    }

    SECTION( "Conversion from base 8" ) {
        Number<8> octal_number = Number<8>("71236230");

        REQUIRE( convert_fast<8, 16>(octal_number).get_value() == "E53C98" );
        REQUIRE( convert_fast<8, 8>(octal_number).get_value() == "71236230" );
        REQUIRE( convert_fast<8, 4>(octal_number).get_value() == "321103302120" );
        REQUIRE( convert_fast<8, 2>(octal_number).get_value() == 
                "111001010011110010011000" );
    }

    SECTION( "Conversion from base 16" ) {
        Number<16> hexa_number= Number<16>("BA0FCE");

        REQUIRE( convert_fast<16, 16>(hexa_number).get_value() == "BA0FCE" );
        REQUIRE( convert_fast<16, 8>(hexa_number).get_value() == "56407716" );
        REQUIRE( convert_fast<16, 4>(hexa_number).get_value() == "232200333032" );
        REQUIRE( convert_fast<16, 2>(hexa_number).get_value() == 
                "101110100000111111001110" );
    }
}
