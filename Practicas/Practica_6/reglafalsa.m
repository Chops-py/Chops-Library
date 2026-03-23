function [i,xr,ep] = reglafalsa(xi, xo, y, tol)
f=inline(y);
i=0;
ep=100;
clc;
fprintf("i\txi\txo\txr\tf(xi)\tf(xo)\tf(xr)\tep\n")
while ep>tol
    i=i+1;
    xr = xo - ((f(xo)*(xi-xo)/(f(xi)-f(xo))));
    fprintf("%d\t%.4f\t%.4f\t%.4f\t%.4f\t%.4f\t%.4f\t%.4f\n", i, xi, xo, xr, f(xi), f(xo), f(xr), ep)
    xiant=xi;
    if f(xi) * f(xr) < 0
            xo = xr; 
    else 
            xi = xr; 
    end
    ep = abs((xr-xiant)/xr)*100;
end