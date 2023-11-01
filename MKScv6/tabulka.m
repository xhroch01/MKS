close all
clear all

ntc = csvread('ntc.csv')';

temperature1=ntc(1,:);
r=ntc(2,:);

adc1=r./(r+10).*(2^10);

plot(adc1, temperature1, 'x');
hold on
grid on

ad2 = 0:1023;
p = polyfit(adc1, temperature1, 10);
t2 = round(polyval(p, ad2), 1);

hold on, plot(ad2, t2, 'r');

dlmwrite('data.dlm', t2*10, ',');

