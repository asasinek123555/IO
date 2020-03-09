clc
clear
close

load("wyniki.txt");
load("wyniki2.txt");

min(wyniki2)
max(wyniki2)

stairs(wyniki(:,1),wyniki(:,2));
figure
stairs(wyniki(:,1),wyniki(:,3));
figure;
stairs(wyniki2(:,1),wyniki2(:,2));