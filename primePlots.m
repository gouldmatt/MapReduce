load('351 Data Part 2.mat') 

figure(1)
h1 = scatter(primeSingle,1:200,'b','o');
hold on
h3 = scatter(primeMap,1:200,'g','p');
hold on
legend([h1,h3], 'Single Thread','MapReduce')
ylabel('Run #');
xlabel('Execution Time milliseconds'); 
hold off 
title('Figure 6 - Prime Number Frequency Results')
print('Figure 6 - Prime Number Frequency Results','-dpng')

%{
figure(2)
h1 = scatter(method1./1000,1:200,'b','o');
hold on
h2 = scatter(method2./1000,1:200,'k','+');
hold on
h3 = scatter(method3./1000,1:200,'b','o');
hold on 
h4 = scatter(method22./1000,1:200,'r','+');
legend([h1,h2,h4], 'Mutex & Ticket Lock', 'Array Lock Without Sleep','Array Lock With Sleep')
ylabel('Run #');
xlabel('Average Thread Wait Time Seconds');
hold off 
title('Figure 5 - Mutex/Ticket Lock vs Array Locks')
print('Method One and Three vs Method Two','-dpng')

figure(6)
histfit(method1);
ylabel('Frequency');
xlabel('Average Thread Wait Time Milliseconds');
title('Figure 1 - Mutex Lock')
print('Method One','-dpng')

figure(7)
histfit(method2./1000);
ylabel('Frequency');
xlabel('Average Thread Wait Time Seconds');
title('Figure 3 - Array Lock Without Sleep')
print('Method Two','-dpng')

figure(8)
histfit(method3);
ylabel('Frequency');
xlabel('Average Thread Wait Time Milliseconds');
title('Figure 2 - Ticket Lock')
print('Method Three','-dpng')

figure(9)
histfit(method22./1000);
ylabel('Frequency');
xlabel('Average Thread Wait Time Seconds');
title('Figure 4 - Array Lock With Sleep')
print('Method22','-dpng')

averageWait1 = mean(method1)
averageWait2 = mean(method2)
averageWait3 = mean(method3)
averageWait4 = mean(method22)


method1Norm = fitdist(method1.','Normal')
method2Norm = fitdist(method2','Normal')
method3Norm = fitdist(method3','Normal')
method4Norm = fitdist(method22','Normal')
%}
