#include <catch2/catch.hpp>

#include "../src/number.hpp"

TEST_CASE("Addition between two numbers", "[Number::operator+]") {
    SECTION( "Base 2" ) {
        Number<2> first = Number<2>("1010101010010100101");
        Number<2> second = Number<2>("101111111111111");

        Number<2> expected_result = Number<2>("1011011010010100100");

        REQUIRE( first + second == expected_result );
    }

    SECTION( "Base 7" ) {
        Number<7> first = Number<7>("612631610");
        Number<7> second = Number<7>("66316");

        Number<7> expected_result = Number<7>("613031226");

        REQUIRE( first + second == expected_result );
    }

    SECTION( "Base 16" ) {
        Number<16> first = Number<16>("ABC01ED");
        Number<16> second = Number<16>("EFA01AAF011");

        Number<16> expected_result = Number<16>("EFA0C66F1FE");

        REQUIRE( first + second == expected_result );
    }
}
