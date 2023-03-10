sample_time = 0.01;
offset_power_cycle = 0; %80
new_time = time + offset_power_cycle;

pre_time = 0:sample_time:offset_power_cycle-sample_time;
new_time = [pre_time';new_time];

new_cycle = [zeros(length(pre_time),1);cycle];
csvwrite('Charger_FTP_72.csv',[new_time new_cycle]);
%plot(new_time,new_cycle);

%%
%plot(new_time,new_cycle);
charge_on = [15]; 
charger_off = [73]; 
charger = zeros(size(new_time));

for j=1:length(charge_on)
    charger((charge_on(j)/sample_time)+1:(charger_off(j)/sample_time)+1) = 1;
end

figure
plot(new_time,new_cycle);
hold on
plot(new_time,charger,'r--');
ylim([-2 2]);

charger_button_data = [new_time charger];

%%
%plot(new_time,new_cycle);
key_on = [15 160];%[77]; 
key_off = [155 642];%[713]; 
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
loadcycle_num = [zeros(length(0:sample_time:offset_power_cycle-sample_time),1);ones(length(offset_power_cycle:sample_time:new_time(end)),1)];
loadcycle_type = [new_time loadcycle_num];

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
type3_fault_on = [460]; 
type3_fault_off = [470];
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