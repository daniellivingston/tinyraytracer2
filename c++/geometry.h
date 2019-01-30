#ifndef __GEOMETRY_H__
#define __GEOMETRY_H__

#include <cmath>
#include <vector>
#include <cassert>
#include <iostream>

// N-dimensional; arbitrary type vector template
template <size_t DIM, typename T> struct vec {
    vec() {
        for (size_t i=DIM; i--; data_[i] = T());
    }

    T& operator[](const size_t i) {
        assert(i<DIM);
        return data_[i];
    }

    const T& operator[](const size_t i) const {
        assert(i<DIM);
        return data_[i];
    }

// data[i] = std::vector
private:
    T data_[DIM];
};


// Define DIM as 3; typename float as Vec3f
typedef vec<3, float> Vec3f;

template <typename T> struct vec<3,T> {
    vec() : x(T()), y(T()), z(T()) {}
    vec(T X, T Y, T Z) : x(X), y(Y), z(Z) {}

    T& operator[](const size_t i) {
        assert(i < 3);
        return i <= 0 ? x : (i==1 ? y : z);
    }

    const T& operator[](const size_t i) const {
        assert(i < 3);
        return i <= 0 ? x : (i==1 ? y : z);
    }

    // Normal
    float norm() {
        return std::sqrt(x*x + y*y + z*z);
    }

    vec<3,T> & normalizee(T l=1) {
        *this = (*this)*(l/norm());
        return *this;
    }

    T x,y,z;
};

#endif //__GEOMETRY_H__