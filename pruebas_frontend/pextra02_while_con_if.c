int i;
int x;

main() {
    i = 0;
    x = 1;
    while (i < 5) {
        if (x == 1) {
            puts("impar");
            x = 0;
        } else {
            puts("par");
            x = 1;
        }
        i = i + 1;
    }
}
//@ (main)
