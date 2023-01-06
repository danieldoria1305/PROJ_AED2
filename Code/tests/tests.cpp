//
// Created by pedropassos on 05-01-2023.
//
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "FlightGraphs.h"

using testing::Eq;

TEST(test_1a, distance) {
    cout << "Testando 'distance'" << endl;

    cout << "  . graph1" << endl;
    Flights g1 = FlightGraphs::graph1();
    EXPECT_EQ(0, g1.distance("1","1"));
    EXPECT_EQ(1, g1.distance("1","2"));
    EXPECT_EQ(1, g1.distance("1","3"));
    EXPECT_EQ(2, g1.distance("1","4"));
    EXPECT_EQ(3, g1.distance("1","5"));
    EXPECT_EQ(4, g1.distance("1","6"));
    EXPECT_EQ(4, g1.distance("1","7"));
    EXPECT_EQ(5, g1.distance("1","8"));
    EXPECT_EQ(5, g1.distance("1","9"));
    EXPECT_EQ(0, g1.distance("4","4"));
    EXPECT_EQ(1, g1.distance("4","5"));
    EXPECT_EQ(2, g1.distance("4","6"));
    EXPECT_EQ(2, g1.distance("4","7"));
    EXPECT_EQ(3, g1.distance("4","8"));
    EXPECT_EQ(3, g1.distance("4","9"));
    EXPECT_EQ(4, g1.distance("2","8"));
}