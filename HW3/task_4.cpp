// TASK IS NOT DONE

#include <iostream>

using namespace std;

template<typename T>
class Vector
{
private:
    T * array;
    T * new_array;
    int size;
    int max_size=0;
    int cnt;
    int count_for_minute;

    T* Copy_back()
    {
        count_for_minute = 0;
        new_array = new T[max_size];
        for (T t:array)
        {
            new_array[count_for_minute] = t;
            count_for_minute++;
        }
        return new_array;
    }
public:
    Vector()
    {
        size = 0;
        cnt = 0;
        max_size = 1;
        array = new T[max_size];
    }
    // ~task_4()
    // {
    //     //Do pop while true
    // }

    void PushBack(T elem)
    {   
        cnt++;
        if (cnt > max_size)
            max_size *= 2;

        array[]
    }
};

int main()
{
    return 0;
}