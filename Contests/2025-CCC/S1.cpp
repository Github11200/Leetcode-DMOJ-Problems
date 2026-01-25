#include <bits/stdc++.h>

using namespace std;

int main()
{
  int A, B, X, Y;
  scanf("%d %d %d %d", &A, &B, &X, &Y);

  int verticalPerimeter = 2 * (Y + B) + 2 * max(A, X);
  int horizontalPerimeter = 2 * (A + X) + 2 * max(B, Y);

  int minPerimeter = min(verticalPerimeter, horizontalPerimeter);
  printf("%d\n", minPerimeter);

  return 0;
}