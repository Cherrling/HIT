// #include <corecrt.h>
#include <stdio.h>

// n!=n*(n-1)!
//(n-1)!=(n-1)*(n-2)!
//(n-2)!=(n-2)*(n-3)!

// 2!=2*1!

int calc(int n) {

  if (n == 1) {
    return 1;
  } else {

    return n * calc(n - 1);
  }
}

int main() { int n = 10; 

char h[100];
scanf("%s",h);

  for (int i=0; h[i]!='\0'; i++) {
      h[i];
  }



for (;;) {
  char x;
  scanf("%c",&x);
  if (x=='\0') {
    break;
  }


  

}





}