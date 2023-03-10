function add_features_to_path
BMS_root_path = fileparts(mfilename('fullpath'));

%to add contactor control
features = {'BMO';
            'BSC';
            'BTC';
            'CB';
            'CC';
            'SOC';
            'VIT_Monitor';
            'SOH';
            'SOP';
            'Amesim_Model'};
        
for i=1:length(features)
    feature_path = fullfile(BMS_root_path,features{i});
    codegen_path = fullfile(BMS_root_path,features{i},'codegen');
    addpath(feature_path);
    if(exist(codegen_path,'dir')==7)
        addpath(codegen_path);
    end
end

%% Initialize Amesim Path
AME_folder = 'C:\Program Files\Simcenter\v1700\Amesim';
setenv('AME', AME_folder);
cur_dir = pwd;
cd('C:\Program Files\Simcenter\v1700\Amesim\scripting\matlab\amesim');
run ameml.m
cd(cur_dir);
clearvars cur_dir