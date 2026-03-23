function [i,xr,ep] = biseccion(xi, xo, y, tol)
    f=inline(y);
    i=0;
    ep=100;
    clc;
    fprintf("i\txi\txo\txr\tf(xi)\tf(xo)\tf(xr)\tep\n");
    while ep>tol
        i = i + 1;

        xr = (xi + xo) / 2; 
        fprintf("%d\t%.4f\t%.4f\t%.4f\t%.4f\t%.4f\t%.4f\t%.2f\n", i, xi, xo, xr, f(xi), f(xo), f(xr), ep); 
        if f(xi) * f(xr) < 0
            xo = xr; 
        else 
            xi = xr; 
        end
        ep = abs((xo - xi) / xr)*100;
        
    end
    XF=(xo+xi)/2;
    fprintf("")