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
#include "test_must_follow_a.cpp"

static MyTestSuite suite_MyTestSuite;

static CxxTest::List Tests_MyTestSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_MyTestSuite( "test_must_follow_a.cpp", 5, "MyTestSuite", suite_MyTestSuite, Tests_MyTestSuite );

static class TestDescription_MyTestSuite_test_a_is_second_to_last : public CxxTest::RealTestDescription {
public:
 TestDescription_MyTestSuite_test_a_is_second_to_last() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 17, "test_a_is_second_to_last" ) {}
 void runTest() { suite_MyTestSuite.test_a_is_second_to_last(); }
} testDescription_MyTestSuite_test_a_is_second_to_last;

static class TestDescription_MyTestSuite_test_two_occurences : public CxxTest::RealTestDescription {
public:
 TestDescription_MyTestSuite_test_two_occurences() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 24, "test_two_occurences" ) {}
 void runTest() { suite_MyTestSuite.test_two_occurences(); }
} testDescription_MyTestSuite_test_two_occurences;

static class TestDescription_MyTestSuite_test_b_after_vector : public CxxTest::RealTestDescription {
public:
 TestDescription_MyTestSuite_test_b_after_vector() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 31, "test_b_after_vector" ) {}
 void runTest() { suite_MyTestSuite.test_b_after_vector(); }
} testDescription_MyTestSuite_test_b_after_vector;

static class TestDescription_MyTestSuite_test_a_is_first : public CxxTest::RealTestDescription {
public:
 TestDescription_MyTestSuite_test_a_is_first() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 40, "test_a_is_first" ) {}
 void runTest() { suite_MyTestSuite.test_a_is_first(); }
} testDescription_MyTestSuite_test_a_is_first;

#include <cxxtest/Root.cpp>
