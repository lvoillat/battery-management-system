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

initial_pack_voltage = 161; %V
initial_pack_current = 0;
initial_vehicle_side_voltage = 0;
initial_pack_soc = Initial_SOC;
initial_cell_ocvs = Initial_Volt*ones(NUM_CELL_SERIES,1); 
initial_cell_temps = air_temperature*ones(NUM_CELL_SERIES,1);
initial_cell_socs = Initial_SOC*ones(NUM_CELL_SERIES,1);
initial_cell_voltages = Initial_Volt*ones(NUM_CELL_SERIES,1); 
