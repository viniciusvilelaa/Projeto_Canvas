#include <fstream>
#include <iostream>
#include <vector>
#include <string>

#include "canvas.h"
#include "../ext_lib/lodepng.h"

using namespace life;

/// Saves an image as a **ascii** PPM file.
bool save_ppm3(const char* file_name,
               const unsigned char* data,
               size_t w,
               size_t h,
               size_t d=4)
{
  std::ofstream ofs_file(file_name, std::ios::out);
  if (not ofs_file.is_open())
    return false;

    // TODO: Complete a geração do arquivo PPM!!


  ofs_file.close();

  return true;
}

// Example 1
// Encode from raw pixels to disk with a single function call
// The image argument has width * height RGBA pixels or width * height * 4 bytes
void encode_png(const char* filename, const unsigned char* image, unsigned width, unsigned height)
{
  // Encode the image
  unsigned error = lodepng::encode(filename, image, width, height);

  // if there's an error, display it
  if (error)
    std::cout << "encoder error " << error << ": " << lodepng_error_text(error) << std::endl;
}

/// Splits the input string based on `delimiter` into a list of substrings.
std::vector<std::string> split(const std::string & input_str, char delimiter='.'){
    // Store the tokens.
    std::vector<std::string> tokens;
    // read tokens from a string buffer.
    std::istringstream iss;
    iss.str(input_str);
    // This will hold a single token temporarily.
    std::string token;
    while (std::getline(iss >> std::ws, token, delimiter))
        tokens.emplace_back(token);
    return tokens;
}

// Saves image to filename given as argument. Warning, this overwrites the file
// without warning!
int main(int argc, char* argv[])
{
  // NOTE: this sample will overwrite the file or test.png without warning!
  const char* filename = argc > 1 ? argv[1] : "test.png";
  auto components = split(filename, '.');
  std::string file_png = components[0]+".png";
  std::string file_ppm = components[0]+".ppm";

  // generate some image
  unsigned width = 20, height = 15;
  short block_size = 50;

  // Criar uma imagem para desenho.
  Canvas image(width, height, block_size);

  for (auto x{ 0u }; x < width; x++)
    for (auto y{ 0u }; y < height; y++) {
      if (y % 2)
        if (!(x % 2))
          // another way to define a color.
          image.pixel(x, y, color_pallet["deep_sky_blue"]);
        // image.pixel( x,y , DEEP_SKY_BLUE );
        else
          image.pixel(x, y, RED);
      else if (!(x % 2))
        image.pixel(x, y, RED);
      else
        image.pixel(x, y, DEEP_SKY_BLUE);
    }
  /// X = Column, Y = Row
  image.pixel(5, 2, color_pallet["green"]);
  std::cout << ">>> Gravando imagem '" << filename << "', dimensions: " << width << " x " << height << " (bs = " << block_size << "), please wait...\n"; 

  encode_png(file_png.c_str(), image.pixels(), image.width(), image.height());
  save_ppm3 (file_ppm.c_str(), image.pixels(), image.width(), image.height());
  std::cout << "<<< done!\n";
}
