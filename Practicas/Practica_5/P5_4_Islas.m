clc; clear;
disp("Ingresar a continuacion 5 numeros: ");
v=[];
n=[];
for i = 1:5
    v(i) = input("Numero " + i + ": ");
end
for i = 0:4
    h=5-i;
    o=i+1;
    n(o)=v(h);
end
disp(n)
