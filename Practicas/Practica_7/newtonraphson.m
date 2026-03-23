function [i,xr,ep] = newtonraphson(xi, tol, y)
disp("METODO DE NEWTON RAPHSON:")
fprintf("\n___________________________________________________\n")
syms x
ep=100;
i=1;
fprintf("i\txi\tf(xi)\tf'(xi)\tep\n");
xidx = diff(y,x);
xr=subs(xidx,x,xi);
epd = subs(y,x,xi);
while tol<ep
%for z=1:20
    ep = abs(subs(y,x,xi) / epd * 100);
    fprintf("%d\t%.4f\t%.2f\t%.2f\t%.3f%%\n", i, xi, subs(y,x,xi), xr, ep)
    
    xi = xi - (subs(y,x,xi))/(subs(xidx,x,xi));
    xr=subs(xidx,x,xi);
    
    i = i + 1;
end
xr = xi;
fprintf("\n___________________________________________________\n")
end

