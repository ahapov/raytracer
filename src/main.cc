#include "vec3.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

std::stringstream prepareImageData();
bool writeToFile(std::stringstream buffer, std::string filename);

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
  for (int j = ny - 1; j >= 0; j--) {
    for (int i = 0; i < nx; i++) {
      vec3 col(float(i) / float(nx), float(j) / float(ny), 0.2);
      int ir = int(255.99 * col[0]);
      int ig = int(255.99 * col[1]);
      int ib = int(255.99 * col[2]);
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
