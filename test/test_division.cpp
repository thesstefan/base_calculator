#include <catch2/catch.hpp>

#include "../src/number.hpp"

TEST_CASE("Division by digit", "[Number::operator/]") {
    SECTION( "Base 10" ) {
        Number<10> dividend = Number<10>("1293892");
        Number<10> divisor = Number<10>("8");

        Number<10> expected_quotinent = Number<10>("161736");
        Number<10> expected_remainder = Number<10>("4");

        auto result = dividend / divisor;

        REQUIRE( result.first == expected_quotinent );
        REQUIRE( result.second == expected_remainder );
    }

    SECTION( "Base 7" ) {
        Number<7> dividend = Number<7>("101440212");
        Number<7> divisor = Number<7>("6");

        Number<7> expected_quotinent = Number<7>("11304501");
        Number<7> expected_remainder = Number<7>("3");

        auto result = dividend / divisor;

        REQUIRE( result.first == expected_quotinent );
        REQUIRE( result.second == expected_remainder );
    }

    SECTION( "Base 16" ) {
        Number<16> dividend = Number<16>("ABCDEF");
        Number<16> divisor = Number<16>("8");

        Number<16> expected_quotinent = Number<16>("1579BD");
        Number<16> expected_remainder = Number<16>("7");

        auto result = dividend / divisor;

        REQUIRE( result.first == expected_quotinent );
        REQUIRE( result.second == expected_remainder );
    }
}
