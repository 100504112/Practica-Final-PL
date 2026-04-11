int resultado;

es_par (int n) {
    if ((n % 2) == 0) {
        return 1;
    } else {
        return 0;
    }
}

suma (int a, int b) {
    return (a + b);
}

main() {
    int v[4];
    int i;
    int s = 0;

    for (i = 0 ; i < 4 ; INC(i)) {
        v[i] = i * 3;
    }

    for (i = 0 ; i < 4 ; INC(i)) {
        if (es_par(v[i])) {
            s = suma(s, v[i]);
        }
    }

    resultado = s;

    switch (resultado) {
        case 0  : puts("cero") ; break ;
        case 18 : puts("dieciocho") ; break ;
        default : puts("otro") ; break ;
    }

    printf("%d", resultado);
}