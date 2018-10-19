primeSingle = zeros(1,200);
primeMap = zeros(1,200);


% Run each method k times 
for k = 1 : 200 
    [~,outM1] = system('./primeNumFreq');
    primeSingle(1,k) = str2double(outM1); 
end 

for k = 1 : 200
    [~,outM2] = system('./guestPrimeNumber');
    primeMap(1,k) = str2double(outM2); 
    
end 

save('351 Data Part 2')