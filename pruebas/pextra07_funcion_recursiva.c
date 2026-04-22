fact (int n) {
    if (n == 1) {
        return 1;
    } else {
        return (n * fact(n - 1));
    }
}

main() {
    printf("%d", fact(5));
    printf("%d", fact(3));
}
//@ (main)
