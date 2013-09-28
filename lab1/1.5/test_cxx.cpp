#include <cxxtest/TestSuite.h>

#include "vector.h"

class MyTestSuite : public CxxTest::TestSuite 
{
public:

    void test_initialized_as_zero( void )
    {
        Vector<int> a(1);
        int result = a[0];
        TS_ASSERT_EQUALS(result, 0);
    }

    void test_vector_with_length_zero( void )
    {
        Vector<int> a(0);
        int length = a.size();
        TS_ASSERT_EQUALS(length, 0);   
    }

    void test_set ( void )
    {
        Vector<int> a(1);
        TS_ASSERT_EQUALS(a[0], 0);
        a[0] = 5;
        TS_ASSERT_EQUALS(a[0], 5);
    }

    void test_negative_index ( void )
    {
        Vector<int> a(5);
        TS_ASSERT_THROWS(a[-1], std::out_of_range)
    }

    void test_out_of_range ( void )
    {
        Vector<int> a(5);
        TS_ASSERT_THROWS(a[5], std::out_of_range)
    }

    void test_copy_equal_lengths( void )
    {
        int length = 10000;
        Vector<int> a(length);
        Vector<int> b(length);

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
        Vector<int> a(3);
        Vector<int>* ptr = &a;
        
        a = a;

        TS_ASSERT_EQUALS(ptr, &a);
    }

    void test_copy_a_bigger ( void )
    {
        Vector<int> a(100);
        Vector<int> b(50);

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
        Vector<int> a(50);
        Vector<int> b(100);

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
        Vector<int> a(50);

        for (int i = 0; i < a.size(); i++)
        {
            a[i] = i+1;
        }

        Vector<int> b = a;

        for (int i = 0; i < a.size(); i++)
        {
            TS_ASSERT_EQUALS(a[i],b[i]);
        }

        Vector<int> c(a);

        for (int i = 0; i < a.size(); i++)
        {
            TS_ASSERT_EQUALS(a[i],c[i]);
        }
    }

    void test_move_constructor (void)
    {
        Vector<int> a(5);
        a[0] = 1;
        a[1] = 2;
        a[2] = 3;
        a[3] = 4;
        a[4] = 5;

        Vector<int> b = std::move(a);

        TS_ASSERT_EQUALS(a.size(), 0);
        TS_ASSERT_EQUALS(b.size(), 5);
        TS_ASSERT_EQUALS(b[0], 1);
        TS_ASSERT_EQUALS(b[1], 2);
    }

    void test_move_assignment_operator (void)
    {
        Vector<int> a(5); 
        a = {1,1,1,1,1};

        Vector<int> b(5); 
        b = {2,2,2,2,2};

        a = std::move(b);

        TS_ASSERT_EQUALS(b.size(),0);
        TS_ASSERT_EQUALS(a.size(),5);

        for (int i = 0; i < a.size(); i++)
            TS_ASSERT_EQUALS(a[i],2);
    }

    void test_template_shit (void) 
    {
        Vector<int> a(5);

        a[3] = 1;

        TS_ASSERT_EQUALS (a.exists(1), true);
    }

    void test_template_zeros (void)
    {
        Vector<double> a;
        TS_ASSERT_EQUALS (a.size(), 0);

        Vector<double> b(0);
        TS_ASSERT_EQUALS (b.size(), 0);

        TS_ASSERT_THROWS(b.erase(0),std::out_of_range);
        b.insert(0,1);
        TS_ASSERT_EQUALS(b.size(),1);
    }
};
