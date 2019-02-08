#include <iostream>
#define CATCH_CONFIG_MAIN
#include "include/catch.hpp"
#include "lib/ends_with.hpp"

SCENARIO("test a postfix check", "[ends_with]")
{
    GIVEN("a bunch of samples")
    {
        std::string s("ciccio bello");
        const auto b = ends_with(s, "bello");
        REQUIRE(b);

        std::string p("bello");
        const auto with = ends_with("ciccio bello", p);
        REQUIRE(with);

        const auto c = ends_with(s, p);
        REQUIRE(c);

        const auto d = ends_with(std::string("ciccio bello"), std::string("bello"));
        REQUIRE(d);
    }
}