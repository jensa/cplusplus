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
#include <cxxtest/TestMain.h>
#include <cxxtest/ErrorPrinter.h>

int main( int argc, char *argv[] ) {
 int status;
    CxxTest::ErrorPrinter tmp;
    status = CxxTest::Main<CxxTest::ErrorPrinter>( tmp, argc, argv );
    return status;
}
bool suite_MyTestSuite_init = false;
#include "test_cxx.cpp"

static MyTestSuite suite_MyTestSuite;

static CxxTest::List Tests_MyTestSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_MyTestSuite( "test_cxx.cpp", 4, "MyTestSuite", suite_MyTestSuite, Tests_MyTestSuite );

static class TestDescription_suite_MyTestSuite_test_initialized_as_zero : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_initialized_as_zero() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 8, "test_initialized_as_zero" ) {}
 void runTest() { suite_MyTestSuite.test_initialized_as_zero(); }
} testDescription_suite_MyTestSuite_test_initialized_as_zero;

static class TestDescription_suite_MyTestSuite_test_vector_with_length_zero : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_vector_with_length_zero() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 15, "test_vector_with_length_zero" ) {}
 void runTest() { suite_MyTestSuite.test_vector_with_length_zero(); }
} testDescription_suite_MyTestSuite_test_vector_with_length_zero;

static class TestDescription_suite_MyTestSuite_test_set : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_set() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 22, "test_set" ) {}
 void runTest() { suite_MyTestSuite.test_set(); }
} testDescription_suite_MyTestSuite_test_set;

static class TestDescription_suite_MyTestSuite_test_negative_index : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_negative_index() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 30, "test_negative_index" ) {}
 void runTest() { suite_MyTestSuite.test_negative_index(); }
} testDescription_suite_MyTestSuite_test_negative_index;

static class TestDescription_suite_MyTestSuite_test_out_of_range : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_out_of_range() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 36, "test_out_of_range" ) {}
 void runTest() { suite_MyTestSuite.test_out_of_range(); }
} testDescription_suite_MyTestSuite_test_out_of_range;

static class TestDescription_suite_MyTestSuite_test_copy_equal_lengths : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_copy_equal_lengths() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 42, "test_copy_equal_lengths" ) {}
 void runTest() { suite_MyTestSuite.test_copy_equal_lengths(); }
} testDescription_suite_MyTestSuite_test_copy_equal_lengths;

static class TestDescription_suite_MyTestSuite_test_copy_a_to_a : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_copy_a_to_a() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 61, "test_copy_a_to_a" ) {}
 void runTest() { suite_MyTestSuite.test_copy_a_to_a(); }
} testDescription_suite_MyTestSuite_test_copy_a_to_a;

static class TestDescription_suite_MyTestSuite_test_copy_a_bigger : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_copy_a_bigger() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 71, "test_copy_a_bigger" ) {}
 void runTest() { suite_MyTestSuite.test_copy_a_bigger(); }
} testDescription_suite_MyTestSuite_test_copy_a_bigger;

static class TestDescription_suite_MyTestSuite_test_copy_b_bigger : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_copy_b_bigger() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 89, "test_copy_b_bigger" ) {}
 void runTest() { suite_MyTestSuite.test_copy_b_bigger(); }
} testDescription_suite_MyTestSuite_test_copy_b_bigger;

static class TestDescription_suite_MyTestSuite_test_copy_constructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_copy_constructor() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 107, "test_copy_constructor" ) {}
 void runTest() { suite_MyTestSuite.test_copy_constructor(); }
} testDescription_suite_MyTestSuite_test_copy_constructor;

static class TestDescription_suite_MyTestSuite_test_move_constructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_move_constructor() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 131, "test_move_constructor" ) {}
 void runTest() { suite_MyTestSuite.test_move_constructor(); }
} testDescription_suite_MyTestSuite_test_move_constructor;

static class TestDescription_suite_MyTestSuite_test_move_assignment_operator : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_move_assignment_operator() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 148, "test_move_assignment_operator" ) {}
 void runTest() { suite_MyTestSuite.test_move_assignment_operator(); }
} testDescription_suite_MyTestSuite_test_move_assignment_operator;

static class TestDescription_suite_MyTestSuite_test_exists : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_exists() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 165, "test_exists" ) {}
 void runTest() { suite_MyTestSuite.test_exists(); }
} testDescription_suite_MyTestSuite_test_exists;

static class TestDescription_suite_MyTestSuite_test_template_zeros : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_template_zeros() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 174, "test_template_zeros" ) {}
 void runTest() { suite_MyTestSuite.test_template_zeros(); }
} testDescription_suite_MyTestSuite_test_template_zeros;

static class TestDescription_suite_MyTestSuite_test_sort : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_test_sort() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 187, "test_sort" ) {}
 void runTest() { suite_MyTestSuite.test_sort(); }
} testDescription_suite_MyTestSuite_test_sort;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
