#include"vec3.h"

template<typename T>
Vec3<T>& Vec3<T>::normalize(){
    T nor2 = length2();
    if (nor2 > 0) {
        T invNor = 1 / sqrt(nor2);
        x *= invNor, y *= invNor, z *= invNor;
    }
    return *this;
}

template<typename T>
/** Finds the square of the length of coordinate vector*/
T Vec3<T>::length2() const {
    return x * x + y * y + z * z;
}

template<typename T>
/**Finds the length of the coordinate vector*/
T Vec3<T>::length() const {
    return sqrt(length2());
}

template<typename T>
/**Facilatite multiplication of the 3 coordinates by one function*/
Vec3<T> Vec3<T>::operator * (const T& f) const { 
    return Vec3<T>(x * f, y * f, z * f); 
}
template<typename T>
/**Finds the cross product*/
Vec3<T> Vec3<T>::operator * (const Vec3<T>& v) const {
    return Vec3<T>(x * v.x, y * v.y, z * v.z); 
}
template<typename T>
/**Finds the dot product*/
T Vec3<T>::dot(const Vec3<T>& v) const {
    return x * v.x + y * v.y + z * v.z; 
}
template<typename T>
/**Finds the Subtraction*/
Vec3<T> Vec3<T>::operator - (const Vec3<T>& v) const { 
    return Vec3<T>(x - v.x, y - v.y, z - v.z); 
}
template<typename T>
/**Finds the Addition*/
Vec3<T> Vec3<T>::operator + (const Vec3<T>& v) const { 
    return Vec3<T>(x + v.x, y + v.y, z + v.z); 
}
template<typename T>
/**Find the sum and store it in self*/
Vec3<T>& Vec3<T>::operator += (const Vec3<T>& v) { 
    x += v.x, y += v.y, z += v.z; 
    return *this; 
}
template<typename T>
/**Find the product and store it in self*/
Vec3<T>& Vec3<T>::operator *= (const Vec3<T>& v) { 
    x *= v.x, y *= v.y, z *= v.z; 
    return *this; 
}
template<typename T>
/**Find the negative of self*/
Vec3<T> Vec3<T>::operator - () const { 
    return Vec3<T>(-x, -y, -z); 
}