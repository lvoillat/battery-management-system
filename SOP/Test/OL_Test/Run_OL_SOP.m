addpath(fullfile(pwd, '..\..\..\', 'SOP'));  
SOP_ini;
  sim_time  = 30;
  run_time = 0:0.01:sim_time;
  sig_len = length(run_time);
  sample_time = 0.01;
  cell_num = 40;

  SOP_CellSOC.time = run_time';
  SOP_CellSOC.signals.dimensions = cell_num;
  SOP_CellTemp.time = run_time';
  SOP_CellTemp.signals.dimensions = cell_num;
  SOP_ChargingStatus.time = run_time';
  SOP_ChargingStatus.signals.dimensions =1 ;
  SOP_DisChargingStatus.time = run_time';
  SOP_DisChargingStatus.signals.dimensions =1 ;
  SOP_CellTempHighFault.time = run_time';
  SOP_CellTempHighFault.signals.dimensions =1 ;
  SOP_PackVoltageFault.time = run_time';
  SOP_PackVoltageFault.signals.dimensions =1 ;
  SOP_PackCurrentFault.time = run_time';
  SOP_PackCurrentFault.signals.dimensions =1 ;
  SOP_IntResScale.time = run_time';
  SOP_IntResScale.signals.dimensions =cell_num; 
  
  
 user_choice = ['Please choose the test case number you want to run (1-8) :\n'];
 choice = input(user_choice);

 switch choice
     case 1
         SOP_CellTemp.signals.values =  27+(35-34)*rand( sig_len,cell_num); 
         SOP_CellSOC.signals.values = 63+ 2*rand(sig_len,cell_num);
         SOP_DisChargingStatus.signals.values =  boolean(zeros(sig_len,1));
         SOP_ChargingStatus.signals.values =  boolean(ones(sig_len,1));
         SOP_CellTempHighFault.signals.values =  boolean(zeros(sig_len,1));
         SOP_PackCurrentFault.signals.values =  boolean(zeros(sig_len,1));
         SOP_PackVoltageFault.signals.values =  boolean(zeros(sig_len,1));
         SOP_IntResScale.signals.values = ones( sig_len,cell_num); 
         sim('SOP_OL_Harness.slx');
         save('test_data/test_1.mat');
     case 2
         SOP_CellTemp.signals.values =  23+(35-34)*rand( sig_len,cell_num); 
         SOP_CellSOC.signals.values = 30+ 2*rand(sig_len,cell_num);
         SOP_DisChargingStatus.signals.values =  boolean(ones(sig_len,1));
         SOP_ChargingStatus.signals.values =  boolean(zeros(sig_len,1));
         SOP_CellTempHighFault.signals.values =  boolean(zeros(sig_len,1));
         SOP_PackCurrentFault.signals.values =  boolean(zeros(sig_len,1));
         SOP_PackVoltageFault.signals.values =  boolean(zeros(sig_len,1));
         SOP_IntResScale.signals.values = ones( sig_len,cell_num); 
         sim('SOP_OL_Harness.slx');
         save('test_data/test_2mat');
     case 3
         SOP_CellTemp.signals.values =  30+(35-34)*rand( sig_len,cell_num); 
         SOP_CellSOC.signals.values = 60+ 2*rand(sig_len,cell_num);
         SOP_DisChargingStatus.signals.values =  boolean(zeros(sig_len,1));
         SOP_ChargingStatus.signals.values =  boolean(ones(sig_len,1));
         SOP_CellTempHighFault.signals.values =  boolean(zeros(sig_len,1));
         SOP_PackCurrentFault.signals.values =  boolean(zeros(sig_len,1));
         SOP_PackVoltageFault.signals.values =  boolean(zeros(sig_len,1));
         SOP_IntResScale.signals.values = ones( sig_len,cell_num); 
         sim('SOP_OL_Harness.slx');
         save('test_data/test_3.mat');
     case 4
         SOP_CellTemp.signals.values =  26+(35-34)*rand( sig_len,cell_num); 
         SOP_CellSOC.signals.values = 50+ 2*rand(sig_len,cell_num);
         SOP_DisChargingStatus.signals.values =  boolean(ones(sig_len,1));
         SOP_ChargingStatus.signals.values =  boolean(zeros(sig_len,1));
         SOP_CellTempHighFault.signals.values =  boolean(zeros(sig_len,1));
         SOP_PackCurrentFault.signals.values =  boolean(zeros(sig_len,1));
         SOP_PackVoltageFault.signals.values =  boolean(zeros(sig_len,1));
         SOP_IntResScale.signals.values = ones( sig_len,cell_num); 
         sim('SOP_OL_Harness.slx');
         save('test_data/test_4.mat');
     case 5
         SOP_CellTemp.signals.values =  25+(35-34)*rand( sig_len,cell_num); 
         SOP_CellSOC.signals.values = 46+ 2*rand(sig_len,cell_num);
         SOP_DisChargingStatus.signals.values =  boolean(zeros(sig_len,1));
         SOP_ChargingStatus.signals.values =  boolean(ones(sig_len,1));
         SOP_CellTempHighFault.signals.values =  boolean(zeros(sig_len,1));
         SOP_PackCurrentFault.signals.values =  boolean(zeros(sig_len,1));
         SOP_PackVoltageFault.signals.values =  boolean(zeros(sig_len,1));
         SOP_IntResScale.signals.values = ones( sig_len,cell_num); 
         sim('SOP_OL_Harness.slx');
         save('test_data/test_5.mat');
     case 6
         SOP_CellTemp.signals.values =  25+(35-34)*rand( sig_len,cell_num); 
         SOP_CellSOC.signals.values = 46+ 2*rand(sig_len,cell_num);
         SOP_DisChargingStatus.signals.values =  boolean(ones(sig_len,1));
         SOP_ChargingStatus.signals.values =  boolean(zeros(sig_len,1));
         SOP_CellTempHighFault.signals.values =  boolean(zeros(sig_len,1));
         SOP_PackCurrentFault.signals.values =  boolean(zeros(sig_len,1));
         SOP_PackVoltageFault.signals.values =  boolean(zeros(sig_len,1));
         SOP_IntResScale.signals.values = ones( sig_len,cell_num); 
         sim('SOP_OL_Harness.slx');
         save('test_data/test_6.mat');
     case 7
           SOP_CellTemp.signals.values =  36+(35-34)*rand( sig_len,cell_num); 
         SOP_CellSOC.signals.values = 42+ 2*rand(sig_len,cell_num);
         SOP_DisChargingStatus.signals.values =  boolean(ones(sig_len,1));
         SOP_ChargingStatus.signals.values =  boolean(zeros(sig_len,1));
         SOP_CellTempHighFault.signals.values =  boolean(zeros(sig_len,1));
         SOP_PackCurrentFault.signals.values =  boolean(zeros(sig_len,1));
         SOP_PackVoltageFault.signals.values =  boolean([zeros(sig_len-100,1);ones(100,1)]);
         SOP_IntResScale.signals.values = ones( sig_len,cell_num); 
         sim('SOP_OL_Harness.slx');
         save('test_data/test_7.mat');
     case 8
         SOP_CellTemp.signals.values = 23+(35-34)*rand( sig_len,cell_num); 
         SOP_CellSOC.signals.values = 30+ 2*rand(sig_len,cell_num);
         SOP_DisChargingStatus.signals.values =  boolean(zeros(sig_len,1));
         SOP_ChargingStatus.signals.values =  boolean(ones(sig_len,1));
         SOP_CellTempHighFault.signals.values =  boolean(zeros(sig_len,1));
         SOP_PackCurrentFault.signals.values =  boolean(zeros(sig_len,1));
         SOP_PackVoltageFault.signals.values =  boolean(zeros(sig_len,1));
         SOP_IntResScale.signals.values = 0.95+0.03*rand( sig_len,cell_num); 
         sim('SOP_OL_Harness.slx');
         save('test_data/test_8.mat');
 end
 
 figure(1);
subplot(1,2,1);
plot(SOP_CellSOC.time, SOP_CellSOC.signals.values , 'LineWidth',1.5);
xlabel('time (s)','FontSize', 12);
ylabel('Cell SOC','FontSize', 12);
subplot(1,2,2);
plot(SOP_CellTemp.time,SOP_CellTemp.signals.values, 'LineWidth',1.5);
xlabel('time (s)','FontSize', 12);
ylabel('cell temperatures (deg C)','FontSize', 12);

 figure(2);
subplot(1,2,1);
plot(SOP_DischgPwLim.Time, SOP_DischgPwLim.Data , 'LineWidth',1.5);
xlabel('time (s)','FontSize', 12);
ylabel('battery charging power limit (W)','FontSize', 12);
subplot(1,2,2);
plot(SOP_DischgCurrentLim.Time,SOP_DischgCurrentLim.Data, 'LineWidth',1.5);
xlabel('time (s)','FontSize', 12);
ylabel('battery charging current limit(A)','FontSize', 12);

 figure(3);
subplot(1,2,1);
plot(SOP_CellSOC.time, SOP_CellSOC.signals.values , 'LineWidth',1.5);
xlabel('time (s)','FontSize', 12);
ylabel('Cell SOC','FontSize', 12);
subplot(1,2,2);
plot(SOP_IntResScale.time,SOP_IntResScale.signals.values, 'LineWidth',1.5);
xlabel('time (s)','FontSize', 12);
ylabel('Internal resistance Factor','FontSize', 12);
