#include "unity.h"
#include "logicalPart.h"
#include "fileReadStore.h"

void test_createArray()
{
  int length = 20;
  int width = 20;
  int **istate = createArray(&length, &width);
  TEST_ASSERT_NOT_NULL_MESSAGE(istate, "CreateArray returns a null pointer");
  int *plength = NULL;
  int *pwidth = NULL;
  istate = createArray(plength, pwidth);
  TEST_ASSERT_NULL_MESSAGE(istate, "CreateArray does not return a null pointer.");
}
void test_findSize()
{
  FILE *file = NULL;
  int length = 20;
  int width = 20;
  int reback = findSize(file, &length, &width);
  TEST_ASSERT_EQUAL_INT_MESSAGE(-1, reback, "Reback of findSize is not -1 as we expected");
  int *plength = NULL;
  int *pwidth = NULL;
  file=fopen("initial.txt","r");
  reback = findSize(file, plength, pwidth);
  TEST_ASSERT_EQUAL_INT_MESSAGE(-1,reback, "Reback of findSize is not -1 as we expected");
  fclose(file);
}
void test_readArray()
{
  FILE *file = NULL;
  int length = 20;
  int width = 20;
  int **istate= createArray(&length, &width);
  int reback=readArray(file,istate,&length,&width);
  TEST_ASSERT_EQUAL_INT_MESSAGE(-1, reback, "Reback of readArray is not -1 as we expected");
  int *plength = NULL;
  int *pwidth = NULL;
  file=fopen("initial.txt","r");
  reback = readArray(file, istate,plength, pwidth);
  TEST_ASSERT_EQUAL_INT_MESSAGE(-1,reback, "Reback of readArray is not -1 as we expected");
  fclose(file);
}
void test_storeArray()
{
  FILE *file = NULL;
  int length = 20;
  int width = 20;
  int **istate= createArray(&length, &width);
  int reback=storeArray(file,istate,&length,&width);
  TEST_ASSERT_EQUAL_INT_MESSAGE(-1, reback, "Reback of storeArray is not -1 as we expected");
  int *plength = NULL;
  int *pwidth = NULL;
  file=fopen("initial.txt","w");
  reback = storeArray(file, istate,plength, pwidth);
  TEST_ASSERT_EQUAL_INT_MESSAGE(-1,reback, "Reback of storeArray is not -1 as we expected");
  fclose(file);
}
void test_nextState()
{
  int length = 5;
  int width = 5;
  int **istate = createArray(&length, &width);
  istate[2][1] = 1;
  istate[2][3] = 1;
  istate[3][2] = 1;
  istate[3][3] = 1;
  istate[4][2] = 1;
  nextState(&length, &width, istate);
  TEST_ASSERT_EQUAL_INT_MESSAGE(1, istate[3][1], "check_next calculate next istate[3][1] is not 1.");
  TEST_ASSERT_EQUAL_INT_MESSAGE(1, istate[2][3], "check_next calculate next istate[2][3] is not 1.");
  TEST_ASSERT_EQUAL_INT_MESSAGE(1, istate[3][3], "check_next calculate next istate[3][4] is not 1.");
  TEST_ASSERT_EQUAL_INT_MESSAGE(1, istate[4][2], "check_next calculate next istate[4][2] is not 1.");
  TEST_ASSERT_EQUAL_INT_MESSAGE(1, istate[4][3], "check_next calculate next istate[4][3] is not 1.");
  TEST_ASSERT_EQUAL_INT_MESSAGE(0, istate[0][0], "check_next calculate next istate[0][0] is not 0.");
}
void setUp()
{
}
void tearDown()
{
}

int main()
{
  UNITY_BEGIN();
  RUN_TEST(test_createArray);
  RUN_TEST(test_findSize);
  RUN_TEST(test_readArray);
  RUN_TEST(test_storeArray);
  RUN_TEST(test_nextState);

  return UNITY_END();
}
