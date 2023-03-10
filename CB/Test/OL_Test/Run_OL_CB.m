addpath(fullfile(pwd, '..\..\..\', 'CB'));  
CB_ini;
  sim_time  = 30;
  run_time = 0:0.01:sim_time;
  sig_len = length(run_time);
  sample_time = 0.01;
  cell_num = 40;
  
  %% Initialize input signals
  CB_Input_CellSOC.time = run_time';
  CB_Input_CellSOC.signals.dimensions = cell_num;
  CB_Input_CellV.time = run_time';
  CB_Input_CellV.signals.dimensions = cell_num;
  CB_Input_BattMode.time = run_time';
  CB_Input_BattMode.signals.dimensions = 1;
  
  
 %% Choose test cases based on user input number
 user_choice = ['Please choose the test case number you want to run (1-3) :\n'];

 choice = input(user_choice);

 switch choice
     case 1
        % CB_Input_CellV_1 = 3.4*ones(1500,cell_num);
         %CB_Input_CellV_2 = 3.4+0.02*rand( sig_len-1501,cell_num);
          %[CB_Input_CellV_1 ;CB_Input_CellV_1]; 
         CB_Input_CellV.signals.values =  [3.4*ones(1500,cell_num);3.4+ 0.02*rand(sig_len-1500,cell_num)];
         CB_Input_CellSOC.signals.values = [60+ 3*rand(sig_len-1500,cell_num); 63*ones(1000,cell_num);40+ 3*rand(500,cell_num)];
         CB_Input_BattMode.signals.values = uint8([5*ones(500,1);6*ones(sig_len-1000,1);6*ones(500,1)]);
         sim('CB_OL_Harness.slx');
         save('test_data/test_1.mat');
     case 2
         CB_Input_CellV.signals.values =  [3.4*ones(1500,cell_num);3.4+ 0.02*rand(sig_len-1500,cell_num)];
         CB_Input_CellSOC.signals.values = [60+ 3*rand(sig_len-1500,cell_num); 63*ones(1000,cell_num);40+ 3*rand(500,cell_num)];
         CB_Input_BattMode.signals.values = 6*ones(sig_len,1);
          sim('CB_OL_Harness.slx');
          save('test_data/test_2.mat');
     case 3
         CB_Input_CellV.signals.values =  [3.4*ones(1500,cell_num);3.4+ 0.02*rand(sig_len-1500,cell_num)];
         CB_Input_CellSOC.signals.values = [60+ 3*rand(sig_len-1500,cell_num); 63*ones(1000,cell_num);40+ 3*rand(500,cell_num)];
         CB_Input_BattMode.signals.values = [5*ones(500,1);6*ones(sig_len-1000,1);6*ones(500,1)];
         sim('CB_OL_Harness.slx');
         save('test_data/test_3.mat');
 end
 figure(1);
subplot(1,3,1);
plot(CB_Input_CellV.time,CB_Input_CellV.signals.values , 'LineWidth',1.5);
xlabel('time (s)','FontSize', 12);
ylabel('Cell voltage','FontSize', 12);
subplot(1,3,2);
plot(CB_Input_CellSOC.time,CB_Input_CellSOC.signals.values, 'LineWidth',1.5);
xlabel('time (s)','FontSize', 12);
ylabel('cell soc','FontSize', 12);
subplot(1,3,3);
plot( CB_Input_BattMode.time, CB_Input_BattMode.signals.values, 'LineWidth',1.5);
xlabel('time (s)','FontSize', 12);
ylabel('battery mode','FontSize', 12);

figure(2);
subplot(1,2,1);
plot(CB_balancing_cmd.Time, CB_balancing_cmd.Data , 'LineWidth',1.5);
xlabel('time (s)','FontSize', 12);
ylabel('cell balancing command','FontSize', 12);
subplot(1,2,2);
plot(CB_balancing_status.Time,CB_balancing_status.Data, 'LineWidth',1.5);
xlabel('time (s)','FontSize', 12);
ylabel('cell balancing status','FontSize', 12);