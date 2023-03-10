soc_init;
warning('off');

test = 'SOC_TS_2';
current_sensor_variance = 0;

test_name = [test,'.mat'];
load(test_name);

final_time = test_pack_current.Time(end);
final_time = 25;
step_size = 0.1;

sim('OL_SOC.slx');

close all

warning('on');

figure(1);
subplot(3,1,1)
plot(test_original_soc,'r','Linewidth',1);
hold on
plot(soc_all_cells,'b--','Linewidth',1);
title('Ground Truth SOC and Calculated SOC');
xlabel('Time[s]');
ylabel('SOC %');

subplot(3,1,2)
plot(soc_max,'r','Linewidth',1);
hold on
plot(soc_min,'b','Linewidth',1);
title('Max and Min SOC');
legend('Max SOC','Min SOC');
xlabel('Time[s]');
ylabel('SOC %');

subplot(3,1,3)
plot(soc_customer,'Linewidth',1);
title('Customer SOC');
legend('Customer SOC');
xlabel('Time[s]');
ylabel('SOC %');



figure(2)
subplot(2,1,1)
plot(test_original_soc,'r','Linewidth',1);
hold on
plot(soc_all_cells,'b--','Linewidth',1);
title('Ground Truth SOC and Calculated SOC');
xlabel('Time[s]');
ylabel('SOC %');

subplot(2,1,2)
plot(soc_rate_high);
title('SOC discharge rate high');
legend('SOC rate high');
xlabel('Time[s]');
ylabel('Status');
ylim([-0.1 1.1]);

figure(3)
subplot(2,1,1)
plot(test_pack_current_w_noise);
title('Pack Current with noise');
xlabel('Time[s]');
ylabel('A');

subplot(2,1,2)
plot(test_original_soc,'r','Linewidth',1);
hold on
plot(soc_all_cells,'b--','Linewidth',1);
title('Ground Truth SOC and Calculated SOC');
xlabel('Time[s]');
ylabel('SOC %');

figure(4)
plot(key_data_used);
title('Key');
xlabel('Time[s]');
ylabel('Key State');
ylim([-0.1 1.1]);
