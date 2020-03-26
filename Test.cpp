

#include "doctest.h"
#include "PhoneticFinder.hpp"
using namespace phonetic;

#include <string>
using namespace std;


TEST_CASE("Test replacement of v and w") {
    string text = "xxx view yyy www";
    CHECK(find(text, "view") == string("view"));
	CHECK(find(text, "wiev") == string("view"));
	CHECK(find(text, "viev") == string("view"));
	CHECK(find(text, "wiew") == string("view"));
	CHECK(find(text, "vvv") == string("www"));
	CHECK(find(text, "wvv") == string("www"));
	CHECK(find(text, "wwv") == string("www"));
	CHECK(find(text, "www") == string("www"));
	CHECK(find(text, "vwv") == string("www"));
	CHECK(find(text, "vww") == string("www"));
	CHECK(find(text, "vvw") == string("www"));
}
TEST_CASE("Test replacement of p and b and f") {
    string text = "xxx happy yyy";
    CHECK(find(text, "happy") == string("happy"));
    CHECK(find(text, "habby") == string("happy"));
    CHECK(find(text, "haffy") == string("happy"));
    CHECK(find(text, "hapby") == string("happy"));
	CHECK(find(text, "habpy") == string("happy"));
	CHECK(find(text, "hapfy") == string("happy"));
	CHECK(find(text, "hafpy") == string("happy"));
	CHECK(find(text, "habfy") == string("happy"));
	CHECK(find(text, "hafby") == string("happy"));
}
TEST_CASE("Test replacement of g and j") {
    string text = "xxx haggy good job yyy";
    CHECK(find(text, "haggy") == string("haggy"));
    CHECK(find(text, "hajjy") == string("haggy"));
    CHECK(find(text, "hagjy") == string("haggy"));
    CHECK(find(text, "hajgy") == string("haggy"));
	CHECK(find(text, "good") == string("good"));
	CHECK(find(text, "jood") == string("good"));
	CHECK(find(text, "job") == string("job"));
	CHECK(find(text, "gob") == string("job"));
}

TEST_CASE("Test replacement of c and k and q") {
    string text = "xxx cool cake quit yyy";
    CHECK(find(text, "kool") == string("cool"));
    CHECK(find(text, "qool") == string("cool"));
    CHECK(find(text, "cool") == string("cool"));
	CHECK(find(text, "qake") == string("cake"));
	CHECK(find(text, "cace") == string("cake"));
	CHECK(find(text, "qace") == string("cake"));
	CHECK(find(text, "cake") == string("cake"));
	CHECK(find(text, "caqe") == string("cake"));
	CHECK(find(text, "qaqe") == string("cake"));
	CHECK(find(text, "kake") == string("cake"));
	CHECK(find(text, "kaqe") == string("cake"));
	CHECK(find(text, "quit") == string("quit"));
	CHECK(find(text, "cuit") == string("quit"));
	CHECK(find(text, "kuit") == string("quit"));
}
TEST_CASE("Test replacement of s and z") {
    string text = "xxx cheese zzz";
    CHECK(find(text, "cheese") == string("cheese"));
	CHECK(find(text, "cheeze") == string("cheese"));
	CHECK(find(text, "zheese") == string("cheese"));
	CHECK(find(text, "zheeze") == string("cheese"));
	CHECK(find(text, "zzz") == string("zzz"));
	CHECK(find(text, "sss") == string("zzz"));
	CHECK(find(text, "zsz") == string("zzz"));
	CHECK(find(text, "szz") == string("zzz"));
	CHECK(find(text, "zzs") == string("zzz"));
	CHECK(find(text, "ssz") == string("zzz"));
	CHECK(find(text, "zss") == string("zzz"));
}
TEST_CASE("Test replacement of d and t") {
    string text = "xxx door to ddd";
    CHECK(find(text, "door") == string("door"));
	CHECK(find(text, "toor") == string("door"));	
	CHECK(find(text, "to") == string("to"));
	CHECK(find(text, "do") == string("to"));
	CHECK(find(text, "ddd") == string("ddd"));
	CHECK(find(text, "ttt") == string("ddd"));
	CHECK(find(text, "ttd") == string("ddd"));
	CHECK(find(text, "dtt") == string("ddd"));
	CHECK(find(text, "tdd") == string("ddd"));
	CHECK(find(text, "dtd") == string("ddd"));
	CHECK(find(text, "ddt") == string("ddd"));
}
TEST_CASE("Test replacement of o and u") {
    string text = "xxx door to uuu";
    CHECK(find(text, "door") == string("door"));
	CHECK(find(text, "duur") == string("door"));
	CHECK(find(text, "dour") == string("door"));
	CHECK(find(text, "duor") == string("door"));
	CHECK(find(text, "tu") == string("to"));
	CHECK(find(text, "uuu") == string("uuu"));
	CHECK(find(text, "ouu") == string("uuu"));
	CHECK(find(text, "uou") == string("uuu"));
	CHECK(find(text, "uuo") == string("uuu"));
	CHECK(find(text, "oou") == string("uuu"));
	CHECK(find(text, "uoo") == string("uuu"));
	CHECK(find(text, "ooo") == string("uuu"));
}
TEST_CASE("Test replacement of i and y") {
    string text = "i xxx illusion iii";
	CHECK(find(text, "y") == string("i"));
	CHECK(find(text, "i") == string("i"));
	CHECK(find(text, "iii") == string("iii"));
	CHECK(find(text, "yii") == string("iii"));
	CHECK(find(text, "iyi") == string("iii"));
	CHECK(find(text, "iiy") == string("iii"));
	CHECK(find(text, "yyi") == string("iii"));
	CHECK(find(text, "iyy") == string("iii"));
	CHECK(find(text, "yyy") == string("iii"));
	CHECK(find(text, "illusion") == string("illusion"));
	CHECK(find(text, "illusyon") == string("illusion"));
	CHECK(find(text, "yllusion") == string("illusion"));
	CHECK(find(text, "yllusyon") == string("illusion"));
}

TEST_CASE("Test replacement of lower-case and upper-case") {
    string text = "Happi xxx slEEp yyy";
    CHECK(find(text, "happi") == string("Happi"));
    CHECK(find(text, "Happi") == string("Happi"));
    CHECK(find(text, "HAPPI") == string("Happi"));
    CHECK(find(text, "HaPpI") == string("Happi"));
	CHECK(find(text, "HAPPI") == string("Happi"));
	CHECK(find(text, "HAPpI") == string("Happi"));
	CHECK(find(text, "slEEp") == string("slEEp"));
	CHECK(find(text, "sleep") == string("slEEp"));
	CHECK(find(text, "SLEEp") == string("slEEp"));
	CHECK(find(text, "SLEEP") == string("slEEp"));
	CHECK(find(text, "SLeep") == string("slEEp"));
	CHECK(find(text, "slEep") == string("slEEp"));
	CHECK(find(text, "sleEp") == string("slEEp"));
}

