battery_mode_init;

test = 'BMO_TS_2';

test_name = [test,'.mat'];
load(fullfile('..','test_cases',test_name));

final_time = test_pack_current.Time(end);
step_size = 0.1;

warning('off');
sim('OL_BMO.slx');
warning('on');

figure(1)
subplot(3,1,1)
plot(test_pack_voltage,'r')
hold on
plot(test_vehicle_side_voltage,'b--')
title('Pack and Vehicle Side Voltage');
legend('Pack Voltage','Vehicle Side Voltage');
xlabel('Time[s]');
ylabel('V');

subplot(3,1,2)
plot(test_pack_current,'k')
title('Pack Current');
legend('Pack Current');
xlabel('Time[s]');
ylabel('A');

subplot(3,1,3)
plot(bmo_mode,'r')
title('Battery Mode');
legend('Battery Mode');
xlabel('Time[s]');
ylabel('Mode');


figure(2)
subplot(2,1,1)
plot(test_original_soc,'r')
title('Battery State of Charge');
legend('Battery SOC');
xlabel('Time[s]');
ylabel('SOC %');

subplot(2,1,2)
plot(bmo_mode,'r')
title('Battery Mode');
legend('Battery Mode');
xlabel('Time[s]');
ylabel('Mode');

