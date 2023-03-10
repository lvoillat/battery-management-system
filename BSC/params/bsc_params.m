bsck_stepSize = 0.1;

bsck_TempMaxLimit = 45;
bsck_TempMinLimit = -25;

bsck_CellMinVolt = 2.7;
bsck_CellMaxVolt = 4.2;

% bsck_CellMinVolt = 2.0;
% bsck_CellMaxVolt = 3.65;

%Type 1: Severe: Crash, Induced by user
%Type 2: Severe: Empty
%Type 3: Medium: NotDecided, Induced by user
%Type 4: Medium: If voltage/temperature condition is not met by the battery when any of the contactor is connected
%Type 5: Low: Empty
%Typ3 6: Low: Induced by user
%Type 7: Low: Empty

bscv_SevereFaultType = [1];
bscv_MediumFaultType = [2,10,11];
bscv_LowFaultType = [3,4,5,6,7,8,9];

bsck_MainContactorInitCond = 0;
bsck_ChargerContactorInitCond = 0; 

