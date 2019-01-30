#include <limits>
#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>
#include "geometry.h"

void render() {

    // Define the domain of the image to render
    const int width     = 1024;
    const int height    = 768;

    // Generate a 3D float vector
    std::vector<Vec3f> framebuffer(width*height);

    // Initialize framebuffer with vectors
    for (size_t i = 0; i < height; i++) {
        for (size_t j = 0; j < width; j++) {
            framebuffer[j+i*width] = Vec3f(j/float(height),i/float(width),0);
        }
    }

    std::ofstream ofs;
    ofs.open("./out.ppm");
    ofs << "P6\n" << width << " " << height << "\n255\n";
    for (size_t i = 0; i < height*width; i++) {
        for (size_t j = 0; j < 3; j++) {
            ofs << (char)(255 * std::max(0.f, std::min(1.f, framebuffer[i][j])));
        }
    }

    ofs.close();

}

int main() {
    render();
    return 0;
}