// Uncomment the next line to use precompiled headers
#include "pch.h"
#include <exception>
// uncomment the next line if you do not use precompiled headers
//#include "gtest/gtest.h"
//
// the global test environment setup and tear down
// you should not need to change anything here
class Environment : public ::testing::Environment
{
public:
    ~Environment() override {}

    // Override this to define how to set up the environment.
    void SetUp() override
    {
        //  initialize random seed
        srand(time(nullptr));
    }

    // Override this to define how to tear down the environment.
    void TearDown() override {}
};

// create our test class to house shared data between tests
// you should not need to change anything here
class CollectionTest : public ::testing::Test
{
protected:
    // create a smart point to hold our collection
    std::unique_ptr<std::vector<int>> collection;

    void SetUp() override
    { // create a new collection to be used in the test
        collection.reset(new std::vector<int>);
    }

    void TearDown() override
    { //  erase all elements in the collection, if any remain
        collection->clear();
        // free the pointer
        collection.reset(nullptr);
    }

    // helper function to add random values from 0 to 99 count times to the collection
    void add_entries(int count)
    {
        assert(count > 0);
        for (auto i = 0; i < count; ++i)
            collection->push_back(rand() % 100);
    }
};

// When should you use the EXPECT_xxx or ASSERT_xxx macros?
// Use ASSERT when failure should terminate processing, such as the reason for the test case.
// Use EXPECT when failure should notify, but processing should continue

// Test that a collection is empty when created.
// Prior to calling this (and all other TEST_F defined methods),
//  CollectionTest::StartUp is called.
// Following this method (and all other TEST_F defined methods),
//  CollectionTest::TearDown is called

TEST_F(CollectionTest, CollectionSmartPointerIsNotNull)
{
    // is the collection created
    ASSERT_TRUE(collection);

    // if empty, the size must be 0
    ASSERT_NE(collection.get(), nullptr);
}

// Test that a collection is empty when created.
TEST_F(CollectionTest, IsEmptyOnCreate)
{
    // is the collection empty?
    ASSERT_TRUE(collection->empty());

    // if empty, the size must be 0
    ASSERT_EQ(collection->size(), 0);
}

/* Comment this test out to prevent the test from running
 * Uncomment this test to see a failure in the test explorer */
TEST_F(CollectionTest, AlwaysFail)
{
    FAIL();
}

// Created a test to verify adding a single value to an empty collection

TEST_F(CollectionTest, CanAddToEmptyVector)
{
    // is the collection empty?
    
    ASSERT_TRUE(collection->empty());
 
    // if empty, the size must be 0

    ASSERT_EQ(collection->size(), 0);

    add_entries(1);

    // is the collection still empty?
    // We don't want collection to be empty since we added. 
     
    ASSERT_FALSE(collection->empty());

    // if not empty, what must the size be?
    // We want collection size to be one now 

    ASSERT_EQ(collection->size(), 1);

}

// TODO: Create a test to verify adding five values to collection

TEST_F(CollectionTest, CanAddFiveValuesToVector)
{
    add_entries(5);

    ASSERT_FALSE(collection->empty());

    ASSERT_EQ(collection->size(),5);
}

// TODO: Create a test to verify that max size is greater than or equal to size for 0, 1, 5, 10 entries

TEST_F(CollectionTest, MaxIsGreaterThanTheseValues)
{
    ASSERT_TRUE(collection->max_size() >= 0);
    ASSERT_TRUE(collection->max_size() >= 1);
    ASSERT_TRUE(collection->max_size() >= 5);
    ASSERT_TRUE(collection->max_size() >= 10);

    //EXPECT_GE(collection->max_size(), 0);
    //EXPECT_GE(collection->max_size(), 1);
    //EXPECT_GE(collection->max_size(), 5);
    //EXPECT_GE(collection->max_size(), 10);
    //std::cout << collection->max_size() << std::endl;
}

// TODO: Create a test to verify that capacity is greater than or equal to size for 0, 1, 5, 10 entries

TEST_F(CollectionTest, CapacityIsGreaterThanTheseValues)
{
    if (collection->size() == 0)
    {
        ASSERT_TRUE((collection->capacity()) >= (collection->size()));
    }

    if (collection->size() == 1)
    {
        ASSERT_TRUE((collection->capacity()) >= (collection->size()));
    }

    if (collection->size() == 5)
    {
        ASSERT_TRUE((collection->capacity()) >= (collection->size()));
    }

    if (collection->size() == 10)
    {
        ASSERT_TRUE((collection->capacity()) >= (collection->size()));
    }
    
    // Check collection for max size
    //EXPECT_GE(collection->max_size(), 0);
    //EXPECT_GE(collection->max_size(), 1);
    //EXPECT_GE(collection->max_size(), 5);
    //EXPECT_GE(collection->max_size(), 10);
    //std::cout << collection->max_size() << std::endl;
    
}

// TODO: Create a test to verify resizing increases the collection

TEST_F(CollectionTest, ResizingIncreasesCollection)
{
    //add one from collection size and verify it is greater than before 
    int PreviousCollectionSize = collection->size(); 

    //int newCollectionSize = collection->resize(PreviousCollectionSize + 1); 

    //ASSERT_TRUE((collection->resize((collection->size()) + 1)) > PreviousCollectionSize); 

    //ASSERT_TRUE(resize(collection));


}

// TODO: Create a test to verify resizing decreases the collection

TEST_F(CollectionTest, ResizingDecreasesCollection)
{
    //Minus one from collection size and verify it is less thatn 
    int PreviousCollectionSize = collection->size();

    //int newCollectionSize = collection->resize(PreviousCollectionSize + 1); 

    //ASSERT_TRUE((collection->resize((collection->size()) + 1)) > PreviousCollectionSize); 

    //ASSERT_TRUE(resize(collection));
}

// TODO: Create a test to verify resizing decreases the collection to zero

TEST_F(CollectionTest, ResizingDecreasesCollectionToZero)
{
    
    collection->resize(0); 
    
    // is the collection empty?
    ASSERT_TRUE(collection->empty());

    // if empty, the size must be 0
    ASSERT_EQ(collection->size(), 0);
    
}

// TODO: Create a test to verify clear erases the collection

TEST_F(CollectionTest, ClearErasesCollection)
{
    collection->clear(); 

    ASSERT_TRUE(collection->empty());

    // if empty, the size must be 0
    ASSERT_EQ(collection->size(), 0);
}

// TODO: Create a test to verify erase(begin,end) erases the collection


TEST_F(CollectionTest, EraseErasesCollection)
{
    int x = (collection->max_size());

    //collection->erase(0, x); 

    ASSERT_TRUE(collection->empty());

    // if empty, the size must be 0
    ASSERT_EQ(collection->size(), 0);
}

// TODO: Create a test to verify reserve increases the capacity but not the size of the collection

TEST_F(CollectionTest,ReserveIncreasesCapacity)
{
    int FirstCapacityOfCollection = (collection->capacity()); 

    int firstSizeOfCollection = (collection->size()); 
    
    collection->reserve(200);

    int secondCapacityOfCollection = (collection->capacity());

    int secondSizeOfCollection = (collection->size());

    //Size should not change after resever changed
    ASSERT_EQ(firstSizeOfCollection, secondSizeOfCollection); 

    //Capacity has increased with reseve increase
    ASSERT_TRUE(secondCapacityOfCollection > FirstCapacityOfCollection);

    //WHAT IS RESERVE METHOD? SHOWN BELOW 

   /*  CONSTEXPR20_CONTAINER void reserve(_CRT_GUARDOVERFLOW const size_type _Newcapacity) {
        // increase capacity to _Newcapacity (without geometric growth), provide strong guarantee
        if (_Newcapacity > capacity()) { // something to do (reserve() never shrinks)
            if (_Newcapacity > max_size()) {
                _Xlength();
            }

            _Reallocate_exactly(_Newcapacity);
        }
    }
    */
}

// TODO: Create a test to verify the std::out_of_range exception is thrown when calling at() with an index out of bounds
// NOTE: This is a negative test

TEST_F(CollectionTest, OutOfRangeException)
{
    try {
        collection->at(5000000000000000000);       // at throws an out-of-range
    }
    catch (const std::out_of_range& oor) {
        ASSERT_TRUE(std::cerr << "\nOut of Range error: " << oor.what());
        std::cerr << "\n\n";
    }
}



// TODO: Create 2 unit tests of your own to test something on the collection - do 1 positive & 1 negative

TEST_F(CollectionTest, SizeIsLessThanMaxSize)
{
    int x = (collection->size());

    int y = (collection->max_size());

    //ASSERT_TRUE(x <= y); 
    EXPECT_TRUE(x <= y);
}

TEST_F(CollectionTest, AddEntriesSeperatly)
{
    
    //clear collection
    collection->clear();

    ASSERT_TRUE(collection->empty());

    //Call Add entry 5 seperatate times
    
    add_entries(1);
    add_entries(1);
    add_entries(1);
    add_entries(1);
    add_entries(1);

    //Expect colltection size to be 5


    EXPECT_TRUE(collection->size(), 5);
}


//Included One addtional test to try to make sure it was a negatvie test



TEST_F(CollectionTest, SubtractFromEmptyCollection)
{
    collection->clear();

    ASSERT_TRUE(collection->empty());

    //Verifies collection size is zero if we try to subtract from an empty collection

    try {
        collection->resize(-1); 
    }
    catch(const std::exception& exception){

        ASSERT_EQ(collection->size(), 0);
        std::cerr << "\nCan't Subtract from a collection with Zero Entries\n\n";

    }
        
}