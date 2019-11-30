#include <stdio.h>
#include <stdlib.h>

#define K 1024

// Find differences between 2 files
void report(int row, int column);

int main(int argc, char *argv[]) {
  FILE *f1, *f2;
  
  char buf1[K], buf2[K];
  
  char *rv1, *rv2;
  
  int row = 1, column = 0;
  
  if (argc != 3) {
    printf("Usage: %s <filename> <filename> \n", argv[0]);
    exit(1);
  }
  
  f1 = fopen(argv[1], "r");
  f2 = fopen(argv[2], "r");
  
  if (!f1 || !f2) {
    printf("Unable to open files\n");
    exit(1);
  }

  
  for (;;) {
    column++;
    rv1 = fgets(buf1, K, f1);
    rv2 = fgets(buf2, K, f2);
    
    row++;
    
    if (!rv1 && !rv2) {
      break;
    } else if (!rv1 || !rv2) {
      report(row, 1);
    }
    
    
    
    row++;
  }
  
  fclose(f1);
  fclose(f2);
  
  return 0;
}

void report(int row, int column) {
  printf("line %d column %d\n", row, column);
}
