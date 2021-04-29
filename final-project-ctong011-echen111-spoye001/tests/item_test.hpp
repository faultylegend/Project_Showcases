#ifndef __ITEM_TEST_HPP__
#define __ITEM__TEST_HPP__
#include "gtest/gtest.h"
#include "../header/item.hpp"

TEST(ItemTest, GetterItemTest) {
    Item* test = new Item("Cookie", 1.00);
    
    EXPECT_EQ(test->getName(), "Cookie");
    EXPECT_EQ(test->getPrice(), 1.00);
    delete test;
}

TEST(ItemTest, SetterItemTest) {
    Item* test = new Item();
    Item* test2 = new Item("Cookie", 1.00);
    
    EXPECT_EQ(test->getName(), "");
    EXPECT_EQ(test->getPrice(), -1);
    test->setName("Cake");
    EXPECT_EQ(test->getName(), "Cake");
    test->setPrice(30.00);
    EXPECT_EQ(test->getPrice(), 30.00);
    test2->setName("Brownie");
    EXPECT_EQ(test2->getName(), "Brownie");
    test2->setPrice(3.30);
    EXPECT_EQ(test2->getPrice(), 3.30);

    delete test;
    delete test2;
}

TEST(ItemTest, DisplayEqualityItemTest) {
    Item* test = new Item("Cream Puff", 1.50);
    test->displayItem();
    Item* test2 = new Item("Pudding", 1.50 );
    test2->displayItem();
    EXPECT_EQ(test == test2, false);

    delete test;
    delete test2;
}
/*
TEST(ItemTest, BasicItemTest) {
    Item* test1 = new Item("Chicken Sandwich", 5.99);
    Item* test2 = new Item("Medium Drink", 1.99);
    
    EXPECT_EQ(test->getItem(0), item1);
    test->removeItem(item1);
    EXPECT_EQ(test->getItem(0), item2);
}
*/
#endif
