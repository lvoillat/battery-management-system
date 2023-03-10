SOCk_stepSize = 0.1;

SOCk_CellCapacity = 8;

SOCk_HrsToSec = 3600;

SOCk_ToPercentage = 100;
SOCk_ToFractionFromPercentage = 0.01;

SOCk_SocMinPercentage = 20; %for customer
SOCk_SocMaxPercentage = 80; %for customer

SOCk_NumberInSeries = 40;

SOCv_InitalSOC = zeros(1,40);

SOCc_CapacityFilterCoeff = 0; %0.9;

SOCk_CellBalancingResistor = 1.1;

%load('C_OcvSocTable');
load('C_OcvSocTableAdvancedCell');

SOCv_factoryInitSohC = ones(40,1);