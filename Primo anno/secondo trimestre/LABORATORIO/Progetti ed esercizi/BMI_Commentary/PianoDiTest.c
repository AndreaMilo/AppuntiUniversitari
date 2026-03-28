#include "unity.c"
#include "unity.h"
#include "unity_internals.h"
#include "BMI.h"
#include <stdio.h>
#include <stdlib.h>

void setUp(void) {
    // This function is called before each test case.
    // You can use it to set up any necessary state or resources.
}

void tearDown(void) {
    // This function is called after each test case.
    // You can use it to clean up any resources or state.
}

//Asserzioni e metodi di test
void test_CalcoloMedia(void) {
    //seguendo lo schema di test di Unix --> TEST(expression/expetted, actual) continua ancora a non andare
    TEST_ASSERT_EQUAL_FLOAT(15, CalcoloMedia(10,20));  
}
void test_Esamesuperato(void) {
    TEST_ASSERT_EQUAL(1, Esamesuperato(20));
}
void test_CalcoloBMI(void) {
    TEST_ASSERT_EQUAL(15.44, CalcoloBMI(60, 1.8)); // 60 / (1.8 * 1.8) = 15.44?
}


int main(){
    UNITY_BEGIN();
    RUN_TEST(test_CalcoloMedia);
    RUN_TEST(test_Esamesuperato);
    RUN_TEST(test_CalcoloBMI);

    return UNITY_END();
} 