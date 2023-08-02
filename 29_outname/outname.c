#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "outname.h"

char * computeOutputFileName(const char * inputName) {                    
  char* out = malloc(sizeof(*out) * (strlen(inputName) + 7 + 1));
  strcpy(out, inputName);
  strcat(out, ".counts");
  return out;
}
