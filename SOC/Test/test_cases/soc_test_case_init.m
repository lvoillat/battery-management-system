test_case_no = 2;

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
        final_time = key_data(end,1); 
        medium_type2_fault = [key_data(:,1) zeros(size(key_data,1),1)];
        low_type3_fault = [key_data(:,1) zeros(size(key_data,1),1)];
        loadcycle_type = [key_data(:,1) load_cycle_type*ones(size(key_data,1),1)];

        initial_imbalance_soc = 58;
        
    case 2
        load_cycle_type = 0;
        charge_cycle = 3;
        
        %key_data
        load('key_switchON.mat');
        charger_button_data = [key_data(:,1) zeros(size(key_data,1),1)];
        final_time = 25;
        medium_type2_fault = [key_data(:,1) zeros(size(key_data,1),1)];
        low_type3_fault = [key_data(:,1) zeros(size(key_data,1),1)];
        loadcycle_type = [key_data(:,1) load_cycle_type*ones(size(key_data,1),1)];
        
        Initial_SOC = 50;
        initial_imbalance_soc = 50;
        
   case 3
        load_cycle_type = 1;
        cycle_name = 'Drive_Cycles/FTP_72_on_off.data';
        
        %key_data
        load('key_on_off.mat');
        charger_button_data = [key_data(:,1) zeros(size(key_data,1),1)];
        final_time = 420; 
        medium_type2_fault = [key_data(:,1) zeros(size(key_data,1),1)];
        low_type3_fault = [key_data(:,1) zeros(size(key_data,1),1)];
        loadcycle_type = [key_data(:,1) load_cycle_type*ones(size(key_data,1),1)];
        
   case 4
        load_cycle_type = 0;
        charge_cycle = 3;
        
        %charger_button_data 
        load('charger_switchON.mat');
        key_data = [charger_button_data(:,1) zeros(size(charger_button_data,1),1)];
        final_time = 25;
        medium_type2_fault = [charger_button_data(:,1) zeros(size(charger_button_data,1),1)];
        low_type3_fault = [key_data(:,1) zeros(size(key_data,1),1)];
        loadcycle_type = [charger_button_data(:,1) load_cycle_type*ones(size(key_data,1),1)];
        
        Initial_SOC = 21;
        initial_imbalance_soc = 21;
        
   case 5
        load_cycle_type = 0;
        charge_cycle = 4;
        
        %charger_button_data 
        load('charger_switchON.mat');
        key_data = [charger_button_data(:,1) zeros(size(charger_button_data,1),1)];
        final_time = 25;
        medium_type2_fault = [charger_button_data(:,1) zeros(size(charger_button_data,1),1)];
        low_type3_fault = [key_data(:,1) zeros(size(key_data,1),1)];
        loadcycle_type = [charger_button_data(:,1) load_cycle_type*ones(size(key_data,1),1)];
        
        Initial_SOC = 79;
        initial_imbalance_soc = 79;
end

bsc_init;
cc_init;
soc_init;
BMSk_stepSize = 0.1;
BMSc_airTemperature = air_temperature;
BMSc_cabinTemperature = 25;

sampling_time = BMSk_stepSize;
pack_voltage_sampling = sampling_time;
pack_current_sampling = sampling_time;
vehicle_side_voltage_sampling = sampling_time;
pack_soc_sampling = sampling_time;
cell_voltages_sampling = sampling_time;
cell_temps_sampling = sampling_time;
cell_socs_sampling = sampling_time;
cell_ocvs_sampling = sampling_time;

Initial_Volt = 3.74;
NUM_CELL_SERIES = 40;

inital_outlet_temperature = air_temperature;

cd(fullfile(BMS_root_path,'Amesim_Model'));

initial_pack_voltage = 161; %V
initial_pack_current = 0;
initial_vehicle_side_voltage = 0;
initial_pack_soc = Initial_SOC;
initial_cell_ocvs = Initial_Volt*ones(NUM_CELL_SERIES,1); 
initial_cell_temps = air_temperature*ones(NUM_CELL_SERIES,1);
initial_cell_socs = Initial_SOC*ones(NUM_CELL_SERIES,1);
initial_cell_voltages = Initial_Volt*ones(NUM_CELL_SERIES,1); 
