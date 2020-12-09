#include <catch2/catch.hpp>

#include "../src/convert.hpp"

TEST_CASE("Conversion using the substitution method", "[convert_substitution]") {
    SECTION( "Conversion from base 2" ) {
        Number<2> binary_number = Number<2>("1110101010111110101111101000010101");

        REQUIRE( convert_substitution<2, 16>(binary_number).get_value() == "3AAFAFA15" );
        REQUIRE( convert_substitution<2, 8>(binary_number).get_value() == "165276575025" );
        REQUIRE( convert_substitution<2, 4>(binary_number).get_value() == "32222332233220111" );
    }

    SECTION( "Conversion from base 4" ) {
        Number<4> base4_number = Number<4>("312032132131");

        REQUIRE( convert_substitution<4, 16>(base4_number).get_value() == "D8E79D" );
        REQUIRE( convert_substitution<4, 9>(base4_number).get_value() == "28665361" );
        REQUIRE( convert_substitution<4, 8>(base4_number).get_value() == "66163635" );
    }

    SECTION( "Conversion from base 11" ) {
        Number<11> base11_number = Number<11>("A1293892AA");

        REQUIRE( convert_substitution<11, 16>(base11_number).get_value() == "58D887514" );
        REQUIRE( convert_substitution<11, 13>(base11_number).get_value() == "2331038183" );
        REQUIRE( convert_substitution<11, 12>(base11_number).get_value() == "4757130A98" );
    }
}
