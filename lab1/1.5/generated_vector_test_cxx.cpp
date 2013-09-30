/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#define _CXXTEST_HAVE_EH
#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/ErrorPrinter.h>

int main() {
 return CxxTest::ErrorPrinter().run();
}
#include "test_cxx.cpp"

static MyTestSuite suite_MyTestSuite;

static CxxTest::List Tests_MyTestSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_MyTestSuite( "test_cxx.cpp", 4, "MyTestSuite", suite_MyTestSuite, Tests_MyTestSuite );

static class TestDescription_MyTestSuite_test_default_constructors : public CxxTest::RealTestDescription {
public:
 TestDescription_MyTestSuite_test_default_constructors() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 12, "test_default_constructors" ) {}
 void runTest() { suite_MyTestSuite.test_default_constructors(); }
} testDescription_MyTestSuite_test_default_constructors;

static class TestDescription_MyTestSuite_test_copy_constructor : public CxxTest::RealTestDescription {
public:
 TestDescription_MyTestSuite_test_copy_constructor() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 25, "test_copy_constructor" ) {}
 void runTest() { suite_MyTestSuite.test_copy_constructor(); }
} testDescription_MyTestSuite_test_copy_constructor;

static class TestDescription_MyTestSuite_test_move_constructor : public CxxTest::RealTestDescription {
public:
 TestDescription_MyTestSuite_test_move_constructor() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 49, "test_move_constructor" ) {}
 void runTest() { suite_MyTestSuite.test_move_constructor(); }
} testDescription_MyTestSuite_test_move_constructor;

static class TestDescription_MyTestSuite_test_initializer_list_constructor : public CxxTest::RealTestDescription {
public:
 TestDescription_MyTestSuite_test_initializer_list_constructor() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 66, "test_initializer_list_constructor" ) {}
 void runTest() { suite_MyTestSuite.test_initializer_list_constructor(); }
} testDescription_MyTestSuite_test_initializer_list_constructor;

static class TestDescription_MyTestSuite_test_copy_a_to_a : public CxxTest::RealTestDescription {
public:
 TestDescription_MyTestSuite_test_copy_a_to_a() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 78, "test_copy_a_to_a" ) {}
 void runTest() { suite_MyTestSuite.test_copy_a_to_a(); }
} testDescription_MyTestSuite_test_copy_a_to_a;

static class TestDescription_MyTestSuite_test_copy_a_bigger : public CxxTest::RealTestDescription {
public:
 TestDescription_MyTestSuite_test_copy_a_bigger() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 90, "test_copy_a_bigger" ) {}
 void runTest() { suite_MyTestSuite.test_copy_a_bigger(); }
} testDescription_MyTestSuite_test_copy_a_bigger;

static class TestDescription_MyTestSuite_test_copy_b_bigger : public CxxTest::RealTestDescription {
public:
 TestDescription_MyTestSuite_test_copy_b_bigger() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 108, "test_copy_b_bigger" ) {}
 void runTest() { suite_MyTestSuite.test_copy_b_bigger(); }
} testDescription_MyTestSuite_test_copy_b_bigger;

static class TestDescription_MyTestSuite_test_copy_equal_lengths : public CxxTest::RealTestDescription {
public:
 TestDescription_MyTestSuite_test_copy_equal_lengths() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 126, "test_copy_equal_lengths" ) {}
 void runTest() { suite_MyTestSuite.test_copy_equal_lengths(); }
} testDescription_MyTestSuite_test_copy_equal_lengths;

static class TestDescription_MyTestSuite_test_index_operator : public CxxTest::RealTestDescription {
public:
 TestDescription_MyTestSuite_test_index_operator() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 149, "test_index_operator" ) {}
 void runTest() { suite_MyTestSuite.test_index_operator(); }
} testDescription_MyTestSuite_test_index_operator;

static class TestDescription_MyTestSuite_test_move_assignment_operator : public CxxTest::RealTestDescription {
public:
 TestDescription_MyTestSuite_test_move_assignment_operator() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 156, "test_move_assignment_operator" ) {}
 void runTest() { suite_MyTestSuite.test_move_assignment_operator(); }
} testDescription_MyTestSuite_test_move_assignment_operator;

static class TestDescription_MyTestSuite_test_initialize_zero_size : public CxxTest::RealTestDescription {
public:
 TestDescription_MyTestSuite_test_initialize_zero_size() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 177, "test_initialize_zero_size" ) {}
 void runTest() { suite_MyTestSuite.test_initialize_zero_size(); }
} testDescription_MyTestSuite_test_initialize_zero_size;

static class TestDescription_MyTestSuite_test_negative_index : public CxxTest::RealTestDescription {
public:
 TestDescription_MyTestSuite_test_negative_index() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 186, "test_negative_index" ) {}
 void runTest() { suite_MyTestSuite.test_negative_index(); }
} testDescription_MyTestSuite_test_negative_index;

static class TestDescription_MyTestSuite_test_out_of_range : public CxxTest::RealTestDescription {
public:
 TestDescription_MyTestSuite_test_out_of_range() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 192, "test_out_of_range" ) {}
 void runTest() { suite_MyTestSuite.test_out_of_range(); }
} testDescription_MyTestSuite_test_out_of_range;

static class TestDescription_MyTestSuite_test_template_types : public CxxTest::RealTestDescription {
public:
 TestDescription_MyTestSuite_test_template_types() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 202, "test_template_types" ) {}
 void runTest() { suite_MyTestSuite.test_template_types(); }
} testDescription_MyTestSuite_test_template_types;

static class TestDescription_MyTestSuite_test_push_back : public CxxTest::RealTestDescription {
public:
 TestDescription_MyTestSuite_test_push_back() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 220, "test_push_back" ) {}
 void runTest() { suite_MyTestSuite.test_push_back(); }
} testDescription_MyTestSuite_test_push_back;

static class TestDescription_MyTestSuite_test_insert : public CxxTest::RealTestDescription {
public:
 TestDescription_MyTestSuite_test_insert() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 230, "test_insert" ) {}
 void runTest() { suite_MyTestSuite.test_insert(); }
} testDescription_MyTestSuite_test_insert;

static class TestDescription_MyTestSuite_test_erase : public CxxTest::RealTestDescription {
public:
 TestDescription_MyTestSuite_test_erase() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 243, "test_erase" ) {}
 void runTest() { suite_MyTestSuite.test_erase(); }
} testDescription_MyTestSuite_test_erase;

static class TestDescription_MyTestSuite_test_clear : public CxxTest::RealTestDescription {
public:
 TestDescription_MyTestSuite_test_clear() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 256, "test_clear" ) {}
 void runTest() { suite_MyTestSuite.test_clear(); }
} testDescription_MyTestSuite_test_clear;

static class TestDescription_MyTestSuite_test_size : public CxxTest::RealTestDescription {
public:
 TestDescription_MyTestSuite_test_size() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 265, "test_size" ) {}
 void runTest() { suite_MyTestSuite.test_size(); }
} testDescription_MyTestSuite_test_size;

static class TestDescription_MyTestSuite_test_sort : public CxxTest::RealTestDescription {
public:
 TestDescription_MyTestSuite_test_sort() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 280, "test_sort" ) {}
 void runTest() { suite_MyTestSuite.test_sort(); }
} testDescription_MyTestSuite_test_sort;

static class TestDescription_MyTestSuite_test_unique_sort : public CxxTest::RealTestDescription {
public:
 TestDescription_MyTestSuite_test_unique_sort() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 299, "test_unique_sort" ) {}
 void runTest() { suite_MyTestSuite.test_unique_sort(); }
} testDescription_MyTestSuite_test_unique_sort;

static class TestDescription_MyTestSuite_test_exists : public CxxTest::RealTestDescription {
public:
 TestDescription_MyTestSuite_test_exists() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 310, "test_exists" ) {}
 void runTest() { suite_MyTestSuite.test_exists(); }
} testDescription_MyTestSuite_test_exists;

#include <cxxtest/Root.cpp>
