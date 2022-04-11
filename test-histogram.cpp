#include "histogram.h"

#include <cassert>

void test_positive() {
    double min = 0;
    double max = 0;
    find_minmax({1, 2, 3}, min, max);
    assert(min == 1);
    assert(max == 3);
}

void test_negative(){
    double min = 0;
    double max = 0;
    find_minmax({-1, -2, -3}, min, max);
    assert(min == -3);
    assert(max == -1);

}
void equal(){
    double min = 0;
    double max = 0;
    find_minmax({3, 3, 3}, min, max);
    assert(min == 3);
    assert(max == min);

}
void one_num(){
    double min = 0;
    double max = 0;
    find_minmax({1}, min, max);
    assert(min == 1);
    assert(max == 1);

}
void test_void(){
    double min = 0;
    double max = 0;
    find_minmax({}, min, max);
    assert(min == 0);
    assert(max == 0);

}
void test_heigth_min(){
    size_t height = 5;
    test_height(height,5,700);
    assert(height == 5);
}
void test_heigth_max(){
    size_t height = 250;
    test_height(height,5,700);
    assert(height == (700/5));
}
void test_heigth_equal(){
    size_t height = 140;
    test_height(height,5,700);
    assert(height == 140);
}

int main() {
    test_positive();
    test_negative();
    equal();
    test_heigth_min();
    test_heigth_max();
    test_heigth_equal();
}

