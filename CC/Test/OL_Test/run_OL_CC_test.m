cc_init;

test = 'CC_TS_5';

test_name = [test,'.mat'];
load(fullfile('..','test_cases',test_name));

final_time = 10.0;
step_size = 0.01;

warning('off');
sim('OL_CC.slx');
warning('on');

figure(1)
subplot(2,1,1)
plot(test_set.Time,test_set.Data(:,3),'r','LineWidth',2)
hold on
plot(test_set.Time,test_set.Data(:,4),'b','LineWidth',2)
title('Pack and Vehicle Side Voltage');
xlabel('Time[s]');
ylabel('V');
legend('Pack Voltage','Vehicle Side Voltage');

subplot(2,1,2)
plot(test_set.Time,test_set.Data(:,1),'r--','LineWidth',2)
hold on
plot(precharge_contactor_cmd,'b--','LineWidth',2);
plot(main_contactor_cmd,'k','LineWidth',2);
title('BSC main contactor request and CC precharger and main contactor command');
legend('BSC main request','CC precharge cmd','CC main cmd');
xlabel('Time[s]');
ylabel('State');
ylim([-0.1 1.1]);



figure(2)
subplot(2,1,1)
plot(test_set.Time,test_set.Data(:,3),'r','LineWidth',2)
hold on
plot(test_set.Time,test_set.Data(:,4),'b','LineWidth',2)
title('Pack and Vehicle Side Voltage');
xlabel('Time[s]');
ylabel('V');
legend('Pack Voltage','Vehicle Side Voltage');

subplot(2,1,2)
plot(test_set.Time,test_set.Data(:,2),'r--','LineWidth',2)
hold on
plot(precharge_contactor_cmd,'b--','LineWidth',2);
plot(charger_contactor_cmd,'k','LineWidth',2);
title('BSC charger contactor request and CC precharger and charger contactor command');
legend('BSC charger request','CC precharge cmd','CC charger cmd');
xlabel('Time[s]');
ylabel('State');
ylim([-0.1 1.1]);



figure(3)
subplot(3,1,1)
plot(test_set.Time,test_set.Data(:,3),'r','LineWidth',2)
hold on
plot(test_set.Time,test_set.Data(:,4),'b','LineWidth',2)
title('Pack and Vehicle Side Voltage');
xlabel('Time[s]');
ylabel('V');
legend('Pack Voltage','Vehicle Side Voltage');

subplot(3,1,2)
plot(test_set.Time,test_set.Data(:,1),'r--','LineWidth',2)
hold on
plot(precharge_contactor_cmd,'b--','LineWidth',2);
plot(main_contactor_cmd,'k','LineWidth',2);
title('BSC main contactor request and CC precharger and main contactor command');
legend('BSC main request','CC precharge cmd','CC main cmd');
xlabel('Time[s]');
ylabel('State');
ylim([-0.1 1.1]);

subplot(3,1,3)
plot(precharge_fault_status,'r','LineWidth',2);
title('Precharge Fault Status');
legend('Fault Status');
xlabel('Time[s]');
ylabel('State');
ylim([-0.1 1.1]);

