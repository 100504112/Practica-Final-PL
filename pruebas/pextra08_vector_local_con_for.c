int total;

suma_vector (int n) {
    int v[10];
    int i;
    int s;
    for (i = 0 ; i < n ; INC(i)) {
        v[i] = i + 1;
        s = s + v[i];
    }
    return s;
}

main() {
    total = suma_vector(5);
    printf("%d", total);
}