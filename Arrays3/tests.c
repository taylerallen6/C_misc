#include "arrays3.h"



int main()
{
    Array_int* array1 = array_int_create(10);

    for (unsigned int i = 0; i < 30; i++)
    {
        array_int_append(&array1, i);
    }
    array_int_print(array1);

    // for (unsigned int i = 0; i < 10; i++)
    // {
    //     array_int_append(&array1, i);
    // }
    // array_int_print(array1);

    // for (unsigned int i = 0; i < 6; i++)
    // {
    //     array_int_append(&array1, i);
    // }
    // array_int_print(array1);

    // for (unsigned int i = 0; i < 6; i++)
    // {
    //     array_int_append(&array1, i);
    // }
    // array_int_print(array1);

    // for (unsigned int i = 0; i < 6; i++)
    // {
    //     array_int_append(&array1, i);
    // }
    // array_int_print(array1);

    // for (unsigned int i = 0; i < 6; i++)
    // {
    //     array_int_append(&array1, i);
    // }
    // array_int_print(array1);

    // array_int_remove_unordered(&array1, 3);
    // array_int_print(array1);
    // array_int_remove_unordered(&array1, 3);
    // array_int_print(array1);
    // array_int_remove_unordered(&array1, 3);
    // array_int_print(array1);
    // array_int_remove_unordered(&array1, 3);
    // array_int_print(array1);

    // for (unsigned int i = 0; i < 20; i++)
    // {
    //     array_int_remove_unordered(&array1, 3);
    // }
    // array_int_print(array1);


    array_int_remove_ordered(&array1, 4);
    array_int_print(array1);
    array_int_remove_ordered(&array1, 4);
    array_int_print(array1);
    array_int_remove_ordered(&array1, 4);
    array_int_print(array1);
    array_int_remove_ordered(&array1, 4);
    array_int_print(array1);
    array_int_remove_ordered(&array1, 4);
    array_int_print(array1);
    array_int_remove_ordered(&array1, 4);
    array_int_print(array1);

    for (unsigned int i = 0; i < 20; i++)
    {
        array_int_remove_ordered(&array1, 4);
    }
    array_int_print(array1);

    // array_int_set(array1, 6, 1241);
    // array_int_print(array1);
    // array_int_set(array1, 24, 1241);
    // array_int_print(array1);
    // array_int_set(array1, 1000, 1241);
    // array_int_print(array1);





    // Array_float* array1 = array_float_create(10);

    // for (unsigned int i = 0; i < 30; i++)
    // {
    //     array_float_append(&array1, (float)i);
    // }
    // array_float_print(array1);

    // for (unsigned int i = 0; i < 10; i++)
    // {
    //     array_float_append(&array1, i);
    // }
    // array_float_print(array1);

    // for (unsigned int i = 0; i < 6; i++)
    // {
    //     array_float_append(&array1, i);
    // }
    // array_float_print(array1);

    // for (unsigned int i = 0; i < 6; i++)
    // {
    //     array_float_append(&array1, i);
    // }
    // array_float_print(array1);

    // for (unsigned int i = 0; i < 6; i++)
    // {
    //     array_float_append(&array1, i);
    // }
    // array_float_print(array1);

    // for (unsigned int i = 0; i < 6; i++)
    // {
    //     array_float_append(&array1, i);
    // }
    // array_float_print(array1);

    // array_float_remove_unordered(&array1, 3);
    // array_float_print(array1);
    // array_float_remove_unordered(&array1, 3);
    // array_float_print(array1);
    // array_float_remove_unordered(&array1, 3);
    // array_float_print(array1);
    // array_float_remove_unordered(&array1, 3);
    // array_float_print(array1);

    // for (unsigned int i = 0; i < 20; i++)
    // {
    //     array_float_remove_unordered(&array1, 3);
    // }
    // array_float_print(array1);


    // array_float_remove_ordered(&array1, 4);
    // array_float_print(array1);
    // array_float_remove_ordered(&array1, 4);
    // array_float_print(array1);
    // array_float_remove_ordered(&array1, 4);
    // array_float_print(array1);
    // array_float_remove_ordered(&array1, 4);
    // array_float_print(array1);
    // array_float_remove_ordered(&array1, 4);
    // array_float_print(array1);
    // array_float_remove_ordered(&array1, 4);
    // array_float_print(array1);

    // for (unsigned int i = 0; i < 20; i++)
    // {
    //     array_float_remove_ordered(&array1, 4);
    // }
    // array_float_print(array1);

    // array_float_set(array1, 6, 1241);
    // array_float_print(array1);
    // array_float_set(array1, 24, 1241);
    // array_float_print(array1);
    // array_float_set(array1, 1000, 1241);
    // array_float_print(array1);
    

    array_int_free(array1);
    // array_float_free(array1);

    return 0;
}