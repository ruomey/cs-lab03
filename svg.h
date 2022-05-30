#ifndef SVG_H_INCLUDED
#define SVG_H_INCLUDED
#include <iostream>
#include <vector>
#include <winsock2.h>
#include <windows.h>
#include <math.h>
#include "histogram.h"
using namespace std;
void svg_begin(double width, double height);
void svg_end();
void svg_text(double left, double baseline, string text);
void svg_rect(double x, double y, double width, double height, string stroke = "black", string fill ="black");
void show_histogram_svg(const vector<size_t> &bins,size_t height);
void test_height(size_t &height_bin,size_t bins_count, const size_t IMAGE_HEIGHT);
void computer_name (char computer_name[],DWORD &MinorVer,DWORD &MajorVer, DWORD &build,DWORD max_len);

#endif // SVG_H_INCLUDED
