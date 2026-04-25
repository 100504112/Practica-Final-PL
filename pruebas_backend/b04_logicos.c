
int a ;
int b ;

main ()
{
    a = 1 ;
    b = 0 ;

    if (a && b) { puts ("and T") ; } else { puts ("and F") ; }
    if (a || b) { puts ("or T") ; }  else { puts ("or F") ; }
    if (!a)     { puts ("not T") ; } else { puts ("not F") ; }
    if (!b)     { puts ("not2 T") ; } else { puts ("not2 F") ; }
}
//@ (main)
