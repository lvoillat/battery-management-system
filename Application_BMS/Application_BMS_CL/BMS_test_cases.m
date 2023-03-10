test_case_no = 1;

CL_testcases_scriptpath = fileparts(mfilename('fullpath'));
addpath(fullfile(CL_testcases_scriptpath,'test_data'));
%initialization
load_cycle_type = 1;
charge_cycle = 1;
air_temperature = 35;
Initial_SOC = 60;
initial_imbalance_soc = 60;
initial_sohr = 100;
initial_sohc = 100;

cycle_name = 'Drive_Cycles/FTP_72.data';

switch test_case_no
    case 1
        load_cycle_type = 1;
        cycle_name = 'Drive_Cycles/FTP_72.data';
        
        %key_data
        load('key_switchON.mat');
        charger_button_data = [key_data(:,1) zeros(size(key_data,1),1)];
        final_time = 660; 
        medium_type2_fault = [key_data(:,1) zeros(size(key_data,1),1)];
        low_type3_fault = [key_data(:,1) zeros(size(key_data,1),1)];
        loadcycle_type = [key_data(:,1) load_cycle_type*ones(size(key_data,1),1)];
        
    case 2
        load_cycle_type = 1;
        cycle_name = 'Drive_Cycles/FTP_72_on_off.data';
        
        %key_data
        load('key_on_off.mat');
        charger_button_data = [key_data(:,1) zeros(size(key_data,1),1)];
        final_time = 420; 
        medium_type2_fault = [key_data(:,1) zeros(size(key_data,1),1)];
        low_type3_fault = [key_data(:,1) zeros(size(key_data,1),1)];
        loadcycle_type = [key_data(:,1) load_cycle_type*ones(size(key_data,1),1)];
        
    case 3
        load_cycle_type = 1;
        cycle_name = 'Drive_Cycles/FTP_72.data';
        
        %key_data
        load('key_switchON.mat');
        charger_button_data = [key_data(:,1) zeros(size(key_data,1),1)];
        final_time = key_data(end,1); 
        medium_type2_fault = [key_data(:,1) zeros(size(key_data,1),1)];
        low_type3_fault = [key_data(:,1) zeros(size(key_data,1),1)];
        loadcycle_type = [key_data(:,1) load_cycle_type*ones(size(key_data,1),1)];

        initial_imbalance_soc = 58;
        
    case 4
        load_cycle_type = 1;
        cycle_name = 'Drive_Cycles/FTP_72_Type2Fault.data';
        
        %key_data
        load('key_type2_fault_power.mat');
        charger_button_data = [key_data(:,1) zeros(size(key_data,1),1)];
        final_time = 290.01; 
        low_type3_fault = [key_data(:,1) zeros(size(key_data,1),1)];
        loadcycle_type = [key_data(:,1) load_cycle_type*ones(size(key_data,1),1)];

        %medium_type2_fault
        load('medium_type2_fault_power.mat');
        
    case 5
        load_cycle_type = 0;
        charge_cycle = 1;
        
        %charger_button_data 
        load('charger_switchON.mat');
        key_data = [charger_button_data(:,1) zeros(size(charger_button_data,1),1)];
        final_time = 350;
        medium_type2_fault = [charger_button_data(:,1) zeros(size(charger_button_data,1),1)];
        low_type3_fault = [key_data(:,1) zeros(size(key_data,1),1)];
        loadcycle_type = [charger_button_data(:,1) load_cycle_type*ones(size(key_data,1),1)];
        
        Initial_SOC = 50;
        initial_imbalance_soc = 50;
        
    case 6 
        load_cycle_type = 1;
        cycle_name = 'Drive_Cycles/FTP_72.data';
        
        %key_data
        load('key_switchON.mat');
        charger_button_data = [key_data(:,1) zeros(size(key_data,1),1)];
        final_time = 660; 
        medium_type2_fault = [key_data(:,1) zeros(size(key_data,1),1)];
        low_type3_fault = [key_data(:,1) zeros(size(key_data,1),1)];
        loadcycle_type = [key_data(:,1) load_cycle_type*ones(size(key_data,1),1)];
        
        air_temperature = 39;
        
        
    case 7
        load_cycle_type = 0;
        charge_cycle = 2;
        
        load('charger_switchOnOff.mat');
        load('key_on_off_late.mat');
        final_time = 90;
        medium_type2_fault = [key_data(:,1) zeros(size(key_data,1),1)];
        low_type3_fault = [key_data(:,1) zeros(size(key_data,1),1)];
        loadcycle_type = [key_data(:,1) load_cycle_type*ones(size(key_data,1),1)];
        
        air_temperature = 35;
        initial_sohc = 98;
        
    case 8
        load_cycle_type = 1;
        cycle_name = 'Drive_Cycles/FTP_72.data';
        
        %key_data
        load('key_switchON.mat');
        charger_button_data = [key_data(:,1) zeros(size(key_data,1),1)];
        final_time = key_data(end,1); 
        medium_type2_fault = [key_data(:,1) zeros(size(key_data,1),1)];
        low_type3_fault = [key_data(:,1) zeros(size(key_data,1),1)];
        loadcycle_type = [key_data(:,1) load_cycle_type*ones(size(key_data,1),1)];
        
        initial_sohr = 98;
        
    case 9
        load_cycle_type = 1;
        cycle_name = 'Drive_Cycles/FTP_72.data';
        
        %key_data
        load('low_medium_fault.mat');
        charger_button_data = [key_data(:,1) zeros(size(key_data,1),1)];
        final_time = key_data(end,1); 
        loadcycle_type = [key_data(:,1) load_cycle_type*ones(size(key_data,1),1)];
        
        air_temperature = 39;
        initial_sohr = 98;
        Initial_SOC = 60;
        initial_imbalance_soc = 58;
        
    case 10
        charge_cycle = 3;
        cycle_name = 'Drive_Cycles/Charger_FTP_72.data';
        
        %key_data
        load('charger_power_cycle.mat');
        final_time = 740; 
        
        medium_type2_fault = [key_data(:,1) zeros(size(key_data,1),1)];
        low_type3_fault = [key_data(:,1) zeros(size(key_data,1),1)];
        
        air_temperature = 39;
        initial_sohr = 98;
        initial_sohc = 98;
        Initial_SOC = 60;
        initial_imbalance_soc = 58;
end