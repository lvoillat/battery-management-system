
addpath(fullfile(pwd, '..', 'BTC'));  
BTC_init;
  %% Initialize input signals
  sim_time  = 10;
  run_time = 0:0.01:sim_time;
  sig_len = length(run_time);
  cell_num = btcc_number_in_series * btcc_pack_in_parallel;
  
  %% Initialize input signals1
  BTC_Input_CellT.time = run_time';
  BTC_Input_CellT.signals.dimensions = cell_num;
  BTC_Input_CellSOC.time = run_time';
  BTC_Input_CellSOC.signals.dimensions = cell_num;
  BTC_Input_ChgStatus.time = run_time';
  BTC_Input_ChgStatus.signals.dimensions = 1;
  BTC_Input_AmbTmep.time = run_time';
  BTC_Input_AmbTmep.signals.dimensions = 1;
  BTC_Input_DisChgStatus.time = run_time';
  BTC_Input_DisChgStatus.signals.dimensions = 1;
  BTC_Input_Faults.time = run_time';
  BTC_Input_Faults.signals.dimensions = 4;
  
  %% Choose test cases based on user input number
 user_choice = ['Please choose the test case number you want to run (1-8) :\n'];

 choice = input(user_choice);

 switch choice
     case 1
         % make all cell temp between 30 to 35 deg C
         BTC_Input_CellT.signals.values =30+(35-30)*rand( sig_len,cell_num); 
         %  make all SOC  between 60 to 62 deg C
         BTC_Input_CellSOC.signals.values =  60+(62-60)*rand( sig_len,cell_num); 
         BTC_Input_ChgStatus.signals.values = boolean(zeros(sig_len,1));
         BTC_Input_AmbTmep.signals.values = 25*ones(sig_len,1);
         BTC_Input_DisChgStatus.signals.values = boolean(zeros(sig_len,1));
         BTC_Input_Faults.signals.values = boolean(zeros(sig_len,4));
         sim('BTC_OL_Harness.slx');
         save('test_data/test_1.mat');
         
     case 2
           % make all cell temp between 30 to 35 deg C
         BTC_Input_CellT.signals.values =30+(35-30)*rand( sig_len,cell_num); 
         %set one cell temperature is greater than maximum temperature high
         %threshold
          BTC_Input_CellT.signals.values(201:1:300,3) = 43*ones(100,1);
          %set one cell temperature is less than minimum temperature
          %low threshold
           BTC_Input_CellT.signals.values(401:1:500,5) = 16*ones(100,1);
           
           %set two cell temperature difference is greater than threshold
           BTC_Input_CellT.signals.values(601:1:700,5) = 26*ones(100,1);
           
         
         %  make all SOC  between 60 to 62 percent
         BTC_Input_CellSOC.signals.values =  60+(62-60)*rand( sig_len,cell_num); 
         BTC_Input_ChgStatus.signals.values = boolean(zeros(sig_len,1));
         BTC_Input_AmbTmep.signals.values = 25*ones(sig_len,1);
         %determine discharge status
         BTC_Input_DisChgStatus.signals.values = boolean(ones(sig_len,1));
         BTC_Input_Faults.signals.values = boolean(zeros(sig_len,4));
         sim('BTC_OL_Harness.slx');
        save('test_data/test_2.mat')
     case 3
         % make all cell temp between 30 to 35 deg C
         BTC_Input_CellT.signals.values =30+(35-30)*rand( sig_len,cell_num); 
         BTC_Input_CellT.signals.values(:,1)=45*ones( sig_len,1); 
         %  make all SOC  between 60 to 62 deg C
         BTC_Input_CellSOC.signals.values =  60+(62-60)*rand( sig_len,cell_num); 
         BTC_Input_ChgStatus.signals.values = boolean(zeros(sig_len,1));
         BTC_Input_AmbTmep.signals.values = 25*ones(sig_len,1);
         BTC_Input_DisChgStatus.signals.values =  boolean([ones(500,1);zeros(sig_len-500,1)]);
         BTC_Input_Faults.signals.values = boolean(zeros(sig_len,4));
         sim('BTC_OL_Harness.slx');
         save('test_data/test_3.mat');
      case 4
         % make all cell temp between 30 to 35 deg C
         BTC_Input_CellT.signals.values =30+(35-30)*rand( sig_len,cell_num); 
         BTC_Input_CellT.signals.values(:,1)=45*ones( sig_len,1); 
         %  make all SOC  between 60 to 62 deg C
         BTC_Input_CellSOC.signals.values =  60+(62-60)*rand( sig_len,cell_num); 
         BTC_Input_ChgStatus.signals.values = boolean(zeros(sig_len,1));
         BTC_Input_AmbTmep.signals.values = 25*ones(sig_len,1);
         BTC_Input_DisChgStatus.signals.values =  boolean([ones(500,1);zeros(sig_len-500,1)]);
         BTC_Input_Faults.signals.values = boolean(zeros(sig_len,4));
         sim('BTC_OL_Harness.slx');
         save('test_data/test_4.mat');
     case 5
         % make all cell temp between 30 to 35 deg C
         BTC_Input_CellT.signals.values =30+(35-30)*rand( sig_len,cell_num); 
         BTC_Input_CellT.signals.values(:,1)=45*ones( sig_len,1); 
         %  make all SOC  between 60 to 62 deg C
         BTC_Input_CellSOC.signals.values =  60+(62-60)*rand( sig_len,cell_num); 
         BTC_Input_ChgStatus.signals.values = boolean(zeros(sig_len,1));
         BTC_Input_AmbTmep.signals.values = 25*ones(sig_len,1);
         BTC_Input_DisChgStatus.signals.values =  boolean([ones(500,1);zeros(sig_len-500,1)]);
         BTC_Input_Faults.signals.values = boolean(zeros(sig_len,4));
         BTC_Input_Faults.signals.values(201:1:300,1) = ones(100,1);
         BTC_Input_Faults.signals.values(401:1:500,2) = ones(100,1);
         BTC_Input_Faults.signals.values(601:1:700,3) = ones(100,1);
         BTC_Input_Faults.signals.values(801:1:900,4) = ones(100,1);
         sim('BTC_OL_Harness.slx');
         save ('test_data/test_5.mat');
     case 6
         BTC_Input_CellT.signals.values =30+(35-30)*rand( sig_len,cell_num); 
         %set one cell temperature is greater than maximum temperature high
         %threshold
          BTC_Input_CellT.signals.values(201:1:300,3) = 43*ones(100,1);
          %set one cell temperature is less than minimum temperature
          %low threshold
           BTC_Input_CellT.signals.values(301:1:400,5) = 16*ones(100,1);
           
           %set two cell temperature difference is greater than threshold
           BTC_Input_CellT.signals.values(501:1:600,5) = 26*ones(100,1);
           
         
         %  make all SOC  between 60 to 62 percent
         BTC_Input_CellSOC.signals.values =  60+(62-60)*rand( sig_len,cell_num); 
         BTC_Input_ChgStatus.signals.values = boolean(zeros(sig_len,1));
         BTC_Input_AmbTmep.signals.values = 25*ones(sig_len,1);
         %determine discharge status
         BTC_Input_DisChgStatus.signals.values = boolean(ones(sig_len,1));
         BTC_Input_Faults.signals.values = boolean(zeros(sig_len,4));
         sim('BTC_OL_Harness.slx');
         save('test_data/test_6.mat')
     case 7
         BTC_Input_CellT.signals.values =30+(35-30)*rand( sig_len,cell_num); 
         %set one cell temperature is greater than maximum temperature high
         %threshold
          BTC_Input_CellT.signals.values(201:1:300,3) = 43*ones(100,1);
          %set one cell temperature is less than minimum temperature
          %low threshold
           BTC_Input_CellT.signals.values(401:1:500,5) = 16*ones(100,1);
           
           %set two cell temperature difference is greater than threshold
           BTC_Input_CellT.signals.values(601:1:700,5) = 26*ones(100,1);
           
         
         %  make all SOC  between 60 to 62 percent
         BTC_Input_CellSOC.signals.values =  60+(62-60)*rand( sig_len,cell_num); 
         BTC_Input_ChgStatus.signals.values = boolean(zeros(sig_len,1));
         BTC_Input_AmbTmep.signals.values = 25*ones(sig_len,1);
         %determine discharge status
         BTC_Input_DisChgStatus.signals.values = boolean(ones(sig_len,1));
         BTC_Input_Faults.signals.values = boolean(zeros(sig_len,4));
         sim('BTC_OL_Harness.slx');
         save('test_data/test_7.mat')
     case 8
       % make all cell temp between 30 to 35 deg C
         BTC_Input_CellT.signals.values =30+(35-30)*rand( sig_len,cell_num); 
         %  make all SOC  between 96 to 98
         BTC_Input_CellSOC.signals.values =  98+(98-96)*rand( sig_len,cell_num); 
         BTC_Input_ChgStatus.signals.values = boolean(ones(sig_len,1));
         BTC_Input_AmbTmep.signals.values = [-35*ones(100,1);47*ones(200,1);27*ones(sig_len-300,1)];
         BTC_Input_DisChgStatus.signals.values =  boolean(zeros(sig_len,1));
         BTC_Input_Faults.signals.values = boolean(zeros(sig_len,4));
         sim('BTC_OL_Harness.slx');
         save('test_data/test_8.mat');  
 end
 
  figure(1);
subplot(1,2,1);
plot(BTC_Input_CellSOC.time, BTC_Input_CellSOC.signals.values , 'LineWidth',1.5);
xlabel('time (s)','FontSize', 12);
ylabel('Cell SOC','FontSize', 12);
subplot(1,2,2);
plot(BTC_Input_CellT.time,BTC_Input_CellT.signals.values, 'LineWidth',1.5);
xlabel('time (s)','FontSize', 12);
ylabel('cell temperatures (deg C)','FontSize', 12);

 figure(2);
subplot(1,2,1);
plot(btc_batt_actual_temp.Time, btc_batt_actual_temp.Data , 'LineWidth',1.5);
xlabel('time (s)','FontSize', 12);
ylabel('battery actual temperature (deg C)','FontSize', 12);
subplot(1,2,2);
plot(btc_coolant_request_status.Time,btc_coolant_request_status.Data, 'LineWidth',1.5);
xlabel('time (s)','FontSize', 12);
ylabel('battery coolant request','FontSize', 12);

 figure(3);
subplot(1,2,1);
plot(BTC_Input_CellSOC.time, BTC_Input_CellSOC.signals.values , 'LineWidth',1.5);
xlabel('time (s)','FontSize', 12);
ylabel('Cell SOC','FontSize', 12);
subplot(1,2,2);
plot( BTC_Input_AmbTmep.time, BTC_Input_AmbTmep.signals.values, 'LineWidth',1.5);
xlabel('time (s)','FontSize', 12);
ylabel('ambient temperatures (deg C)','FontSize', 12);

figure(4);
subplot(1,2,1);
plot(btc_batt_target_temp.Time, btc_batt_target_temp.Data , 'LineWidth',1.5);
xlabel('time (s)','FontSize', 12);
ylabel('target battery temperature (deg C)','FontSize', 12);
subplot(1,2,2);
plot(btc_coolant_request_status.Time,btc_coolant_request_status.Data, 'LineWidth',1.5);
xlabel('time (s)','FontSize', 12);
ylabel('coolant flow request','FontSize', 12);