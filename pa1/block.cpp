#include "block.h"
#include <cmath>
#include <iostream>

int Block::height() const {
  if(data.size() != 0) {
      return data[0].size();
    } else
  return 0;
}

int Block::width() const {
  
  return data.size();

}

  /**
   * Renders the given block onto img with its upper
   * left corner at (x, 0). Assumes block fits on the 
   * image.
   */
void Block::render(PNG &im, int x) const {

  unsigned int x_bound = x + width();
  unsigned int y_bound = height();

  for (unsigned int i = x; i < x_bound; i++) {
    for(unsigned int j = 0; j < y_bound; j++) {
      *im.getPixel(i, j) = data[i - x][j];
     }
  }
}

/** 
   * Creates a block that is width X img.height pixels in size
   * by copying the pixels from (x, 0) to (x+width-1, img.height-1)
   * in img. Assumes img is large enough to supply these pixels.
   */
void Block::build(PNG &im, int x, int width) {
  
  /*
  unsigned int x_bound = x + width;
  unsigned int y_bound = height();

  data.resize(width);
  for (unsigned int row = 0; row < x_bound; row++) {
    data[row].resize(height());
    for (unsigned int col = x; col < y_bound; col++) {
      data[row][col-(unsigned)x] = *(im.getPixel(col, row));
    }
  }
  */
 for (int i = x; i < x + width; i++) {
    std::vector <HSLAPixel> v;
    for(int j = 0; j < height(); j++) {
      HSLAPixel * pix = im.getPixel(i,j);
      v.push_back(*pix);
    } 
    data.push_back(v);
 }
  
}
