#include <cxxtest/TestSuite.h>

#include "vector.h"

class MyTestSuite : public CxxTest::TestSuite 
{
public:

    void test_initialized_as_zero( void )
    {
        Vector a(1);
        int result = a[0];
        TS_ASSERT_EQUALS(result, 0);
    }

    void test_vector_with_length_zero( void )
    {
        Vector a(0);
        int length = a.size();
        TS_ASSERT_EQUALS(length, 0);   
    }

    void test_set ( void )
    {
        Vector a(1);
        TS_ASSERT_EQUALS(a[0], 0);
        a[0] = 5;
        TS_ASSERT_EQUALS(a[0], 5);
    }

    void test_negative_index ( void )
    {
        Vector a(5);
        TS_ASSERT_THROWS(a[-1], std::out_of_range)
    }

    void test_out_of_range ( void )
    {
        Vector a(5);
        TS_ASSERT_THROWS(a[5], std::out_of_range)
    }

    void test_copy_equal_lengths( void )
    {
        int length = 10000;
        Vector a(length);
        Vector b(length);

        for (int i = 0; i < length; i++)
        {
            a[i] = i+1;
        }

        b = a;

        for (int i = 0; i < a.size(); i++)
        {
            TS_ASSERT_EQUALS(a[i],b[i]);
        }
    }

    void test_copy_a_to_a ( void )
    {
        Vector a(3);
        Vector* ptr = &a;
        
        a = a;

        TS_ASSERT_EQUALS(ptr, &a);
    }

    void test_copy_a_bigger ( void )
    {
        Vector a(100);
        Vector b(50);

        for (int i = 0; i < a.size(); i++)
        {
            a[i] = i+1;
        }

        b = a;

        for (int i = 0; i < a.size(); i++)
        {
            TS_ASSERT_EQUALS(a[i],b[i]);
        }
    }

    void test_copy_b_bigger ( void )
    {
        Vector a(50);
        Vector b(100);

        for (int i = 0; i < a.size(); i++)
        {
            a[i] = i+1;
        }

        b = a;

        for (int i = 0; i < a.size(); i++)
        {
            TS_ASSERT_EQUALS(a[i],b[i]);
        }
    }

    void test_copy_constructor (void)
    {
        Vector a(50);

        for (int i = 0; i < a.size(); i++)
        {
            a[i] = i+1;
        }

        Vector b = a;

        for (int i = 0; i < a.size(); i++)
        {
            TS_ASSERT_EQUALS(a[i],b[i]);
        }

        Vector c(a);

        for (int i = 0; i < a.size(); i++)
        {
            TS_ASSERT_EQUALS(a[i],c[i]);
        }
    }

    void test_move_constructor (void)
    {
        Vector a(5);
        a[0] = 1;
        a[1] = 2;
        a[2] = 3;
        a[3] = 4;
        a[4] = 5;

        Vector b = std::move(a);

        TS_ASSERT_EQUALS(a.size(), 0);
        TS_ASSERT_EQUALS(b.size(), 5);
        TS_ASSERT_EQUALS(b[0], 1);
        TS_ASSERT_EQUALS(b[1], 2);
    }

    void test_move_assignment_operator (void)
    {
        Vector a(5); 
        a = {1,1,1,1,1};

        Vector b(5); 
        b = {2,2,2,2,2};

        a = std::move(b);

        TS_ASSERT_EQUALS(b.size(),0);
        TS_ASSERT_EQUALS(a.size(),5);

        for (int i = 0; i < a.size(); i++)
            TS_ASSERT_EQUALS(a[i],2);
    }
};
