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
        int length = a.getLength();
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
        TS_ASSERT_THROWS(a.get(-1), std::out_of_range)
    }

    void test_out_of_range ( void )
    {
        Vector a(5);
        TS_ASSERT_THROWS(a.get(5), std::out_of_range)
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

        for (int i = 0; i < a.getLength(); i++)
        {
            TS_ASSERT_EQUALS(a[i],b[i]);
        }
    }

    void test_copy_a_to_a ( void )
    {
        Vector a(3);
        a[0] = 1;
        a[1] = 2;
        a[2] = 3;
        
        a = a;

        TS_ASSERT_EQUALS(a[0], 1);
        TS_ASSERT_EQUALS(a[1], 2);
        TS_ASSERT_EQUALS(a[2], 3);
    }

    void test_copy_a_bigger ( void )
    {
        Vector a(100);
        Vector b(50);

        for (int i = 0; i < a.getLength(); i++)
        {
            a[i] = i+1;
        }

        b = a;

        for (int i = 0; i < a.getLength(); i++)
        {
            TS_ASSERT_EQUALS(a[i],b[i]);
        }
    }

    void test_copy_b_bigger ( void )
    {
        Vector a(50);
        Vector b(100);

        for (int i = 0; i < a.getLength(); i++)
        {
            a[i] = i+1;
        }

        b = a;

        for (int i = 0; i < a.getLength(); i++)
        {
            TS_ASSERT_EQUALS(a[i],b[i]);
        }
    }

    void test_copy_constructor (void)
    {
        Vector a(50);

        for (int i = 0; i < a.getLength(); i++)
        {
            a[i] = i+1;
        }

        Vector b = a;

        for (int i = 0; i < a.getLength(); i++)
        {
            TS_ASSERT_EQUALS(a[i],b[i]);
        }

        Vector c(a);

        for (int i = 0; i < a.getLength(); i++)
        {
            TS_ASSERT_EQUALS(a[i],c[i]);
        }
    }

    void test_assignment()
    {
        Vector a(10);
        a[1] = 2;
        Vector b = a;
        a[2] = 3;
        TS_ASSERT_EQUALS(b[1], 2);
        TS_ASSERT_EQUALS(b[2], 0);
        b[3] = 5;
        a = b;
        TS_ASSERT_EQUALS(a[3], 5);
        b[4] = 2;
        b = b;
        TS_ASSERT_EQUALS(b[4], 2);
    }
    void test_diff_size_assignment()
    {
        Vector a(20);
        Vector b(10);
        a[5] = 10;
        a[9] = 123;
        b = a;
        TS_ASSERT_EQUALS(b.getLength(), a.getLength());
        TS_ASSERT_EQUALS(b[5], 10);
        TS_ASSERT_EQUALS(b[9], 123);
        b[15] = 15;
        TS_ASSERT_EQUALS(b[15], 15);
        b[5] = 20;
        a = b;
        TS_ASSERT_EQUALS(a.getLength(), b.getLength());
        TS_ASSERT_EQUALS(a[5], 20);
        TS_ASSERT_EQUALS(a[15], 15);
    }
};
