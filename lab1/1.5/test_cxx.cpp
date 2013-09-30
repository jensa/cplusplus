#include <cxxtest/TestSuite.h>
#include "kth_cprog_vektor.cpp"

class MyTestSuite : public CxxTest::TestSuite 
{
public:

    /**
    TEST AV KONSTRUKTORERNA
    */

    void test_default_constructors (void)
    {
        Vector<int> a;
        TS_ASSERT_EQUALS((int) a.size(),0);

        Vector<int> b(5);
        TS_ASSERT_EQUALS((int) b.size(),5);

        // Test setting default value to 1
        Vector<int> c(5,1);
        TS_ASSERT_EQUALS(c[0],1);
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

    void test_initializer_list_constructor (void) {
        Vector<int> a = {0,1,2,3,4,5,6,7,8,9};
        TS_ASSERT_EQUALS(a.size(),10);
        for (int i = 0; i < a.size(); i++) {
            TS_ASSERT_EQUALS(a[i],i);
        }
    }

    /**
    TEST AV TILLDELNINGSOPERATORN (KOPIERING)
    */

    void test_copy_a_to_a ( void )
    {
        //Testar att den inte kopierar innehållet till en ny,
        //exakt likadan array
        Vector<int> a(3);
        int** ptr = &a.array;
        
        a = a;

        TS_ASSERT_EQUALS(ptr, &a.array);
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

    /**
    TEST AV ÖVRIGA OPERATORER
    */

    void test_index_operator (void)
    {
        Vector<int> a = {0,1,2,3,4,5};
        TS_ASSERT_EQUALS(a[0],0);
        TS_ASSERT_EQUALS(a[5],5);
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

    /**
    TEST AV RANDVILLKOR
    */

    void test_initialize_zero_size (void)
    {
        Vector<double> a;
        TS_ASSERT_EQUALS (a.size(), 0);

        Vector<double> b(0);
        TS_ASSERT_EQUALS (b.size(), 0);
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

    /**
    TEST AV OLIKA TYPER
    */

    void test_template_types (void) {
        Vector<int> int_vector = {0,1,2,3,4,5};
        TS_ASSERT_EQUALS(int_vector[5], 5);
        TS_ASSERT_EQUALS(int_vector.exists(5),true);

        Vector<std::string> string_vector = {"0","1","2","3","4","5"};
        TS_ASSERT_EQUALS(string_vector[5], "5");
        TS_ASSERT_EQUALS(string_vector.exists("5"),true);

        Vector<double> double_vector = {0.0,0.1,0.2,0.3,0.4,0.5};
        TS_ASSERT_EQUALS(double_vector[5], 0.5);
        TS_ASSERT_EQUALS(double_vector.exists(0.5),true);
    }

    /**
    TEST AV DEN NYA FUNKTIONALITETEN FÖR 1.5
    */

    void test_push_back (void)
    {
        Vector<int> a(5);
        TS_ASSERT_EQUALS(a.size(),5);

        a.push_back(1);
        TS_ASSERT_EQUALS(a.size(),6);
        TS_ASSERT_EQUALS(a[5],1);
    }

    void test_insert (void)
    {
        Vector<int> a(5);
        TS_ASSERT_EQUALS(a.size(),5);

        a.insert(3,1);
        TS_ASSERT_EQUALS(a[3],1);
        TS_ASSERT_EQUALS(a.size(),6);

        TS_ASSERT_THROWS(a.insert(a[10],1), std::out_of_range);
        TS_ASSERT_THROWS(a.insert(a[-1], 1), std::out_of_range);
    }

    void test_erase (void)
    {
        Vector<int> a;
        TS_ASSERT_THROWS(a.erase(0), std::out_of_range);
        TS_ASSERT_THROWS(a.erase(-1), std::out_of_range);

        Vector<int> b(5);
        TS_ASSERT_EQUALS(b.size(),5);

        b.erase(3);
        TS_ASSERT_EQUALS(b.size(),4);
    }

    void test_clear (void)
    {
        Vector<int> a(5);
        TS_ASSERT_EQUALS(a.size(),5);

        a.clear();
        TS_ASSERT_EQUALS(a.size(),0);
    }

    void test_size (void)
    {
        Vector<int> a;
        TS_ASSERT_EQUALS(a.size(),0);

        Vector<int> b(0);
        TS_ASSERT_EQUALS(b.size(),0);

        Vector<int> c(5);
        TS_ASSERT_EQUALS(c.size(),5);

        Vector<int> d = {0,1,2,3,4};
        TS_ASSERT_EQUALS(d.size(),5);
    }

    void test_sort (void)
    {
        // Testar att ascending blir {0,1,2,3,4,5,6,7,8,9}
        Vector<int> a = {0,9,1,8,2,7,3,6,4,5};
        a.sort(true);

        for (int i = 0; i < a.size(); i++) {
            TS_ASSERT_EQUALS(a[i],i);
        }

        // Testar att descending blir {9,8,7,6,5,4,3,2,1,0}
        Vector<int> b = {0,9,1,8,2,7,3,6,4,5};
        b.sort(false);

        for (int i = a.size()-1; i >= 0; i--) {
            TS_ASSERT_EQUALS(a[i],i);
        }
    }

    void test_unique_sort (void)
    {
        // Testar att den tar bort dubletter och sorterar (ascending)
        Vector<int> a = {0,9,9,1,8,8,2,2,7,3,6,6,4,5};
        a.unique_sort(true);

        for (int i = 0; i < a.size(); i++) {
            TS_ASSERT_EQUALS(a[i],i);
        }
    }
 
    void test_exists (void) 
    {
        Vector<int> a(5);
        a[3] = 1;
        // a = {0,0,0,1,0}
        TS_ASSERT_EQUALS (a.exists(1), true);
        TS_ASSERT_EQUALS (a.exists(2), false);
    }
};
