#pragma once

#include <numbers>

//constexpr double PI = 3.14159265;

// constexpr float DEG2RAD(float angle) {
//     //return angle * (PI / 180.0);
//     return angle * (std::numbers::pi / 180.0);
// }

template <typename T>
constexpr T DEG2RAD(T degrees) noexcept {
    return degrees * (std::numbers::pi_v<T> / static_cast<T>(180));
}