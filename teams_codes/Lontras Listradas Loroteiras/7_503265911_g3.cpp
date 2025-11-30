#include <bits/stdc++.h>
using namespace std;

int main () {

    int qv;
    scanf("%d", &qv);
    int p[qv], s = 0;

    if (qv != 0 ) {
        for (int i = 0; i < qv; i++) {
            scanf("%d", &p[i]);
        }

        for (int i = 0; i < qv; i++){
            s += p[i];
        }

        if ( s % qv != 0) {
            printf("NAO\n");
        } else {
            printf("SIM\n");
        }

    } else {
        printf("SIM\n");
    }

    return 0;
}

