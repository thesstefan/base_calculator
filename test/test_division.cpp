#include <catch2/catch.hpp>

#include "../src/number.hpp"

TEST_CASE("Division by digit", "[Number::operator/]") {
    SECTION( "Base 10" ) {
        Number dividend = Number(10, "1293892");
        Number divisor = Number(10, "8");

        Number expected_quotinent = Number(10, "161736");
        Number expected_remainder = Number(10, "4");

        auto result = dividend / divisor;

        REQUIRE( result.first == expected_quotinent );
        REQUIRE( result.second == expected_remainder );
    }

    SECTION( "Base 7" ) {
        Number dividend = Number(7, "101440212");
        Number divisor = Number(7, "6");

        Number expected_quotinent = Number(7, "11304501");
        Number expected_remainder = Number(7, "3");

        auto result = dividend / divisor;

        REQUIRE( result.first == expected_quotinent );
        REQUIRE( result.second == expected_remainder );
    }

    SECTION( "Base 16" ) {
        Number dividend = Number(16, "ABCDEF");
        Number divisor = Number(16, "8");

        Number expected_quotinent = Number(16, "1579BD");
        Number expected_remainder = Number(16, "7");

        auto result = dividend / divisor;

        REQUIRE( result.first == expected_quotinent );
        REQUIRE( result.second == expected_remainder );
    }
}
