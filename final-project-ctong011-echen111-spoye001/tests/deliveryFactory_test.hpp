#ifndef __FACT_TEST_HPP__
#define __FACT_TEST_HPP__
#include "gtest/gtest.h"
#include "../header/restaurant.hpp"
#include "../header/item.hpp"
#include "../header/tag.hpp"
#include "../header/factory.hpp"
#include "../header/fooditem.hpp"
#include "../header/category.hpp"

TEST(FactoryTest, PriceUEFactoryTest) {
    Restaurant* test = new Restaurant("Chick-Fil-A");
    Factory* fact = new UberEatsFactory(test);
    fact->createPriceBreakdown();
}

TEST(FactoryTest, PriceDDFactoryTest) {
    Restaurant* test = new Restaurant("Chick-Fil-A");
    Factory* fact = new DoorDashFactory(test);
    fact->createPriceBreakdown();
}

TEST(FactoryTest, TimeUEFactoryTest) {
    Restaurant* test = new Restaurant("Chick-Fil-A");
    Factory* fact = new UberEatsFactory(test);
    fact->createTimeBreakdown();
}

TEST(FactoryTest, TimeDDFactoryTest) {
    Restaurant* test = new Restaurant("Chick-Fil-A");
    Factory* fact = new DoorDashFactory(test);
    fact->createTimeBreakdown();
}

#endif //__FACT_TEST_HPP__
