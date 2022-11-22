#################
# Appa firmware #
#################

##########
# Config #
##########
project_name = "appa"
keymap = "default"

qmk_repo_url = https://github.com/qmk/qmk_firmware
qmk_version = 0.18.17

current_path = `pwd`
qmk_repo_path = "$(current_path)/`basename $(qmk_repo_url)`"

###########
# Targets #
###########
init: qmk_firmware symlink
	@echo "all done!"

compile:
	@echo "Compiling $(project_name) firmware..."
	cd $(qmk_repo_path); qmk compile -kb "$(project_name)" -km "$(keymap)"
	@echo "done!"

flash:
	@echo "Flashing $(project_name) firmware to keyboard..."
	cd $(qmk_repo_path); qmk flash -kb "$(project_name)" -km "$(keymap)"
	@echo "done!"

symlink:
	@echo "Creating symbolic link for '$(project_name)' firmware..."
	ln -s "$(current_path)/src" "$(qmk_repo_path)/keyboards/$(project_name)"
	@echo "done!"

qmk_firmware:
	@echo "Cloning 'qmk_firmware' repo..."
	@git clone --recursive -b "$(qmk_version)" "$(qmk_repo_url)" "$(qmk_repo_path)"
	@echo "done!"

clean:
	@echo "Cleaning 'qmk_firmware' repo..."
	@rm -fr "$(qmk_repo_path)"
	@echo "done!"

.POSIX:
.PHONY: init clean symlink compile flash
# end
