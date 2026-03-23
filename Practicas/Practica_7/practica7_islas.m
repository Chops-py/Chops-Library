clc;
syms x

tol=0.001;
op = 0;
while op~=4
    op = menu("Met. Abiertos" , "Ingresar Funcion" , "Met. Newton Raphson" , "Met. Secante" , "Exit" , "Limpiar pantalla");
    switch op
        case 1
            y = input ("Ingresar la funcion: ");
            %y = x^2-2;
            ezplot(y, -1, 2);
            grid on;
            xi = input("Ingresar xi: ");
            %xi = -1;
        case 2
            [i,xr,ep] = newtonraphson(xi, tol, y);
        case 3
            [i,xiz,ep] = secantef(xi, tol, y);
        case 5
            limpieza ()
    end
end

