%plot(time,cycle)
sample_time = 0.01;
key_off_times = [140 150]; %[140 140 140]
new_cycle = [];

for i=1:length(key_off_times)
    new_cycle = [new_cycle;cycle(1:(key_off_times(i)/sample_time)+1)];
end

new_time = 0:sample_time:((length(new_cycle)-1)*sample_time);
new_time = new_time';

%csvwrite('FTP_72_On_Off.csv',[new_time new_cycle]);

%%
%plot(new_time,new_cycle);
key_on = [15 157]; % [15 150 292]
key_off = [150 282]; % [140 280 415]
key = zeros(size(new_time));

for j=1:length(key_on)
    key((key_on(j)/sample_time)+1:(key_off(j)/sample_time)+1) = 1;
end

figure
plot(new_time,new_cycle);
hold on
plot(new_time,key,'r--');
ylim([-2 2]);

key_data = [new_time key];

%%
type2_fault_on = [142]; 
type2_fault_off = [145];
type2_fault = zeros(size(new_time));

for j=1:length(type2_fault_on)
    type2_fault((type2_fault_on(j)/sample_time)+1:(type2_fault_off(j)/sample_time)+1) = 1;
end

figure
plot(new_time,new_cycle);
hold on
plot(new_time,type2_fault,'r--');
ylim([-2 2]);

medium_type2_fault = [new_time type2_fault];

%%
type3_fault_on = [142]; 
type3_fault_off = [145];
type3_fault = zeros(size(new_time));

for j=1:length(type3_fault_on)
    type3_fault((type3_fault_on(j)/sample_time)+1:(type3_fault_off(j)/sample_time)+1) = 1;
end

figure
plot(new_time,new_cycle);
hold on
plot(new_time,type3_fault,'r--');
ylim([-2 2]);

low_type3_fault = [new_time type3_fault];
