/*
  dd.c 
  by Daniel Morales Miguel
  https://github.com/danalex93/dd/
  GNU General Public License v3.0
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main( int argc, const char* argv[] ){
  if (argc < 9){
    printf("usage dd -i input_file -o output_file -bs block_size -co block_count\n");
    
    return 1;
  } else {
    char input[256];
    char output[256];
    int block_size;
    int block_count;
    FILE *fout;
    FILE *fin;

    strcpy(input, argv[2]);
    strcpy(output, argv[4]);
    block_size = atoi(argv[6]);
    block_count = atoi(argv[8]);

    fin = fopen(input, "rb");
    if (fin == NULL){
      printf("Input file '%s' not found!\n", input);
      return 1;
    }

    char buffer[block_size*block_count];

    if (block_count != fread(buffer, 1, block_size*block_count, fin)){
      printf("Error reading input file!\n");
      return 1;
    }

    if (block_count != fwrite(buffer, 1, block_size*block_count, fout)){
      printf("Error writing output file!\n");
      return 1;
    }

    fclose(fin);
    fclose(fout);
  }

  return 0;
}
