#ifndef SVG_H_INCLUDED
#define SVG_H_INCLUDED
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
void svg_begin(double width, double height);
void svg_end();
void svg_text(double left, double baseline, string text,double font_size);
void svg_rect(double x, double y, double width, double height, string stroke = "black", string fill ="black");
void show_histogram_svg(const vector<size_t> bins, size_t height_bin);
void test_height(size_t &height_bin,size_t bins_count, const size_t IMAGE_HEIGHT);

#endif // SVG_H_INCLUDED
