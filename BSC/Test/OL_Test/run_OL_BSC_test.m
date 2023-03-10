bsc_init;
test = 'BSC_TS_1';
test_name = [test,'.mat'];
load(fullfile('..','test_cases',test_name));



test_result_name = [test, '_result.png'];
test_result_path = fullfile('..','OL_Test','Results',test_result_name);

final_time = 10.0;
step_size = 0.1;

test_set = resample(test_set,[0:step_size:final_time]);

warning('off');
sim('OL_BSC.slx');
warning('on');

ha = tight_subplot(8,2,[.07 .03],[.06 .03],[.02 .01]);

figure(1);

axes(ha(1))
plot(test_set.Time,test_set.Data(:,1));
title('pwr request');

axes(ha(3))
plot(test_set.Time,test_set.Data(:,2));
title('vehicle psr');

axes(ha(5))
plot(test_set.Time,test_set.Data(:,3));
title('charger psr');

axes(ha(7))
plot(test_set.Time,test_set.Data(:,4));
title('key');

axes(ha(9))
plot(test_set.Time,test_set.Data(:,5));
title('soc');

axes(ha(11))
plot(test_set.Time,test_set.Data(:,6));
title('high fault');

axes(ha(13))
plot(test_set.Time,test_set.Data(:,7));
title('medium fault');

axes(ha(15))
plot(test_set.Time,test_set.Data(:,8));
title('low fault');
xlabel('Time');

axes(ha(4))
plot(test_set.Time,CVTN_supply_signal.Data);
title('CVTN supply signal');

axes(ha(6))
plot(test_set.Time,main_contactor_cmd.Data);
title('main contactor cmd');

axes(ha(8))
plot(test_set.Time,charger_contactor_cmd.Data);
title('charger contactor cmd');

axes(ha(10))
plot(test_set.Time,sleep_mode.Data);
title('sleep mode');

axes(ha(12))
plot(test_set.Time,reason_to_open_contactor.Data);
title('reason to open contactor');

axes(ha(14))
plot(test_set.Time,fault_type.Data);
title('fault type');

axes(ha(16))
xlabel('Time');


set(gcf,'units','normalized','outerposition',[0 0 1 1])

set(gcf, 'PaperPositionMode', 'auto')
saveas(gcf,test_result_path);

