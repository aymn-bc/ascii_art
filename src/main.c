#define STB_IMAGE_IMPLEMENTATION
#include "../include/stb_image.h"
#include <stdio.h>
#include <math.h>
#include <string.h>

unsigned char *resize_img();
// char* avg_brightness(unsigned char* pixel);
void print_colored_char(char c, int r, int g, int b);


int main(int argc, char** argv){
  if(argc < 2){
    printf("Usage: %s <image_path>\n", argv[0]);
    return -1;
  }else{
    int width, height, channels;
    unsigned char *img = stbi_load(argv[argc-1], &width, &height, &channels, 3);
    if (!img) {
      printf("Failed to load image\n");
      return -1;
    }
    char *brightness = " .'`^\",:;Il!i><~+_-?][}{1)(|\\/tfjrxnuvczXYUJCLQ0OZmwqpdbkhao*#MW&8%B@$";
    int brightness_level = strlen(brightness);
    for (int y = 0; y < height; y+=2){
      for(int x = 0; x < width; x++){

        int pixel_index1 = (x + y * width) * channels;
        int pixel_index2 = (x + (y + 1) * width) * channels;

        // Color of pixel of the current row
        unsigned char red1 = img[pixel_index1];
        unsigned char green1 = img[pixel_index1 + 1];
        unsigned char blue1 = img[pixel_index1 + 2];

        // Color of pixel of the next row
        unsigned char red2 = img[pixel_index2];
        unsigned char green2 = img[pixel_index2 + 1];
        unsigned char blue2 = img[pixel_index2 + 2];

        // if (y < 3) {
        //   printf("Pixel (%d,%d):", x, y);
        //   printf("%d\n", img[y * width + x]);
        // }

        int brightness1 = (int)(0.299 * red1 + 0.587 * green1 + 0.114 * blue1);
        int brightness2 = (int)(0.299 * red2 + 0.587 * green2 + 0.114 * blue2);
  
        int avg_brightness = (brightness1 + brightness2) / 2;

        int brightness_index = (avg_brightness * brightness_level) / 256;
        if (brightness_index >= brightness_level) brightness_index = brightness_level - 1;
        print_colored_char(brightness[brightness_index], (red1+red2)/2, (green1+green2)/2, (blue1+blue2)/2);
        // printf("%c", brightness[brightness_index]);
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

void print_colored_char(char c, int r, int g, int b){
  printf("\033[38;2;%d;%d;%dm%c\033[0m", r, g, b, c);
}
