function []= ROC(TPR, FPR)

figure(1)
plot(FPR(1:20),TPR(1:20),'r.-')
hold on
plot(FPR(21:45),TPR(21:45),'g.-')
title('Curva ROC 1')
xlabel('Tasa de falsos positivos')
ylabel('Tasa de verdaderos positivos')
hold on
plot(0:1,0:1,'b-')