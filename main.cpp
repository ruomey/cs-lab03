#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main(){
    //Ввод данных
    size_t number_count;
    cerr << "Enter number count:";
    cin >> number_count;

    vector<double> numbers(number_count);
    cerr << "Enter numbers:";
    for(size_t i = 0; i < number_count; i++){
        cin >> numbers[i];
    }

    size_t bin_count;
    cerr << "Enter bin count:";
    cin >> bin_count;
    //Расчет гистограммы

    double min = numbers[0];
    double max = numbers[0];

    for (double number : numbers){
        if (min > number){
            min = number;
        }
        if (max < number){
            max = number;
        }
    }


    vector<size_t> bins(bin_count, 0);
    double bin_size = (max - min)/bin_count;
    for (size_t i = 0; i < number_count; i++){
        bool found = false;
        for(size_t j = 0; j < (bin_count - 1) && !found; j++){
            auto lo = min +  j * bin_size;
            auto hi = min + (j + 1) * bin_size;
            if ((lo <= numbers[i]) && (numbers[i] < hi)) {
                bins[j]++;
                found = true;
            }
        }
        if (!found){
            bins[bin_count - 1]++;
        }
    }


    //Вывод гистограммы
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
    return 0;
}
