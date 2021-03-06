#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define PTR_SIZE 100
#define PTR2_SIZE 10
#define PTR3_SIZE 10
#define OUT_OF_BOUNDS_EXCESS 1

// FIXME: The parameters are not being replaced with
// structed versions
int* fn2(int*, int*, int*, int*);


int* fn1(int* input) {

  int* nixptr = fn2(input, (int*)input, (int*)input, (int*)input);

  printf("input: %u\n", *input);
  return (int*)malloc(PTR_SIZE*sizeof(int));
}

int* fn2(int* input, int* input2, int* input3, int* input4) {
  return NULL;
}

int main()
{
  int* ptr = (int*)malloc(PTR_SIZE*sizeof(int));
  int* ptr2 = (int*)malloc(PTR2_SIZE*sizeof(int));
  int* start_ptr = ptr;
  int* start_ptr2 = ptr2;
  int* start_ptr3 = (int*)malloc(PTR_SIZE*sizeof(int)), *start_ptr4 = start_ptr2;

  int* reclaim1 = ptr;
  int* reclaim2 = ptr2;
  int* reclaim3 = start_ptr3;

  *start_ptr = 1;
  *start_ptr2 = 1;

  *ptr = 3;
  *ptr2 = 9;

  int* new_ptr;

  for(new_ptr = start_ptr; new_ptr < start_ptr + PTR_SIZE; new_ptr++) {
    *new_ptr = 5;
    printf("%u\n", *new_ptr);
  }

  int* whileptr = NULL;
  int* reclaim4 = NULL;

  do
  {
    int* doptr = start_ptr, *forptr2, *doptr2;

    // BUG: create unreclaimed memory
    for(forptr2 = (int*)malloc(PTR_SIZE*sizeof(int)), doptr2 = forptr2; doptr2 < (forptr2 + PTR_SIZE) ; doptr2++) {
      if (reclaim4 == NULL) reclaim4 = forptr2;
    }
  } while (whileptr != NULL);

  int* tempptr = start_ptr;

  if (whileptr == NULL) {
    start_ptr += PTR_SIZE - 1;
    *start_ptr = 10;
  }

  start_ptr = tempptr;

  printf("Final print\n");
  for(new_ptr = start_ptr; new_ptr < start_ptr + PTR_SIZE; new_ptr++) {
    printf("%u\n", *new_ptr);
  }
  printf("Final print -end\n");


  // Review Code
  int* p = (int*)malloc(PTR_SIZE*sizeof(int));
  int* reclaim5 = p;
  int* q;
  int y = (q = p, *q = 5, *q);
  // ------



  // Passing pointers to function
  int* fnptr = fn1(start_ptr);
  int* reclaim6 = fnptr;

  int* fnptr2;
  fnptr2 = fn1(fnptr);
  int* reclaim7 = fnptr2;
  // ------

  // Add more

  free(reclaim1);
  free(reclaim2);
  free(reclaim3);
  free(reclaim4);
  free(reclaim5);
  free(reclaim6);
  free(reclaim7);

  return 0;
}
