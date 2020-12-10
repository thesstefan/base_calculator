#include <catch2/catch.hpp>

#include "../src/convert.hpp"

TEST_CASE("Conversion using successive division", "[convert_successive_division]") {
    SECTION( "Conversion from base 8" ) {
        Number octal_number = Number(8, "71236230");

        REQUIRE( convert_successive_division(5, octal_number).get_value() == "12321221011" );
        REQUIRE( convert_successive_division(4, octal_number).get_value() == "321103302120" );
        REQUIRE( convert_successive_division(2, octal_number).get_value() == 
                "111001010011110010011000" );
    }

    SECTION( "Conversion from base 10" ) {
        Number decimal_number = Number(10, "21837291");

        REQUIRE( convert_successive_division(9, decimal_number).get_value() == "45073116" );
        REQUIRE( convert_successive_division(3, decimal_number).get_value() == "1112002110010120" );
        REQUIRE( convert_successive_division(2, decimal_number).get_value() ==
                "1010011010011010111101011" );
    }

    SECTION( "Conversion from base 16" ) {
        Number hexa_number= Number(16, "BA0FCE");

        REQUIRE( convert_successive_division(13, hexa_number).get_value() == "26AC242" );
        REQUIRE( convert_successive_division(8, hexa_number).get_value() == "56407716" );
        REQUIRE( convert_successive_division(4, hexa_number).get_value() == "232200333032" );
        REQUIRE( convert_successive_division(2, hexa_number).get_value() == 
                "101110100000111111001110" );
    }
}
