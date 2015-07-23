clear aux i j k mean; close all

for i=1:45
    ROC(D{i}(:,1),D{i}(:,2))
end

mean = zeros(45,2);
aux = mean;


for i=1:45
    for j=1:2
        for k=1:45
            aux(i,j)=aux(i,j)+D{k}(i,j);
        end
        mean(i,j)=aux(i,j)/45;
    end
end

figure(2)
plot(mean(:,2),mean(:,1),'m.-')
hold on
title('Curva ROC General')
xlabel('Tasa de falsos positivos')
ylabel('Tasa de verdaderos positivos')
hold on
plot(0:1,0:1,'b-')