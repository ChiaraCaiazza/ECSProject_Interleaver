
# PlanAhead Launch Script for Pre-Synthesis Floorplanning, created by Project Navigator

create_project -name interleaver -dir "C:/Users/kia/Dropbox/Progetto_fanucci/xinlix/planAhead_run_2" -part xc7z010clg400-3
set_param project.pinAheadLayout yes
set srcset [get_property srcset [current_run -impl]]
set_property target_constrs_file "interleaver.ucf" [current_fileset -constrset]
set hdlfile [add_files [list {../interleaver/interleaver/src/interleaver.vhd}]]
set_property file_type VHDL $hdlfile
set_property library work $hdlfile
set_property top interleaver $srcset
add_files [list {interleaver.ucf}] -fileset [get_property constrset [current_run]]
open_rtl_design -part xc7z010clg400-3
