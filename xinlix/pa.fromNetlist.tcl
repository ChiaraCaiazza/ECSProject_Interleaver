
# PlanAhead Launch Script for Post-Synthesis floorplanning, created by Project Navigator

create_project -name interleaver -dir "C:/Users/kia/Dropbox/Progetto_fanucci/xinlix/planAhead_run_3" -part xc7z010clg400-3
set_property design_mode GateLvl [get_property srcset [current_run -impl]]
set_property edif_top_file "C:/Users/kia/Dropbox/Progetto_fanucci/xinlix/interleaver.ngc" [ get_property srcset [ current_run ] ]
add_files -norecurse { {C:/Users/kia/Dropbox/Progetto_fanucci/xinlix} }
set_property target_constrs_file "interleaver.ucf" [current_fileset -constrset]
add_files [list {interleaver.ucf}] -fileset [get_property constrset [current_run]]
link_design
