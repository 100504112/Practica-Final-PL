int turno;

main() {
    turno = 0;
    while (turno < 3) {
        switch (turno) {
            case 0 : puts("inicio") ; break ;
            case 1 : puts("medio") ; break ;
            case 2 : puts("fin") ; break ;
            default : puts("error") ; break ;
        }
        turno = turno + 1;
    }
}