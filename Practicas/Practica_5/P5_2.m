clc; clear;
t=input("Ingresar el valor de n: ");
D=0;
for x=1:t
    n=x;
    fac=FCA(n);
    D=D+(1/fac);
end
fprintf("La sumatoria es igual a: %f\n", D);
