#include "gtest/gtest.h"
#include "../ejercicios.h"

TEST(sonPixelesConectadosTest, PixelesIgualesEstanConectados) {
    imagen img = {
            {1, 0, 0, 0, 0, 0, 1, 0},
            {1, 0, 0, 1, 0, 0, 1, 1},
            {1, 1, 0, 1, 0, 0, 0, 1},
            {0, 1, 1, 1, 1, 1, 1, 1},
            {1, 1, 1, 0, 0, 1, 0, 0},
    };
    pixel p = {3, 2};
    pixel q = {3, 2};
    EXPECT_TRUE(sonPixelesConectados(img, p, q, 4));
}

TEST(sonPixelesConectadosTest, PixelesApagadosNoEstanConectadosAdy4) {
    imagen img = {
            {0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0},
    };
    pixel p = {0, 0};
    pixel q = {0, 6};
    EXPECT_FALSE(sonPixelesConectados(img, p, q, 4));
}

TEST(sonPixelesConectadosTest, PixelesApagadosNoEstanConectadosAdy8) {
    imagen img = {
            {0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0},
    };
    pixel p = {0, 0};
    pixel q = {0, 6};
    EXPECT_FALSE(sonPixelesConectados(img, p, q, 8));
}
