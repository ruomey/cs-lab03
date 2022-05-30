#include <iostream>
#include <vector>
#include <math.h>
#include "svg.h"
#include "histogram.h"
using namespace std;


void svg_begin(double width, double height) {
    cout << "<?xml version='1.0' encoding='UTF-8'?>\n";
    cout << "<svg ";
    cout << "width='" << width << "' ";
    cout << "height='" << height << "' ";
    cout << "viewBox='0 0 " << width << " " << height << "' ";
    cout << "xmlns='http://www.w3.org/2000/svg'>\n";
}

void svg_end() {
    cout << "</svg>\n";
}
void svg_text(double left, double baseline, string text, double font_size) {
    cout << "<text x='" << left << "' y='"<< baseline << "' font-size='" << font_size <<"'>'"<< text <<"'</text>";
}
void svg_rect(double x, double y, double width, double height, string stroke, string fill){
    cout << "<rect x='"<< x <<"' y='"<< y <<"' width='"<< width <<"' height='"<< height <<"' stroke='"<< stroke <<"' fill='"<< fill <<"'></rect>\n";
}


void computer_name (char comp_name[],DWORD &MinorVer,DWORD &MajorVer, DWORD &build,DWORD max_len){
    GetComputerNameA(comp_name, &max_len);
    DWORD info = GetVersion();
    DWORD mask = 0x0000ffff;
    DWORD version = info&mask;
    DWORD platf = info >> 16;
    MajorVer = version & 0x00ff;
    MinorVer = version >> 8;
    if ((info&0x4000'0000)==0){
        build = platf;
    }

}
void show_histogram_svg(const vector<size_t> &bins, size_t height) {
    const auto IMAGE_WIDTH = 400;
    const auto IMAGE_HEIGHT = 300;
    const auto TEXT_LEFT = 20;
    const auto TEXT_WIDTH = 50;
    const auto BLOCK_WIDTH = 10;
    const auto HISTOGRAM_MAX_WIDTH = IMAGE_WIDTH - TEXT_LEFT - TEXT_WIDTH;
    DWORD MinorVer, MajorVer, build;
    DWORD max_len = MAX_COMPUTERNAME_LENGTH + 1;
    char comp_name[max_len];
    computer_name(comp_name,MinorVer,MajorVer,build,max_len);
    size_t max_bin = bins[0];
    for (size_t bin : bins){
        if (max_bin < bin) max_bin = bin;
    }
    svg_begin(IMAGE_WIDTH, IMAGE_HEIGHT);
    test_height(height,bins.size(),IMAGE_HEIGHT);
    double top = 0;
    double font_size = height/2;
    for (size_t bin : bins) {
        double bin_width = BLOCK_WIDTH * bin;
        size_t width_temp = bin;
        if (max_bin * BLOCK_WIDTH > HISTOGRAM_MAX_WIDTH){
            width_temp = HISTOGRAM_MAX_WIDTH * (static_cast<double> (bin) / (max_bin * BLOCK_WIDTH));
            bin_width = BLOCK_WIDTH * width_temp;
        }

        double font_size = height/2;
        svg_text(TEXT_LEFT, top + height/2, to_string(bin), font_size);
        svg_rect(TEXT_WIDTH + height, top, bin_width, height,"#474A51","#DC143C");
        top += height;

    }
    svg_text(TEXT_LEFT, top + height/2, "Windows v" + to_string(MajorVer) +"."+ to_string(MinorVer) + " " + "build("+ to_string(build) + ")", font_size/1.5);
    top += height/2;
    svg_text(TEXT_LEFT, top + height/2,"Computer name: ", font_size/1.5);
    svg_text(TEXT_LEFT+height*2.5, top + height/2,comp_name, font_size/1.5);
    svg_end();
}
void test_height(size_t &height,size_t bins_count, const size_t IMAGE_HEIGHT){
    if (height * bins_count > IMAGE_HEIGHT){
            height = (IMAGE_HEIGHT/bins_count);
    }
}
