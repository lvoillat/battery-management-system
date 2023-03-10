%will not work until Contactor Control is setup up in new Format storage
%and init file

original_wd = pwd;

load_cycle_type = 1;
charge_cycle = 1;
cycle_name = 'Drive_Cycles/FTP_72.data';
air_temperature = 35;
Initial_SOC = 60;
initial_imbalance_soc = 60;
initial_sohr = 100;
initial_sohc = 100;

bsc_init;
CL_init;

%other systems
cc_init; 

test = 'BSC_TS_1';

test_name = [test,'.mat'];
load(fullfile('..','test_cases',test_name));

final_time = 10.0;
step_size = 0.01;

path = mfilename('fullpath');
path_to_add = regexp(path,'.+(?=\\.+$)','match');
addpath(path_to_add{1});

AME_model_path = fullfile(BMS_root_path,'Amesim_Model');
cd(AME_model_path);

warning('off');
sim('CL_BSC.slx');
warning('on');

cd(original_wd);
rmpath(path_to_add{1});



