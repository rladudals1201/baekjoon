//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//
//
//int get_integer(void) {
//   int n;
//   scanf_s("%d", &n);
//
//   return n;
//}
//
//
//
//int main() {
//   int T = 0;
//   T = get_integer();
//   int* num = (int*)malloc(sizeof T);
//   for (int i = 0; i < T; i++) {
//      num[i] = get_integer();
//   }
//
//
//   return 0;
//
//}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int get_integer(void) {
    int n;
    scanf_s("%d", &n);

    return n;
}


int A_Floor_B(int k, int n) {
    int sum_mo = 1;
    int sum_ja = 1;
    if (k > n) {
        for (int i = k + 1; i <= k + n; i++) {
            sum_mo = sum_mo * i;
        }

        for (int i = 1; i <= n; i++) {
            sum_ja = sum_ja * i;
        }
    }

    else {
        for (int i = n + 1; i <= k + n; i++) {
            sum_mo = sum_mo * i;
        }

        for (int i = 1; i <= k; i++) {
            sum_ja = sum_ja * i;
        }
    }

    return sum_mo / sum_ja;
}


int main() {
    int T = 0;
    T = get_integer();
    int k, n;

    for (int i = 0; i < T; i++) {
        k = get_integer();
        n = get_integer();

        if (k == 0) {
            printf("%d\n", n);
        }
        else {
            printf("%d\n", A_Floor_B(k + 1, n - 1));
        }
    }


    return 0;

}