
int i ;
int j ;
int prod ;

main ()
{
    i = 1 ;
    while (i <= 3) {
        j = 1 ;
        while (j <= 3) {
            prod = i * j ;
            printf ("%d", prod) ;
            j = j + 1 ;
        }
        i = i + 1 ;
    }
}
//@ (main)
