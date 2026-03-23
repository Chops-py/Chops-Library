clc; clear;
V =[];
disp("Ingresar solo valores entre 1 y 9")
for i=1:3
    for l=1:3
        t = input("");
        if t>=1 && t<=9
            V(i,l) = t;
        else
            while ~(t >= 1) || ~(t <= 9)
                disp("Valor inválido. Ingrese un número entre 1 y 9:");
                t = input("");
                V(i,l) = t;
            end
        end
    end
end



disp("Matriz: ")
disp(V);

for i=1:3
    p=0;
    for l=1:3
        p=p+V(i,l);
    end
    fprintf("Valor de la sumatoria en la fila %d es: %.2f\n", i , p)
end

disp("valor maximo: ")
disp(max(max(V)))
disp("valor promedio:")
disp(mean(mean(V)))
