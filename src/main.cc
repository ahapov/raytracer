#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

std::stringstream prepareImageData();
bool writeToFile(std::stringstream buffer, std::string filename);

int main()
{
    std::string filename = "FILE1.ppm";
    std::stringstream buffer = prepareImageData();
    if (writeToFile(std::move(buffer), filename)) {
        std::cout << "File is written succesfully" << std::endl;
    }
}

std::stringstream prepareImageData()
{
    std::stringstream buffer;
    int nx = 400;
    int ny = 500;
    buffer << "P3\n" << nx << " " << ny << "\n255\n";
    for (int j = ny-1; j >= 0; j--)
    {
        for (int i = 0; i < nx; i++)
        {
            float r = float(i) / float(nx);
            float g = float(j) / float(ny);
            float b = 0.2;
            int ir = int(255.99*r);
            int ig = int(255.99*g);
            int ib = int(255.99*b);
            buffer << ir << " " << ig << " " << ib << "\n";
        }
    }
    return buffer;
}

bool writeToFile(std::stringstream buffer, std::string filename)
{
    std::ofstream file(filename);
    if (file.is_open())
    {
        for (std::string line; std::getline(buffer, line); )
        {
            file << line << std::endl;
        }
        return true;
    }
    return false;
}

