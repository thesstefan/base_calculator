#include <catch2/catch.hpp>

#include "../src/number.hpp"

TEST_CASE("Multiplication by digit", "[Number::operator*]") {
    SECTION( "Base 10" ) {
        Number<10> first = Number<10>("696969696969");
        Number<10> second = Number<10>("8");

        Number<10> expected_result = Number<10>("5575757575752");

        REQUIRE( first * second == expected_result );
    }

    SECTION( "Base 7" ) {
        Number<7> first = Number<7>("612631610");
        Number<7> second = Number<7>("6");

        Number<7> expected_result = Number<7>("5213354160");

        REQUIRE( first * second == expected_result );
    }

    SECTION( "Base 16" ) {
        Number<16> first = Number<16>("ABC01ED");
        Number<16> second = Number<16>("E");

        Number<16> expected_result = Number<16>("96481AF6");

        REQUIRE( first * second == expected_result );
    }
}
