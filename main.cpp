#include <iostream>
#include <vector>
#include <math.h>
#include "histogram.h"
#include "svg.h"
using namespace std;

vector<double> input_numbers(size_t count) {
    vector<double> result(count);
    for (size_t i = 0; i < count; i++) {
        cin >> result[i];
    }
    return result;
}
int main(){
    //¬вод данных
    size_t number_count;
    cerr << "Enter number count:";
    cin >> number_count;
    cerr << "Enter numbers:";
    const auto numbers = input_numbers(number_count);
    size_t bin_count;
    cerr << "Enter bin count:";
    cin >> bin_count;
    size_t height_historgam;
    cerr << "Enter height historgram:";
    cin >> height_historgam;
    const auto bins = make_histogram(numbers, bin_count);
    show_histogram_svg(bins, height_historgam);
    return 0;
}
