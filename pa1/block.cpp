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

void Block::build(PNG &im, int x, int width) {
  
  unsigned int x_bound = x + width();
  unsigned int y_bound = height();
}
