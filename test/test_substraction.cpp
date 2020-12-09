#include <catch2/catch.hpp>

#include "../src/number.hpp"

TEST_CASE("Addition between two numbers", "[Number::operator+]") {
    SECTION( "Base 2" ) {
        Number<2> first = Number<2>("1010101010010100101");
        Number<2> second = Number<2>("101111111111111");

        Number<2> expected_result = Number<2>("1001111010010100110");

        REQUIRE( first - second == expected_result );
    }

    SECTION( "Base 7" ) {
        Number<7> first = Number<7>("612631610");
        Number<7> second = Number<7>("66316");

        Number<7> expected_result = Number<7>("612532261");

        REQUIRE( first - second == expected_result );
    }

    SECTION( "Base 16" ) {
        Number<16> first = Number<16>("EFA01AAF011");
        Number<16> second = Number<16>("ABC01ED");

        Number<16> expected_result = Number<16>("EF9F6EEEE24");

        REQUIRE( first - second == expected_result );
    }
}
