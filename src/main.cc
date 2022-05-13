#include "ray.h"
#include "sphere.h"
#include "vec3.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

vec3 color(const ray &r) {
  if (hit_sphere(vec3(0, 0, -1), 0.5, r))
    return vec3(1, 0, 0);
  vec3 unit_direction = unit_vector(r.direction());
  float t = 0.5 * (unit_direction.y() + 1.0);
  return (1.0 - t) * vec3(1.0, 1.0, 1.0) + t * vec3(0.5, 0.7, 1.0);
}

std::stringstream prepareImageData();
bool writeToFile(std::stringstream buffer, std::string filename);

float divide(int a, int b);

int main() {
  std::string filename = "FILE1.ppm";
  std::stringstream buffer = prepareImageData();
  if (writeToFile(std::move(buffer), filename)) {
    std::cout << "File is written succesfully" << std::endl;
  }
}

std::stringstream prepareImageData() {
  std::stringstream buffer;
  int nx = 500;
  int ny = 500;
  buffer << "P3\n" << nx << " " << ny << "\n255\n";
  vec3 lower_left_corner(-2.0, -1.0, -1.0);
  vec3 horizontal(4.0, .0, 0.0);
  vec3 vertical(0.0, 2.0, 0.0);
  vec3 origin(0.0, 0.0, 0.0);
  for (int j = ny - 1; j >= 0; j--) {
    for (int i = 0; i < nx; i++) {
      auto u{divide(i, nx)};
      auto v{divide(j, ny)};
      ray r(origin, lower_left_corner + u * horizontal + v * vertical);
      vec3 col{color(r)};
      auto ir{static_cast<int>(255.99 * col[0])};
      auto ig{static_cast<int>(255.99 * col[1])};
      auto ib{static_cast<int>(255.99 * col[2])};
      buffer << ir << " " << ig << " " << ib << "\n";
    }
  }
  return buffer;
}

bool writeToFile(std::stringstream buffer, std::string filename) {
  std::ofstream file(filename);
  if (file.is_open()) {
    for (std::string line; std::getline(buffer, line);) {
      file << line << std::endl;
    }
    return true;
  }
  return false;
}

float divide(int a, int b) {
  return static_cast<float>(a) / static_cast<float>(b);
}
