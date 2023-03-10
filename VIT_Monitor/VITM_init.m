vitk_stepSize = 0.1; 

%% Those are coefficients for filters of various sensors
vitc_CellVolFilterC = 1;
vitc_PackVolFilterC = 1;
vitc_VehVolFilterC = 1;
vitc_PackCurFilterC = 1;
vitc_CoolantTFilterC = 0.9;
vitc_CellTempFilterC = 1.0;

vitc_CellVoltageMin = 2.7;
vitc_CellVoltageMax = 4.2;
vitc_CellVoltageFaultTimer = 2;
vitc_CellVoltageLowFaultReset = 0;
vitc_CellVoltageHighFaultReset = 0;


vitc_CellPackVolTol = 12;
vitc_PackVoltageFaultTimer = 10;
vitc_PackVoltageFaultReset = 0;

vitc_PackCurrentLimit = 300;
vitc_PackCurrentFaultTimer = 1;
vitc_PackCurrentFaultReset = 0;

vitc_CellTempMin = -40;
vitc_CellTempMax = 70;
vitc_CellTempFaultTimer = 10;
vitc_CellTempLowFaultReset = 0;
vitc_CellTempHighFaultReset = 0;

vitc_CoolantInletTUpperLim = 70;
vitc_CoolantInletTLowerLim = -40;
vitc_CoolantOutletTUpperLim = 70;
vitc_CoolantOutletTLowerLim = -40;

vitk_NumberInSeries = 40;
vitk_NumberInPara = 1;

vitc_CoolantTempFaultCounter = 5;
vitc_CoolantInletTFaultReset = 0;
vitc_CoolantOutletTFaultReset = 0;

vitc_HVILFaultCounter = 1;
vitc_HVILFaultReset = 0;