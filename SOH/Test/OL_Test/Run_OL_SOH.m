addpath(fullfile(pwd, '..\..\..\', 'SOH'));  
SOH_ini;
step_size = 0.01;
  sim_time  = 200;
  run_time = 0:0.01:sim_time;
  sig_len = length(run_time);
  sample_time = 0.01;
  cell_num = 40;
  
  
  %% Initialize input signals
  SOH_CellSOC.time = run_time';
  SOH_CellSOC.signals.dimensions = cell_num;
  SOH_CellVoltages.time = run_time';
  SOH_CellVoltages.signals.dimensions = cell_num;
  SOH_CellTemp.time = run_time';
  SOH_CellTemp.signals.dimensions = cell_num;
  SOH_ChargingStatus.time = run_time';
  SOH_ChargingStatus.signals.dimensions =1 ;
  SOH_DisChargingStatus.time = run_time';
  SOH_DisChargingStatus.signals.dimensions = 1;
  SOH_PackCurrent.time = run_time';
  SOH_Cfactor.signals.dimensions = cell_num;
  SOH_Cfactor.time = run_time';
  SOH_Main_Contactor.signals.dimensions = 1;
  SOH_Main_Contactor.time = run_time';
  SOH_Charger_Contactor.signals.dimensions = 1;
  SOH_Charger_Contactor.time = run_time';
  SOH_Precharger_Contactor.signals.dimensions = 1;
  SOH_Precharger_Contactor.time = run_time';
  SOH_CB_Cmd.signals.dimensions = cell_num;
  SOH_CB_Cmd.time = run_time';
  
  
   %% Choose test cases based on user input number
 user_choice = ['Please choose the test case number you want to run (1-3) :\n'];

 choice = input(user_choice);

 switch choice
     case 1
        SOH_CellTemp.signals.values =  30+(35-30)*ones( sig_len,cell_num); 
        SOH_CellSOC.signals.values = 60+ 2*ones(sig_len,cell_num);
         [Resis_X, Resis_Y]= meshgrid(bmsc_InternalChgResistX,bmsc_InternalChgResistY);
        VV  = interp2(Resis_X,Resis_Y, bmsc_InternalChgResistZ', SOH_CellTemp.signals.values, SOH_CellSOC.signals.values);
        SOH_PackCurrent.signals.values = 45+5*rand(sig_len,1);
        SOH_CellVoltages.signals.values = zeros(length(VV(:,1)),length(VV(1,:)));
        for i = 2: length(VV)
            SOH_CellVoltages.signals.values(i,:) = SOH_CellVoltages.signals.values(i-1,:)+ 1.01.*VV(i,:).*(SOH_PackCurrent.signals.values(i)-SOH_PackCurrent.signals.values(i-1));
        end
         %3+(3.4-3)*rand(sig_len,cell_num); 
       
        SOH_ChargingStatus.signals.values  = boolean([zeros(51,1);ones(sig_len-51,1)]);
        SOH_DisChargingStatus.signals.values  = boolean(zeros(sig_len,1));
        SOH_Cfactor.signals.values = 0.97 + 0.01*rand(sig_len,cell_num);
        SOH_Main_Contactor.signals.values = boolean(zeros(sig_len,1));
        SOH_Charger_Contactor.signals.values = boolean([zeros(50,1);ones(sig_len-50,1)]);
        SOH_Precharger_Contactor.signals.values = boolean([zeros(20,1);ones(50,1);zeros(sig_len-70,1)]);
        SOH_CB_Cmd.signals.values = boolean(zeros(sig_len,cell_num));
        sim('SOH_OL_Harness.slx');
        save('test_data/test_1.mat');
        
     case 2
        SOH_CellTemp.signals.values =  30+(35-30)*ones( sig_len,cell_num); 
        SOH_CellSOC.signals.values = 60+ 2*ones(sig_len,cell_num);
         [Resis_X, Resis_Y]= meshgrid(bmsc_InternalDischgResistX,bmsc_InternalDischgResistY);
        VV  = interp2(Resis_X,Resis_Y, bmsc_InternalDischgResistZ', SOH_CellTemp.signals.values, SOH_CellSOC.signals.values);
        SOH_PackCurrent.signals.values = 45+5*rand(sig_len,1);
        SOH_CellVoltages.signals.values = zeros(length(VV(:,1)),length(VV(1,:)));
        for i = 2: length(VV)
            SOH_CellVoltages.signals.values(i,:) = SOH_CellVoltages.signals.values(i-1,:)+ VV(i,:)*1.02.*(SOH_PackCurrent.signals.values(i)-SOH_PackCurrent.signals.values(i-1));
        end
         %3+(3.4-3)*rand(sig_len,cell_num); 
       SOH_Cfactor.signals.values = 0.99 + 0.01*rand(sig_len,cell_num);
        SOH_Main_Contactor.signals.values = boolean([zeros(50,1);ones(sig_len-55,1);zeros(5,1)]);
        SOH_Charger_Contactor.signals.values = boolean(zeros(sig_len,1));
        SOH_Precharger_Contactor.signals.values = boolean([zeros(20,1);ones(50,1);zeros(sig_len-70,1)]);
        SOH_CB_Cmd.signals.values = boolean(zeros(sig_len,cell_num));
        SOH_ChargingStatus.signals.values  = boolean(zeros(sig_len,1));
        SOH_DisChargingStatus.signals.values  = boolean([zeros(51,1);ones(sig_len-51,1)]);
  
        sim('SOH_OL_Harness.slx');
        save('test_data/test_2.mat');
        
     case 3
        SOH_CellTemp.signals.values =  30+(35-30)*ones( sig_len,cell_num); 
        SOH_CellSOC.signals.values = 60+ 2*ones(sig_len,cell_num);
         [Resis_X, Resis_Y]= meshgrid(bmsc_InternalDischgResistX,bmsc_InternalDischgResistY);
        VV  = interp2(Resis_X,Resis_Y, bmsc_InternalDischgResistZ', SOH_CellTemp.signals.values, SOH_CellSOC.signals.values);
        SOH_PackCurrent.signals.values = 45+5*rand(sig_len,1);
        SOH_CellVoltages.signals.values = zeros(length(VV(:,1)),length(VV(1,:)));
        for i = 2: length(VV)
            SOH_CellVoltages.signals.values(i,:) = SOH_CellVoltages.signals.values(i-1,:)+ VV(i,:)*1.02.*(SOH_PackCurrent.signals.values(i)-SOH_PackCurrent.signals.values(i-1));
        end
         %3+(3.4-3)*rand(sig_len,cell_num); 
        
        SOH_ChargingStatus.signals.values  = boolean(zeros(sig_len,1));
        SOH_DisChargingStatus.signals.values  = boolean([zeros(50,1);ones(50,1);zeros(50,1);ones(50,1);ones(sig_len-205,1);zeros(5,1)]);
        SOH_Cfactor.signals.values = 0.99 + 0.01*rand(sig_len,cell_num);
        SOH_Main_Contactor.signals.values = boolean([zeros(50,1);ones(50,1);zeros(50,1);ones(50,1);ones(sig_len-205,1);zeros(5,1)]);
        SOH_Charger_Contactor.signals.values = boolean(zeros(sig_len,1));
        SOH_Precharger_Contactor.signals.values = boolean([zeros(20,1);ones(40,1);zeros(70,1);ones(40,1);zeros(sig_len-170,1)]);
        SOH_CB_Cmd.signals.values = boolean(zeros(sig_len,cell_num)); 
        sim('SOH_OL_Harness.slx');
        save('test_data/test_3.mat');
 end
 
figure(1);
subplot(1,2,1);
plot(SOH_Cfactor.time, SOH_Cfactor.signals.values , 'LineWidth',1.5);
xlabel('time (s)','FontSize', 12);
ylabel('Capacity Degradation Factor','FontSize', 12);
subplot(1,2,2);
plot(SOH_Charger_Contactor.time,SOH_Charger_Contactor.signals.values , 'LineWidth',1.5);
xlabel('time (s)','FontSize', 12);
ylabel('Charger Contactor','FontSize', 12);

figure(2);
subplot(1,2,1);
plot(soh_healthindex.Time, soh_healthindex.Data , 'LineWidth',1.5);
ylim([95 100])
xlabel('time (s)','FontSize', 12);
ylabel('SOH R index','FontSize', 12);
subplot(1,2,2);
plot(soh_customer_index.Time,soh_customer_index.Data, 'LineWidth',1.5);
xlabel('time (s)','FontSize', 12);
ylabel('SOH customer index','FontSize', 12);

figure(3);
subplot(1,2,1);
plot(SOH_Cfactor.time, SOH_Cfactor.signals.values , 'LineWidth',1.5);
xlabel('time (s)','FontSize', 12);
ylabel('Capacity Degradation Factor','FontSize', 12);
subplot(1,2,2);
plot(SOH_Main_Contactor.time,SOH_Main_Contactor.signals.values , 'LineWidth',1.5);
xlabel('time (s)','FontSize', 12);
ylabel('Main Contactor','FontSize', 12);

figure(4);
subplot(1,2,1);
plot(soh_healthindex.Time, soh_healthindex.Data , 'LineWidth',1.5);
ylim([95 100])
xlabel('time (s)','FontSize', 12);
ylabel('SOH R index','FontSize', 12);
subplot(1,2,2);
plot(soh_customer_index.Time,min(soh_healthindex.Data,soh_healthindex2.Data), 'LineWidth',1.5);
ylim([95 100])
xlabel('time (s)','FontSize', 12);
ylabel('SOH customer index','FontSize', 12);