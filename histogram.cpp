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
vector<size_t> make_histogram(Input data){
    double min,max;
    find_minmax(data.numbers, min, max);
    vector<size_t>bins(data.bin_count,0);
    double bin_size = (max - min)/data.bin_count;
    for (size_t i = 0; i < data.numbers.size(); i++){
        bool found = false;
        for(size_t j = 0; j < (data.bin_count - 1) && !found; j++){
            auto lo = min +  j * bin_size;
            auto hi = min + (j + 1) * bin_size;
            if ((lo <= data.numbers[i]) && (data.numbers[i] < hi)) {
                bins[j]++;
                found = true;
            }
        }
        if (!found){
            bins[data.bin_count - 1]++;
        }
    }
    return bins;
}
void show_histogram_text(vector<size_t>bins){
    const size_t SCREEN_WIDTH = 80;
    const size_t MAX_ASTERISK = SCREEN_WIDTH - 3 - 1;
    size_t max_bin = bins[0];
    for (size_t bin : bins){
        if (max_bin < bin){
            max_bin = bin;
        }
    }
    for (size_t bin: bins){
        size_t height = bin;
        if (max_bin > MAX_ASTERISK){
            height = MAX_ASTERISK * (static_cast<double> (bin) / max_bin);
        }
        if (bin < 100) cout << " ";
        if (bin < 10) cout << " ";
        cout << bin;
        cout << "|";
        for(size_t i = 0; i < height;i++){
            cout << "*";
        }
        cout << endl;
    }
}
