%init file for svn check
my_path = mfilename('fullpath');
feature_path = regexp(my_path,'.+(?=\\.+$)','match');
feature_path = feature_path{1};
addpath(feature_path);

BMS_root_path = regexp(my_path,'.+(?=\\.+\\.+$)','match');
BMS_root_path = BMS_root_path{1};

params_path = fullfile(feature_path,'params','soc_params');
run(params_path);
