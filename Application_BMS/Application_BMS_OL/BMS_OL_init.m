test_case_number = 9;

load(sprintf('test_cases/TS%s',num2str(test_case_number)));
load(sprintf('test_cases/TS%s_faults',num2str(test_case_number)));

battery_mode_init;
bsc_init;
cc_init;
soc_init;
BTC_init;
VITM_init;
SOH_ini;
SOP_ini;
CB_ini;

air_temperature = 35;
BMSk_stepSize = 0.1;
BMSc_airTemperature = air_temperature;
BMSc_cabinTemperature = 25;

use_bsc_sfun = 0;
use_cc_sfun = 0;
use_soc_sfun = 0;
use_bmo_sfun = 0;
use_vit_sfun = 0;
use_btc_sfun = 0;
use_soh_sfun = 0;
use_sop_sfun = 0;
use_cb_sfun = 0;