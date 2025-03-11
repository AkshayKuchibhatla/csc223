#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <string>
#include <iostream>
#include "Evaluator.h"
using namespace std;

// TEST_CASE("Test eval.isValidExp") {
//     Evaluator eval;
//     string expr = "(4 + a) / c";
//     CHECK(eval.isValidExp(expr) == true);

//     expr = "(x * ((5 - d) + c) - y) * 2";
//     CHECK(eval.isValidExp(expr) == true);

//     expr = "(x * ((5 - d) + c - y) * 2";
//     CHECK(eval.isValidExp(expr) == false);

//     expr = "(xy * ((5 - ab) + c) - y) * 2";
//     CHECK(eval.isValidExp(expr) == true);

//     expr = "(x * ((5 - draw) + cat) - y) * 2";
//     CHECK(eval.isValidExp(expr) == true);

//     expr = "(x - y)(x + y)";
//     CHECK(eval.isValidExp(expr) == true);
// }

TEST_CASE("Test eval.isValidNumExp") {
    Evaluator eval;
    string expr = "(4 + 10) / (3 + 5)";

    CHECK(eval.isValidNumExp(expr) == true);
}