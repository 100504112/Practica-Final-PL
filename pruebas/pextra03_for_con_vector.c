int v[5];

main() {
    int i;
    for (i = 0 ; i < 5 ; INC(i)) {
        v[i] = i * 2;
    }
    for (i = 0 ; i < 5 ; INC(i)) {
        printf("%d", v[i]);
    }
}
//@ (main)
