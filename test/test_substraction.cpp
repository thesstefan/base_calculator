#include <catch2/catch.hpp>

#include "../src/number.hpp"

TEST_CASE("Subtraction between two numbers", "[Number::operator+]") {
    SECTION( "Base 2" ) {
        Number first = Number(2, "1010101010010100101");
        Number second = Number(2, "101111111111111");

        Number expected_result = Number(2, "1001111010010100110");

        REQUIRE( first - second == expected_result );
    }

    SECTION( "Base 7" ) {
        Number first = Number(7, "612631610");
        Number second = Number(7, "66316");

        Number expected_result = Number(7, "612532261");

        REQUIRE( first - second == expected_result );
    }

    SECTION( "Base 16" ) {
        Number first = Number(16, "EFA01AAF011");
        Number second = Number(16, "ABC01ED");

        Number expected_result = Number(16, "EF9F6EEEE24");

        REQUIRE( first - second == expected_result );
    }
}
