#include <limits>
#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>
#include "geometry.h"

/*
struct Sphere {
    Vec3f center;
    float radius;

    Sphere(const Vec3f &c, const float &r) : center(c), radius(r) {}

    // Method to determine if ray intersects sphere
    bool ray_intersect(const Vec3f &orig, const Vec3f &dir, float &t0) const {
        Vec3f L = center - orig;
        float tca = L*dir;
        float d2 = L*L - tca*tca;

        if (d2 > radius*radius) return false;

        float thc = sqrtf(radius*radius - d2);
        t0 = tca - thc;
        float t1 = tca + thc;

        if (t0 < 0) t0 = t1;
        if (t0 < 0) return false;
        return true;
    }
};
*/

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