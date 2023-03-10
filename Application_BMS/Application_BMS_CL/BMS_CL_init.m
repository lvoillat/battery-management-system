battery_mode_init;
bsc_init;
cc_init;
soc_init;
BTC_init;
VITM_init;
SOH_ini;
SOP_ini;
CB_ini;
BMS_test_cases;
CL_init;

cd(fullfile(BMS_root_path,'Amesim_Model'));

% 1: use c-code mex file, 0: use simulink blocks
use_bsc_sfun = 0;
use_cc_sfun = 0;
use_soc_sfun = 0;
use_bmo_sfun = 0;
use_vit_sfun = 0;
use_btc_sfun = 0;
use_soh_sfun = 0;
use_sop_sfun = 0;
use_cb_sfun = 0;