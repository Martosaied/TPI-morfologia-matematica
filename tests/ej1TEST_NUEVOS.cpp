//
// Created by martin on 2/11/19.
//

#include "gtest/gtest.h"
#include "../ejercicios.h"

TEST(esImagenValidaTest, ImagenSegundaFilaVaciaEsInvalida) {
    imagen img = {
            {1, 0, 1},
            {},
            {0, 0, 1},
    };
    EXPECT_FALSE(esImagenValida(img));
}

