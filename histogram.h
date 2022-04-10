
#ifndef HISTOGRAM_H_INCLUDED
#define HISTOGRAM_H_INCLUDED
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

void find_minmax(vector<double> numbers, double& min, double& max);
vector<size_t> make_histogram(const vector<double> numbers, size_t bin_count);
void show_histogram_text(vector<size_t>bins);
void svg_begin(double width, double height);
void svg_end();
void svg_text(double left, double baseline, string text);
void svg_rect(double x, double y, double width, double height, string stroke = "black", string fill ="black");
void show_histogram_svg(const vector<size_t>& bins, size_t height_bin);
#endif // HISTOGRAM_H_INCLUDED
