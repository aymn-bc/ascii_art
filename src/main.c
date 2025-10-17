#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <stdio.h>
#include <math.h>

int main(int argc, char** argv){
  if(argc < 2){
    printf("Usage: %s <image_path>\n", argv[0]);
    return -1;
  }else{
    int width, height, channels;
    unsigned char *img = stbi_load(argv[argc-1], &width, &height, &channels, 1);
    if (!img) {
      printf("Failed to load image\n");
      return -1;
    }
    char *brightness = " .'`^\",:;Il!i><~+_-?][}{1)(|\\/tfjrxnuvczXYUJCLQ0OZmwqpdbkhao*#MW&8%B@$";
    int brightness_level = 69;
    for (int y = 0; y < height; y+=2){
      for(int x = 0; x < width; x++){
        // if (y < 3) {
        //   printf("Pixel (%d,%d):", x, y);
        //   printf("%d\n", img[y * width + x]);
        // }
        int gray1 = y * width + x;
        int gray2 = (y+1) * width + x;

        int avg_brightness = (img[gray1] + img[gray2]) / 2;
        int brightness_index = (avg_brightness * brightness_level) / 256;
        if (brightness_index >= brightness_level) brightness_index = brightness_level - 1;
        printf("%c", brightness[brightness_index]);
      }
      printf("\n");
    }
    // printf("Loaded image: %dx%d, %d channels\n", width, height, channels);
    stbi_image_free(img);

    return 0;
  }
}

unsigned char *resize_img(){
  //Todo: checkout how resize a photo in c && stb_image_resize libraby
}