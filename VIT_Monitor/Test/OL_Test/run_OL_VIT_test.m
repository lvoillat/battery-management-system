
addpath(fullfile(pwd, '..\..\..\', 'VIT_Monitor'));  
VITM_init;
  %% Initialize input signals
  sim_time  = 30;
  run_time = 0:0.01:sim_time;
  sig_len = length(run_time);
  cell_num = vitk_NumberInSeries * vitk_NumberInPara;
  
  %% Initialize input signals
  vitm_Input_CellV.time = run_time';
  vitm_Input_CellV.signals.dimensions = cell_num;
  vitm_Input_CellT.time = run_time';
  vitm_Input_CellT.signals.dimensions = cell_num;
  vitm_Input_PackCurrent.time = run_time';
  vitm_Input_PackCurrent.signals.dimensions =1 ;
  vitm_Input_CoolantInletT.time = run_time';
  vitm_Input_CoolantInletT.signals.dimensions = 1;
  vitm_Input_CoolantOutletT.time = run_time';
  vitm_Input_CoolantOutletT.signals.dimensions = 1;
  vitm_Input_VehSideVoltage.time = run_time';
  vitm_Input_VehSideVoltage.signals.dimensions = 1;
  vitm_Input_PackVoltage.time = run_time';
  vitm_Input_PackVoltage.signals.dimensions = 1;
  
  
  
  %% Choose test cases based on user input number
 user_choice = ['Please choose the test case number you want to run (1-8) :\n'];

 choice = input(user_choice);

 switch choice
     case 1
         % make all cell temp between 30 to 35 deg C
        vitm_Input_CellT.signals.values =30+(35-30)*rand( sig_len,cell_num); 
         %  make all cell voltage  between 3 to 3.4V
         vitm_Input_CellV.signals.values =  3+(3.4-3)*rand( sig_len,cell_num); 
        
        vitm_Input_PackCurrent.signals.values = 25*ones(sig_len,1);
        vitm_Input_CoolantInletT.signals.values =  28*ones(sig_len,1);
        vitm_Input_CoolantOutletT.signals.values = 32*ones(sig_len,1);
        vitm_Input_PackVoltage.signals.values = sum( vitm_Input_CellV.signals.values,2)+1.5*rand( sig_len,1);
        vitm_Input_VehSideVoltage.signals.values = sum( vitm_Input_CellV.signals.values,2)+1.5*rand( sig_len,1); 
        sim('VITM_OL_Harness.slx');
         save('test_data/test_1.mat');
         
     case 2
         % make all cell temp between 30 to 35 deg C
        vitm_Input_CellT.signals.values =30+(35-30)*rand( sig_len,cell_num); 
         vitm_Input_CellT.signals.values(101:1200,3) = 75*ones(1100,1);
          vitm_Input_CellT.signals.values(1301:2400,20) = -45*ones(1100,1);
         %  make all cell voltage  between 3 to 3.4V
         vitm_Input_CellV.signals.values =  3+(3.4-3)*rand( sig_len,cell_num); 
        
        vitm_Input_PackCurrent.signals.values = 25*ones(sig_len,1);
        vitm_Input_CoolantInletT.signals.values =  28*ones(sig_len,1);
        vitm_Input_CoolantOutletT.signals.values = 32*ones(sig_len,1);
          vitm_Input_PackVoltage.signals.values = sum( vitm_Input_CellV.signals.values,2)+1.5*rand( sig_len,1);
        vitm_Input_VehSideVoltage.signals.values = sum( vitm_Input_CellV.signals.values,2)+1.5*rand( sig_len,1);
         sim('VITM_OL_Harness.slx');
         save('test_data/test_2.mat');
     case 3
         % make all cell temp between 30 to 35 deg C
        vitm_Input_CellT.signals.values =30+(35-30)*rand( sig_len,cell_num); 
         vitm_Input_CellT.signals.values(101:1200,3) = 75*ones(1100,1);
          vitm_Input_CellT.signals.values(1301:2400,20) = -45*ones(1100,1);
         %  make all cell voltage  between 3 to 3.4V
         vitm_Input_CellV.signals.values =  3+(3.4-3)*rand( sig_len,cell_num); 
        
        vitm_Input_PackCurrent.signals.values = 25*ones(sig_len,1);
        vitm_Input_CoolantInletT.signals.values =  20+(25-20)*rand(sig_len,1);
        vitm_Input_CoolantOutletT.signals.values = 25+(30-25)*rand(sig_len,1);
          vitm_Input_PackVoltage.signals.values = sum( vitm_Input_CellV.signals.values,2)+1.5*rand( sig_len,1);
        vitm_Input_VehSideVoltage.signals.values = sum( vitm_Input_CellV.signals.values,2)+1.5*rand( sig_len,1);
         sim('VITM_OL_Harness.slx');
         save('test_data/test_3.mat');
     case 4
             % make all cell temp between 30 to 35 deg C
        vitm_Input_CellT.signals.values =30+(35-30)*rand( sig_len,cell_num); 
         vitm_Input_CellT.signals.values(101:1200,3) = 75*ones(1100,1);
          vitm_Input_CellT.signals.values(1301:2400,20) = -45*ones(1100,1);
         %  make all cell voltage  between 3 to 3.4V
         vitm_Input_CellV.signals.values =  3+(3.4-3)*rand( sig_len,cell_num); 
        
        vitm_Input_PackCurrent.signals.values = 25*ones(sig_len,1);
        vitm_Input_CoolantInletT.signals.values =  [20+(25-20)*rand(500,1); 80*ones(600,1);20+(25-20)*rand(sig_len-1100,1)];
        vitm_Input_CoolantOutletT.signals.values = [20+(25-20)*rand(1100,1); 80*ones(510,1);20+(25-20)*rand(sig_len-1610,1)];
         sim('VITM_OL_Harness.slx');
         save('test_data/test_4.mat');
     case 5
         % make all cell temp between 30 to 35 deg C
        vitm_Input_CellT.signals.values =30+(35-30)*rand( sig_len,cell_num); 
         %  make all cell voltage  between 3.3 to 3.7V
         vitm_Input_CellV.signals.values =  3.3+(3.7-3.3)*rand( sig_len,cell_num); 
        
        vitm_Input_PackCurrent.signals.values = 25*ones(sig_len,1);
        vitm_Input_CoolantInletT.signals.values =  28*ones(sig_len,1);
        vitm_Input_CoolantOutletT.signals.values = 32*ones(sig_len,1);
          vitm_Input_PackVoltage.signals.values = sum( vitm_Input_CellV.signals.values,2)+1.5*rand( sig_len,1);
        vitm_Input_VehSideVoltage.signals.values = sum( vitm_Input_CellV.signals.values,2)+1.5*rand( sig_len,1);
         sim('VITM_OL_Harness.slx');
         save('test_data/test_5.mat');
     case 6
         % make all cell temp between 30 to 35 deg C
         vitm_Input_CellT.signals.values =30+(35-30)*rand( sig_len,cell_num); 
         %  make all cell voltage  between 3 to 3.4V
         vitm_Input_CellV.signals.values =  3+(3.4-3)*rand( sig_len,cell_num); 
         vitm_Input_CellV.signals.values(301:600,3) = 4.22*ones(300,1);
         vitm_Input_CellV.signals.values(901:1200,23) = 2.65*ones(300,1);
         vitm_Input_PackCurrent.signals.values = 25*ones(sig_len,1);
         vitm_Input_CoolantInletT.signals.values =  28*ones(sig_len,1);
         vitm_Input_CoolantOutletT.signals.values = 32*ones(sig_len,1);
         vitm_Input_PackVoltage.signals.values = sum( vitm_Input_CellV.signals.values,2)+1.5*rand( sig_len,1);
         vitm_Input_VehSideVoltage.signals.values = sum( vitm_Input_CellV.signals.values,2)+1.5*rand( sig_len,1);
         sim('VITM_OL_Harness.slx');
         save('test_data/test_6.mat');
     case 7
         % make all cell temp between 30 to 35 deg C
        vitm_Input_CellT.signals.values =30+(35-30)*rand( sig_len,cell_num); 
         %  make all cell voltage  between 3 to 3.4V
         vitm_Input_CellV.signals.values =  3+(3.4-3)*rand( sig_len,cell_num); 
        vitm_Input_CellV.signals.values(301:600,3) = 4.22*ones(300,1);
         vitm_Input_CellV.signals.values(901:1200,23) = 2.65*ones(300,1);
        vitm_Input_PackCurrent.signals.values = [20+5*rand(1500,1); 330*ones(500,1);20*ones(sig_len-2000,1)];
        vitm_Input_CoolantInletT.signals.values =  28*ones(sig_len,1);
        vitm_Input_CoolantOutletT.signals.values = 32*ones(sig_len,1);
          vitm_Input_PackVoltage.signals.values = sum( vitm_Input_CellV.signals.values,2)+1.5*rand( sig_len,1);
        vitm_Input_VehSideVoltage.signals.values = sum( vitm_Input_CellV.signals.values,2)+1.5*rand( sig_len,1);
         sim('VITM_OL_Harness.slx');
         save('test_data/test_7.mat');
         
 end
 
  figure(1);
subplot(1,2,1);
plot(vitm_Input_CellV.time, vitm_Input_CellV.signals.values , 'LineWidth',1.5);
xlabel('time (s)','FontSize', 12);
ylabel('Cell voltage','FontSize', 12);
subplot(1,2,2);
plot(vitm_CellsMinVoltage.time,vitm_CellsMinVoltage.Data, 'LineWidth',1.5);
xlabel('time (s)','FontSize', 12);
ylabel('minimum cell voltage(V)','FontSize', 12);
 
figure(2);
subplot(1,2,1);
plot(vitm_CellsMaxVoltage.Time, vitm_CellsMaxVoltage.Data , 'LineWidth',1.5);
xlabel('time (s)','FontSize', 12);
ylabel('maximum cell voltage (V)','FontSize', 12);
subplot(1,2,2);
plot(vitm_CellsAvgVoltage.Time,vitm_CellsAvgVoltage.Data, 'LineWidth',1.5);
xlabel('time (s)','FontSize', 12);
ylabel('Average Cell Voltage (V)','FontSize', 12);

figure(3);
subplot(1,2,1);
plot(vitm_CellsVoltageLowFault.Time, vitm_CellsVoltageLowFault.Data , 'LineWidth',1.5);
xlabel('time (s)','FontSize', 12);
ylabel('cell voltage low fault','FontSize', 12);
subplot(1,2,2);
plot(vitm_CellsVoltageHighFault.Time, vitm_CellsVoltageHighFault.Data, 'LineWidth',1.5);
xlabel('time (s)','FontSize', 12);
ylabel('cell voltage high fault', 'FontSize', 12);
