main() {
    int a = 1;
    int b = 0;
    if (!b) {
        puts("b es falso");
    }
    if (a && !b) {
        puts("a true y b false");
    }
    if (a || b) {
        puts("al menos uno true");
    }
}