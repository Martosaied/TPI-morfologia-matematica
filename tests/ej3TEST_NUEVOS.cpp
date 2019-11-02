#include "gtest/gtest.h"
#include "../ejercicios.h"

double abs_error2 = 0.00001;

TEST(devolverPromedioAreasTest, promedioUnPixel) {
    imagen A = {{1}};
    EXPECT_NEAR(devolverPromedioAreas(A, 8), 1, abs_error2);
}


