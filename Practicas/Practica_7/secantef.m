function [i,xiz,ep] = secantef(xi, tol, y)
disp("METODO DE SECANTE:")
fprintf("\n___________________________________________________\n")
syms x
fprintf("i\txi-1\txi\txi+1\tf(xi-1)\t f(xi) \tep\n");
xia = xi;
xi = xi + 1;
i=1;
ep = 100;
xiz = xi - (subs(y,x,xi) * (xi-xia) / (subs(y,x,xi)-subs(y,x,xia)));
epd = subs(y,x,xiz);
%for i=1:15
while ep>tol
    i = i+1;
    xiz = xi - (subs(y,x,xi) * (xi-xia) / (subs(y,x,xi)-subs(y,x,xia)));
    ep = abs(subs(y,x,xiz) / epd) * 100;
    fprintf("%d\t%.2f\t%.2f\t%.4f\t%.4f\t%.4f\t%.1f%%\n", i, xia, xi, xiz, subs(y,x,xia), subs(y,x,xi), ep);
    if xiz<xia
        xi = xia;
        xia = xiz;
    else
        xia = xi;
        xi = xiz;
    end

end
fprintf("\n___________________________________________________\n")
end