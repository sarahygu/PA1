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

  for (unsigned int i = x; i < (unsigned)(x + width()); i++) {
    for(unsigned int j = 0; j < (unsigned)im.height(); j++) {
      *im.getPixel(i, j) = data[i-x][j];
     }
  }
}

/** 
   * Creates a block that is width X img.height pixels in size
   * by copying the pixels from (x, 0) to (x+width-1, img.height-1)
   * in img. Assumes img is large enough to supply these pixels.
   */
void Block::build(PNG &im, int x, int width) {
  
 for (unsigned int i = x; i < (unsigned)(x + width); i++) {
    std::vector <HSLAPixel> v;
    for(unsigned int j = 0; j < im.height(); j++) {
      HSLAPixel * pix = im.getPixel(i,j);
      v.push_back(*pix);
    } 
    data.push_back(v);
 }
  
}
