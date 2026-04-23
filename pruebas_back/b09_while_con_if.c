
int i ;
int suma ;

main ()
{
    i = 1 ;
    suma = 0 ;

    while (i <= 10) {
        if (i % 2 == 0) {
            suma = suma + i ;
        } else {
            printf ("%d", i) ;
        }
        i = i + 1 ;
    }

    printf ("%d", suma) ;
}
//@ (main)
