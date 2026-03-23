y="pi*x^3 - 3*x + 1";
f=inline(y);
ezplot(y, -1, 2);
grid on;
xi = 0.5;
xo = 1;
tol=0.1;
rootxr_a = 0;
rootxr_b = 0;
if f(xi)*f(xo)<0
    op=0;
    while op~=4
        op=menu('Met. cerrado', "biseccion", "regla falsa", "comparacion", "exit");
        switch op
            case 1
                [i,xr,ep] = biseccion(xi, xo, y, tol);
                rootxr_a = xr;
                disp(rootxr_a);
                cont_a = i;
            case 2
                [i,xr,ep] = reglafalsa(xi, xo, y, tol);
                rootxr_b = xr;
                disp(rootxr_b);
                cont_b = i;
            case 3
                clc;
                comparacionab(rootxr_a,rootxr_b,cont_a,cont_b);
        end

    end
end

