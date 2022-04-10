#include <iostream>
#include <vector>
#include <math.h>
#include "histogram.h"
#include <cassert>
using namespace std;


void find_minmax(vector<double> numbers, double& min, double& max) {
    min = numbers[0];
    max = numbers[0];
    if(numbers.size() == 0)
    {
        return;
    }
    for (double number : numbers){
        if (min > number) min = number;
        if (max < number) max = number;
    }
}



