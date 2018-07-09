//
// Created by ynakata on 09/07/2018.
//

#include "gtest/gtest.h"
#include "util/List.cpp"

class ConcreteItem{
public:

    /**
     * Constructor
     */
    ConcreteItem():value(0){}

    /**
     * Destructor
     */
    ~ConcreteItem() {}

    /**
     * Getter for value
     * @return
     */
    int getValue() const {
        return value;
    }

    /**
     *Setter for value
     * @param value
     */
    void setValue(int value) {
        ConcreteItem::value = value;
    }

    /**
     * Override '==' operator
     * @param it
     * @return
     */
    bool operator == (const ConcreteItem * it){
        return *this == it;
    }
private:
    /**
     * Value property
     */
    int value;
};

TEST(TestList, Should_return_not_null_list) {
    List<ConcreteItem> * testClass = new List<ConcreteItem>();
    EXPECT_TRUE(testClass != nullptr);
}

TEST(TestList, Size_should_long_equals_to_0) {
    List<ConcreteItem> testClass;
    EXPECT_EQ(testClass.size(), 0);
}

TEST(TestListAppend, should_throw_exception_when_max_capacity_exceeded) {
    //Arrange
    ConcreteItem concreteItem;
    ConcreteItem concreteItem2;
    List<ConcreteItem> testClass(1);

    int result = 0;

    //Act
    try{
        testClass.append(concreteItem);
        testClass.append(concreteItem2);
    } catch (int exception){
        result = exception;
    }

    //Assert
    EXPECT_EQ(result, 2);
}


TEST(TestList_size, Should_return_size_equal_to_2) {

    //Arrange
    ConcreteItem concreteItem;
    concreteItem.setValue(0);
    ConcreteItem concreteItem2;
    concreteItem2.setValue(1);
    List<ConcreteItem> testClass;
    testClass.append(concreteItem);
    testClass.append(concreteItem2);

    //Act
    long result = testClass.size();

    //Assert
    EXPECT_EQ(result, 2);
}

TEST(TestList_Get, should_return_a_not_null_ptr_when_index_is_0_and_1) {

    //Arrange
    ConcreteItem concreteItem;
    concreteItem.setValue(777);
    ConcreteItem concreteItem2;
    concreteItem2.setValue(1);

    List<ConcreteItem> testClass;
    testClass.append(concreteItem);
    testClass.append(concreteItem2);

    //Act
    ConcreteItem result = testClass.get(0);

    //Assert
    EXPECT_EQ(result.getValue(), 777);
}

TEST(TestList_get, should_throw_exeption_when_index_is_out_of_bound) {

    //Arrange
    ConcreteItem concreteItem;
    concreteItem.setValue(777);

    List<ConcreteItem> testClass;
    testClass.append(concreteItem);

    int result = 0;

    //Act
    try{
        testClass.get(2);
    } catch (int e){
        result = e;
    }

    //Assert
    EXPECT_EQ(result, 1);
}

TEST(TestList_indexOf, Should_return_0) {

    //Arrange
    List<ConcreteItem> testClass;
    ConcreteItem concreteItem;
    testClass.append(concreteItem);

    //Act
    long result = testClass.indexOf(concreteItem);

    //Assert
    EXPECT_EQ(result, 0);
}

TEST(TestList_indexOf, Should_return_minus_1) {

    //Arrange
    List<ConcreteItem> testClass;
    ConcreteItem concreteItem;
    ConcreteItem concreteItem2;
    testClass.append(concreteItem);

    //Act
    long result = testClass.indexOf(concreteItem2);

    //Assert
    EXPECT_EQ(result, 0);
}