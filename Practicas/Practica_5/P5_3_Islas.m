clc; clear;
v=[];
for x=1:10
    v(x)=randi(100);
end
disp("Vector: ")
disp(v)
fprintf("Valor maximo: ")
disp(max(v))
fprintf("Valor minimo: ")
disp(min(v))
fprintf("Valor promedio: ")
disp(mean(v))