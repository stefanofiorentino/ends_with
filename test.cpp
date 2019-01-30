#include <iostream>

#define CATCH_CONFIG_MAIN

#include "include/catch.hpp"
#include "lib/ends_with.hpp"

SCENARIO("test a postfix check", "[ends_with]")
{
    GIVEN("two string")
    {
        std::string s("ciccio bello");
        std::string p("bello");
        REQUIRE(ends_with(std::begin(s), std::end(s), std::begin(p)));
        std::string p1("bell");
        REQUIRE_FALSE(ends_with(std::begin(s), std::end(s), std::begin(p1)));
    }
    GIVEN("a vector")
    {
        std::vector<int> s(10, 10);
        s.emplace_back(9);
        s.emplace_back(8);
        s.emplace_back(7);
        std::vector<int> p;
        p.emplace_back(8);
        p.emplace_back(7);
        REQUIRE(ends_with<std::vector<int>>(s, p));
        REQUIRE(ends_with(s, p));
        p.pop_back();
        REQUIRE_FALSE(ends_with(s, p));
    }
}