#include <catch2/catch.hpp>

#include "../src/convert_succesive.hpp"

TEST_CASE("Conversion using succesive division", "[convert_succesive]") {
    SECTION( "Conversion from base 8" ) {
        Number<8> octal_number = Number<8>("71236230");

        REQUIRE( convert_succesive<8, 5>(octal_number).get_value() == "12321221011" );
        REQUIRE( convert_succesive<8, 4>(octal_number).get_value() == "321103302120" );
        REQUIRE( convert_succesive<8, 2>(octal_number).get_value() == 
                "111001010011110010011000" );
    }

    SECTION( "Conversion from base 10" ) {
        Number<10> decimal_number = Number<10>("21837291");

        REQUIRE( convert_succesive<10, 9>(decimal_number).get_value() == "45073116" );
        REQUIRE( convert_succesive<10, 3>(decimal_number).get_value() == "1112002110010120" );
        REQUIRE( convert_succesive<10, 2>(decimal_number).get_value() ==
                "1010011010011010111101011" );
    }

    SECTION( "Conversion from base 16" ) {
        Number<16> hexa_number= Number<16>("BA0FCE");

        REQUIRE( convert_succesive<16, 13>(hexa_number).get_value() == "26AC242" );
        REQUIRE( convert_succesive<16, 8>(hexa_number).get_value() == "56407716" );
        REQUIRE( convert_succesive<16, 4>(hexa_number).get_value() == "232200333032" );
        REQUIRE( convert_succesive<16, 2>(hexa_number).get_value() == 
                "101110100000111111001110" );
    }
}
