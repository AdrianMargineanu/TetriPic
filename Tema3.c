#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bmp_header.h"

#define SCALE 10
//Functia aloca un poiter de pointeri
infopixel** MYMALLOC(int* height, int* width) {
  infopixel** image;
  int i;

  image = (infopixel**)malloc((*height + 1) * sizeof(infopixel*));
  for (i = 0; i < *height; i++) {
    image[i] = (infopixel*)malloc((*width + 1) * sizeof(infopixel));
  }
  return image;
}
//Functia creaza un patrat de o anumita culoare
void SQUARE(char color, infopixel** image, int height, int width) {
  int i, j;
  if (color == 'b') {
    for (i = 0; i < height; i++) {
      for (j = 0; j < width; j++) {
        image[i][j].Blue = 255;
        image[i][j].Green = 0;
        image[i][j].Red = 0;
      }
    }
  }
  if (color == 'y') {
    for (i = 0; i < height; i++) {
      for (j = 0; j < width; j++) {
        image[i][j].Blue = 0;
        image[i][j].Green = 255;
        image[i][j].Red = 255;
      }
    }
  }
  if (color == 'r') {
    for (i = 0; i < height; i++) {
      for (j = 0; j < width; j++) {
        image[i][j].Blue = 0;
        image[i][j].Green = 0;
        image[i][j].Red = 255;
      }
    }
  }
  if (color == 'g') {
    for (i = 0; i < height; i++) {
      for (j = 0; j < width; j++) {
        image[i][j].Blue = 0;
        image[i][j].Green = 255;
        image[i][j].Red = 0;
      }
    }
  }
  if (color == 'o') {
    for (i = 0; i < height; i++) {
      for (j = 0; j < width; j++) {
        image[i][j].Blue = 0;
        image[i][j].Green = 140;
        image[i][j].Red = 255;
      }
    }
  }
  if (color == 'p') {
    for (i = 0; i < height; i++) {
      for (j = 0; j < width; j++) {
        image[i][j].Blue = 255;
        image[i][j].Green = 0;
        image[i][j].Red = 255;
      }
    }
  }
  if (color == 'm') {
    for (i = 0; i < height; i++) {
      for (j = 0; j < width; j++) {
        image[i][j].Blue = 255;
        image[i][j].Green = 0;
        image[i][j].Red = 130;
      }
    }
  }
}
//Functia creaza bordurile albe ale pieselor
void BORDER(infopixel** image, int height, int width) {
  int i, j;

  for (i = 0; i <= height + 1; i++) {
    image[i][0].Blue = 255;
    image[i][0].Green = 255;
    image[i][0].Red = 255;

    image[i][width + 1].Blue = 255;
    image[i][width + 1].Green = 255;
    image[i][width + 1].Red = 255;
  }

  for (j = 0; j <= width + 1; j++) {
    image[0][j].Blue = 255;
    image[0][j].Green = 255;
    image[0][j].Red = 255;

    image[height + 1][j].Blue = 255;
    image[height + 1][j].Green = 255;
    image[height + 1][j].Red = 255;
  }
}
//Toate functile PIESA_X_Y creaza piesa sub o numita rotatie
void PIESA_I(infopixel** image, int height, int width) {
  SQUARE('b', image, height, width);
}

void PIESA_I_90(infopixel** image, int height, int width) {
  SQUARE('b', image, height, width);
}

void PIESA_O(infopixel** image, int height, int width) {
  SQUARE('y', image, height, width);
}

void PIESA_S(infopixel** image, int height, int width) {
  SQUARE('r', image, height, width);
  image[0][0].Blue = 255;
  image[0][0].Green = 255;
  image[0][0].Red = 255;

  image[1][2].Blue = 255;
  image[1][2].Green = 255;
  image[1][2].Red = 255;
}
void PIESA_S_90(infopixel** image, int height, int width) {
  SQUARE('r', image, height, width);
  image[0][1].Blue = 255;
  image[0][1].Green = 255;
  image[0][1].Red = 255;

  image[2][0].Blue = 255;
  image[2][0].Green = 255;
  image[2][0].Red = 255;
}

void PIESA_Z(infopixel** image, int height, int width) {
  SQUARE('g', image, height, width);
  image[0][2].Blue = 255;
  image[0][2].Green = 255;
  image[0][2].Red = 255;

  image[1][0].Blue = 255;
  image[1][0].Green = 255;
  image[1][0].Red = 255;
}

void PIESA_Z_90(infopixel** image, int height, int width) {
  SQUARE('g', image, height, width);
  image[0][0].Blue = 255;
  image[0][0].Green = 255;
  image[0][0].Red = 255;

  image[2][1].Blue = 255;
  image[2][1].Green = 255;
  image[2][1].Red = 255;
}

void PIESA_L(infopixel** image, int height, int width) {
  SQUARE('o', image, height, width);
  image[0][1].Blue = 255;
  image[0][1].Green = 255;
  image[0][1].Red = 255;

  image[1][1].Blue = 255;
  image[1][1].Green = 255;
  image[1][1].Red = 255;
}

void PIESA_L_90(infopixel** image, int height, int width) {
  SQUARE('o', image, height, width);
  image[1][1].Blue = 255;
  image[1][1].Green = 255;
  image[1][1].Red = 255;

  image[1][2].Blue = 255;
  image[1][2].Green = 255;
  image[1][2].Red = 255;
}

void PIESA_L_180(infopixel** image, int height, int width) {
  SQUARE('o', image, height, width);
  image[1][0].Blue = 255;
  image[1][0].Green = 255;
  image[1][0].Red = 255;

  image[2][0].Blue = 255;
  image[2][0].Green = 255;
  image[2][0].Red = 255;
}

void PIESA_L_270(infopixel** image, int height, int width) {
  SQUARE('o', image, height, width);
  image[0][0].Blue = 255;
  image[0][0].Green = 255;
  image[0][0].Red = 255;

  image[0][1].Blue = 255;
  image[0][1].Green = 255;
  image[0][1].Red = 255;
}

void PIESA_J(infopixel** image, int height, int width) {
  SQUARE('p', image, height, width);
  image[0][0].Blue = 255;
  image[0][0].Green = 255;
  image[0][0].Red = 255;

  image[1][0].Blue = 255;
  image[1][0].Green = 255;
  image[1][0].Red = 255;
}

void PIESA_J_90(infopixel** image, int height, int width) {
  SQUARE('p', image, height, width);
  image[0][1].Blue = 255;
  image[0][1].Green = 255;
  image[0][1].Red = 255;

  image[0][2].Blue = 255;
  image[0][2].Green = 255;
  image[0][2].Red = 255;
}

void PIESA_J_180(infopixel** image, int height, int width) {
  SQUARE('p', image, height, width);
  image[1][1].Blue = 255;
  image[1][1].Green = 255;
  image[1][1].Red = 255;

  image[2][1].Blue = 255;
  image[2][1].Green = 255;
  image[2][1].Red = 255;
}

void PIESA_J_270(infopixel** image, int height, int width) {
  SQUARE('p', image, height, width);
  image[1][0].Blue = 255;
  image[1][0].Green = 255;
  image[1][0].Red = 255;

  image[1][1].Blue = 255;
  image[1][1].Green = 255;
  image[1][1].Red = 255;
}

void PIESA_T(infopixel** image, int height, int width) {
  SQUARE('m', image, height, width);
  image[1][0].Blue = 255;
  image[1][0].Green = 255;
  image[1][0].Red = 255;

  image[1][2].Blue = 255;
  image[1][2].Green = 255;
  image[1][2].Red = 255;
}

void PIESA_T_90(infopixel** image, int height, int width) {
  SQUARE('m', image, height, width);
  image[0][0].Blue = 255;
  image[0][0].Green = 255;
  image[0][0].Red = 255;

  image[2][0].Blue = 255;
  image[2][0].Green = 255;
  image[2][0].Red = 255;
}

void PIESA_T_180(infopixel** image, int height, int width) {
  SQUARE('m', image, height, width);
  image[0][0].Blue = 255;
  image[0][0].Green = 255;
  image[0][0].Red = 255;

  image[0][2].Blue = 255;
  image[0][2].Green = 255;
  image[0][2].Red = 255;
}

void PIESA_T_270(infopixel** image, int height, int width) {
  SQUARE('m', image, height, width);
  image[0][1].Blue = 255;
  image[0][1].Green = 255;
  image[0][1].Red = 255;

  image[2][1].Blue = 255;
  image[2][1].Green = 255;
  image[2][1].Red = 255;
}
//Functia scrie imaginea in fisier
void WRITE_PIECE(FILE* fout, infopixel** image, int height, int width) {
  int i, j, k, c, padding_nr = (width * SCALE) % 4;
  char padding = 0;
  for (i = height - 1; i >= 0; i--) {
    for (k = 0; k < SCALE; k++) {
      for (j = 0; j < width; j++) {
        for (c = 0; c < SCALE; c++) {
          fwrite(&image[i][j], sizeof(infopixel), 1, fout);
        }
      }
      padding_nr = (width * SCALE) % 4;
      while (padding_nr > 0) {
        fwrite(&padding, sizeof(char), 1, fout);
        padding_nr--;
      }
    }
  }
}
//Functia scrie infoheader si fileheaderul in fisier
void WRITE_HEADER(int width, int height, FILE* fout) {
  bmp_fileheader fileheader;
  bmp_infoheader infoheader;

  infoheader.width = width * 10;
  infoheader.height = height * 10;
  fileheader.fileMarker1 = 'B';
  fileheader.fileMarker2 = 'M';
  fileheader.unused1 = 0;
  fileheader.unused2 = 0;
  fileheader.imageDataOffset = 54;
  infoheader.biSize = 40;
  infoheader.planes = 1;
  infoheader.bitPix = 24;
  infoheader.biCompression = 0;
  infoheader.biYPelsPerMeter = 0;
  infoheader.biXPelsPerMeter = 0;
  infoheader.biClrUsed = 0;
  infoheader.biClrImportant = 0;

  infoheader.biSizeImage = height * SCALE * width * SCALE * sizeof(infopixel) +
                           height * SCALE * ((width * SCALE) % 4);
  fileheader.bfSize = infoheader.biSizeImage + fileheader.imageDataOffset;

  fwrite(&fileheader, sizeof(bmp_fileheader), 1, fout);
  fwrite(&infoheader, sizeof(bmp_infoheader), 1, fout);
}
//Functia selecteaza piesa si o creaza
infopixel** PIECE_GENERATOR(int type, int rotation, int* height, int* width) {
  infopixel** piece;
  if (type == 'O') {
    *height = 2;
    *width = 2;
    piece = MYMALLOC(height, width);
    PIESA_O(piece, 2, 2);
  }
  if (type == 'I') {
    if (rotation == 0 || rotation == 180) {
      *height = 4;
      *width = 1;
      piece = MYMALLOC(height, width);
      PIESA_I(piece, 4, 1);

    } else {
      *height = 1;
      *width = 4;
      piece = MYMALLOC(height, width);
      PIESA_I_90(piece, 1, 4);
    }
  }
  if (type == 'S') {
    if (rotation == 0 || rotation == 180) {
      *height = 2;
      *width = 3;
      piece = MYMALLOC(height, width);
      PIESA_S(piece, 2, 3);
    } else {
      *height = 3;
      *width = 2;
      piece = MYMALLOC(height, width);
      PIESA_S_90(piece, 3, 2);
    }
  }
  if (type == 'Z') {
    if (rotation == 0 || rotation == 180) {
      *height = 2;
      *width = 3;
      piece = MYMALLOC(height, width);
      PIESA_Z(piece, 2, 3);
    } else {
      *height = 3;
      *width = 2;
      piece = MYMALLOC(height, width);
      PIESA_Z_90(piece, 3, 2);
    }
  }
  if (type == 'L') {
    if (rotation == 0) {
      *height = 3;
      *width = 2;
      piece = MYMALLOC(height, width);
      PIESA_L(piece, 3, 2);
    } else {
      if (rotation == 90) {
        *height = 2;
        *width = 3;
        piece = MYMALLOC(height, width);
        PIESA_L_90(piece, 2, 3);
      } else {
        if (rotation == 180) {
          *height = 3;
          *width = 2;
          piece = MYMALLOC(height, width);
          PIESA_L_180(piece, 3, 2);
        } else {
          *height = 2;
          *width = 3;
          piece = MYMALLOC(height, width);
          PIESA_L_270(piece, 2, 3);
        }
      }
    }
  }
  if (type == 'J') {
    if (rotation == 0) {
      *height = 3;
      *width = 2;
      piece = MYMALLOC(height, width);
      PIESA_J(piece, 3, 2);
    } else {
      if (rotation == 90) {
        *height = 2;
        *width = 3;
        piece = MYMALLOC(height, width);
        PIESA_J_90(piece, 2, 3);
      } else {
        if (rotation == 180) {
          *height = 3;
          *width = 2;
          piece = MYMALLOC(height, width);
          PIESA_J_180(piece, 3, 2);
        } else {
          *height = 2;
          *width = 3;
          piece = MYMALLOC(height, width);
          PIESA_J_270(piece, 2, 3);
        }
      }
    }
  }
  if (type == 'T') {
    if (rotation == 0) {
      *height = 2;
      *width = 3;
      piece = MYMALLOC(height, width);
      PIESA_T(piece, 2, 3);
    } else {
      if (rotation == 90) {
        *height = 3;
        *width = 2;
        piece = MYMALLOC(height, width);
        PIESA_T_90(piece, 3, 2);
      } else {
        if (rotation == 180) {
          *height = 2;
          *width = 3;
          piece = MYMALLOC(height, width);
          PIESA_T_180(piece, 2, 3);
        } else {
          *height = 3;
          *width = 2;
          piece = MYMALLOC(height, width);
          PIESA_T_270(piece, 3, 2);
        }
      }
    }
  }
  return piece;
}
//Functia creaza imaginea cu bordura
void CREATE_IMAGE_PIECE(FILE* fout, char type, int rotation, int height,
                        int width) {
  int i, j;
  infopixel **image, **piece;
  image = (infopixel**)malloc((height + 3) * sizeof(infopixel*));
  if(image==NULL){
    printf("ERROR! OUT OF MEMORRY\n");
  }
  for (i = 0; i < height + 2; i++) {
    image[i] = (infopixel*)malloc((width + 3) * sizeof(infopixel));
    if(image[i]==NULL){
    printf("ERROR! OUT OF MEMORRY\n");
  }
  }
  BORDER(image, height, width);
  piece = PIECE_GENERATOR(type, rotation, &height, &width);
  for (i = 1; i <= height; i++) {
    for (j = 1; j <= width; j++) {
      image[i][j] = piece[i - 1][j - 1];
    }
  }
  WRITE_HEADER(width + 2, height + 2, fout);
  WRITE_PIECE(fout, image, height + 2, width + 2);
   for (i = 0; i < height + 2; i++){
    free(image[i]);
  }
  free(image);
}

//Functia creaza piesele rotite in fisiere bmp, utilizata pentru testare.
void TASK_2() {
  FILE* fout;

  fout = fopen("piesa_I_90.bmp", "wb");
  CREATE_IMAGE_PIECE(fout, 'I', 90, 1, 4);
  fclose(fout);
  fout = fopen("piesa_I_180.bmp", "wb");
  CREATE_IMAGE_PIECE(fout, 'I', 0, 4, 1);
  fclose(fout);
  fout = fopen("piesa_I_270.bmp", "wb");
  CREATE_IMAGE_PIECE(fout, 'I', 90, 1, 4);
  fclose(fout);

  fout = fopen("piesa_O_90.bmp", "wb");
  CREATE_IMAGE_PIECE(fout, 'O', 0, 2, 2);
  fclose(fout);
  fout = fopen("piesa_O_180.bmp", "wb");
  CREATE_IMAGE_PIECE(fout, 'O', 0, 2, 2);
  fclose(fout);
  fout = fopen("piesa_O_270.bmp", "wb");
  CREATE_IMAGE_PIECE(fout, 'O', 0, 2, 2);
  fclose(fout);

  fout = fopen("piesa_S_90.bmp", "wb");
  CREATE_IMAGE_PIECE(fout, 'S', 90, 3, 2);
  fclose(fout);
  fout = fopen("piesa_S_180.bmp", "wb");
  CREATE_IMAGE_PIECE(fout, 'S', 0, 2, 3);
  fclose(fout);
  fout = fopen("piesa_S_270.bmp", "wb");
  CREATE_IMAGE_PIECE(fout, 'S', 90, 3, 2);
  fclose(fout);

  fout = fopen("piesa_Z_90.bmp", "wb");
  CREATE_IMAGE_PIECE(fout, 'Z', 90, 3, 2);
  fclose(fout);
  fout = fopen("piesa_Z_180.bmp", "wb");
  CREATE_IMAGE_PIECE(fout, 'Z', 0, 2, 3);
  fout = fopen("piesa_Z_270.bmp", "wb");
  CREATE_IMAGE_PIECE(fout, 'Z', 90, 3, 2);
  fclose(fout);

  fout = fopen("piesa_L_90.bmp", "wb");
  CREATE_IMAGE_PIECE(fout, 'L', 90, 2, 3);
  fclose(fout);
  fout = fopen("piesa_L_180.bmp", "wb");
  CREATE_IMAGE_PIECE(fout, 'L', 180, 3, 2);
  fclose(fout);
  fout = fopen("piesa_L_270.bmp", "wb");
  CREATE_IMAGE_PIECE(fout, 'L', 270, 2, 3);
  fclose(fout);

  fout = fopen("piesa_J_90.bmp", "wb");
  CREATE_IMAGE_PIECE(fout, 'J', 90, 2, 3);
  fclose(fout);
  fout = fopen("piesa_J_180.bmp", "wb");
  CREATE_IMAGE_PIECE(fout, 'J', 180, 3, 2);
  fclose(fout);
  fout = fopen("piesa_J_270.bmp", "wb");
  CREATE_IMAGE_PIECE(fout, 'J', 270, 2, 3);
  fclose(fout);

  fout = fopen("piesa_T_90.bmp", "wb");
  CREATE_IMAGE_PIECE(fout, 'T', 90, 3, 2);
  fclose(fout);
  fout = fopen("piesa_T_180.bmp", "wb");
  CREATE_IMAGE_PIECE(fout, 'T', 180, 2, 3);
  fclose(fout);
  fout = fopen("piesa_T_270.bmp", "wb");
  CREATE_IMAGE_PIECE(fout, 'T', 270, 3, 2);
  fclose(fout);
}
//Functia transforma casutele albe in negre
void WHITE_TO_BLACK(infopixel** image, int* height, int* width) {
  infopixel white;
  white.Blue = 255;
  white.Red = 255;
  white.Green = 255;

  int i, j;

  for (i = 0; i < *height; i++)
    for (j = 0; j < *width; j++) {
      if (memcmp(&image[i][j], &white, sizeof(infopixel)) == 0) {
        image[i][j].Blue = 0;
        image[i][j].Red = 0;
        image[i][j].Green = 0;
      }
    }
}
//Functia indeplieste caderea pieselor
void GAME(FILE* fin, infopixel** map, int moves, int map_h, int map_w) {
  int aux, i, j, k, count, rotation, position_h,verify, collom;
  char name;
  infopixel** piesa;
  int piesa_h = 0, piece_w = 0;
  infopixel black;

  black.Red = 0;
  black.Blue = 0;
  black.Green = 0;

  while (moves > 0) {
    fseek(fin, 1, SEEK_CUR);
    fscanf(fin, "%c%d%d", &name, &rotation, &collom);
    printf("%c %d\n", name, rotation);
    piesa = PIECE_GENERATOR(name, rotation, &piesa_h, &piece_w);
    WHITE_TO_BLACK(piesa, &piesa_h, &piece_w);
    for (i = 0; i < map_h; i++) {
      for (k = piesa_h - 1; k >= 0; k--) {
        for (j = collom; j < (collom + piece_w); j++) {
          if (memcmp(&map[i][j], &black, sizeof(infopixel)) != 0 &&
              memcmp(&piesa[k][j - collom], &black, sizeof(infopixel)) != 0) {
            position_h = i;
            i = map_h + 1;
            aux = k + 1;
            k = 0;
            break;
          }
        }
      }
    }
    if (i == map_h) {
      for (i = map_h - piesa_h, k = 0; i < map_h; i++, k++) {
        for (j = collom; j < (collom + piece_w); j++) {
          memcpy(&map[i][j], &piesa[k][j - collom], sizeof(infopixel));
        }
      }
    } else {
      for (i = position_h - aux, k = 0;
           (i < position_h - aux + piesa_h) && (k < piesa_h); i++, k++) {
        for (j = collom, count = 0; (j < collom + piece_w) && (count < piece_w);
             j++, count++) {
          if (memcmp(&map[i][j], &black, sizeof(infopixel)) == 0) {
            if (memcmp(&piesa[k][count], &black, sizeof(infopixel)) != 0) {
              memcpy(&map[i][j], &piesa[k][count], sizeof(infopixel));
            }
          }
        }
      }
    }
    for (j = 0; j < map_w; j++) {
      if (memcmp(&map[3][j], &black, sizeof(infopixel)) != 0) {
        moves = 0;
      }
    }
    for (i = 4; i < map_h; i++) {
      verify = 1;
      for (j = 0; j < map_w; j++) {
        if (memcmp(&map[i][j], &black, sizeof(infopixel)) == 0) {
          verify = 0;
        }
      }
      if (verify == 1) {
        for (j = 0; j < map_w; j++) {
          memcpy(&map[i][j], &black, sizeof(infopixel));
        }
        for (k = i; k > 0; k--) {
          for (j = 0; j < map_w; j++) {
            memcpy(&map[k][j], &map[k - 1][j], sizeof(infopixel));
          }
        }
      }
    }
    moves--;
  }
  for (i = 0; i < 4; i++) {
    for (j = 0; j < map_w; j++) {
      if (memcmp(&map[i][j], &black, sizeof(infopixel)) == 0) {
        map[i][j].Blue = 255;
        map[i][j].Green = 255;
        map[i][j].Red = 255;
      }
    }
  }
}
//Functia care incepe jocul de la 0
void TASK_3() {
  int i, j, map_h, map_w, moves;
  infopixel** map;
  FILE* fin,*fout;
  fin = fopen("Moves.in", "r");

  fscanf(fin, "%d%d%d", &moves, &map_h, &map_w);
  map_h = map_h + 4;
  map = (infopixel**)malloc((map_h) * sizeof(infopixel*));
  if(map==NULL){
    printf("ERROR! OUT OF MEMORRY\n");
  }
  for (i = 0; i < map_h; i++) {
    map[i] = (infopixel*)malloc((map_w) * sizeof(infopixel));
    if(map[i]==NULL){
    printf("ERROR! OUT OF MEMORRY\n");
  }
  }
  for (; i < map_h; i++) {
    for (j = 0; j < map_w; j++) {
      map[i][j].Blue = 0;
      map[i][j].Green = 0;
      map[i][j].Red = 0;
    }
  }
  GAME(fin, map, moves, map_h, map_w);
  fclose(fin);
  fout = fopen("Game.bmp", "wb");
  WRITE_HEADER(map_w, map_h, fout);
  WRITE_PIECE(fout, map, map_h, map_w);
  fclose(fout);
   for (i = 0; i < map_h ; i++){
    free(map[i]);
  }
  free(map);

}
//Functia incepe jocul de la o mapa deja existenta
void TASK_4() {
  FILE* fin,*fout;
  int i, j, map_h, map_w,moves;
  infopixel** map;
  bmp_fileheader fileheader;
  bmp_infoheader infoheader;

  fin = fopen("Map.bmp", "rw");
  fread(&fileheader, sizeof(bmp_fileheader), 1, fin);
  fread(&infoheader, sizeof(bmp_infoheader), 1, fin);
  map_w = infoheader.width / 10;
  map_h = infoheader.height / 10;
  
   map = (infopixel**)malloc((map_h) * sizeof(infopixel*));
  if(map==NULL){
    printf("ERROR! OUT OF MEMORRY\n");
  }
  for (i = 0; i < map_h; i++) {
    map[i] = (infopixel*)malloc((map_w) * sizeof(infopixel));
    if(map[i]==NULL){
    printf("ERROR! OUT OF MEMORRY\n");
  }
  }
  for (i = infoheader.height - 1; i > 0; i--) {
    for (j = 0; j < infoheader.width; j++) {
      fread(&map[i / 10][j / 10], sizeof(infopixel), 1, fin);
    }
    fseek(fin, ((infoheader.width) % 4), SEEK_CUR);
  }
  fclose(fin);

  WHITE_TO_BLACK(map, &map_h, &map_w);
  fin = fopen("Moves.in", "r");
  fscanf(fin, "%d", &moves);
  GAME(fin, map, moves, map_h, map_w);

  fclose(fin);
  fout = fopen("Game.bmp", "wb");
  WRITE_HEADER(map_w, map_h, fout);
  WRITE_PIECE(fout, map, map_h, map_w);
  fclose(fout);
  for (i = 0; i < map_h ; i++){
    free(map[i]);
  }
  free(map);
}

int main(int argc, char* argv[]) {

  if(argc==0){
    printf("NEED ARGUMENTS\n");
    return 0;
  }
  // if (argv[1][0] == '2') {
  //   TASK_2();
  // }
  if (argv[1][0] == '3') {
    TASK_3();
  }
  if (argv[1][0] == '4') {
    TASK_4();
  }
  return 0;
}
