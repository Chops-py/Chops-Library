function comparacionab(rootxr_a,rootxr_b,cont_a,cont_b)
if rootxr_a~=0 && rootxr_b ~=0
    fprintf("la raiz por medio de biseccion es:..................%f\n", rootxr_a);
    fprintf("el numero de iteraciones por biseccion es:..........%d\n", cont_a);
    disp(" ")
    fprintf("la raiz por medio de regla falsa es:................%f\n", rootxr_b);
    fprintf("el numero de iteraciones por regla falsa es:........%d\n", cont_b);
    disp(" ")
    rotfunc = 0.713154009;
    difx = abs((rootxr_a/rotfunc)-1) * 100;
    dify = abs((rootxr_b/rotfunc)-1) * 100;

    fprintf("error porcentual de biseccion:......................%.2f%%\n", difx)
    fprintf("error porcentual de regla falsa:....................%.2f%%\n", dify);
else
    fprintf("se necesita definir ambos metodos antes de comparar...\n")
end
end