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

bootloader.hex:
	@echo "Downloading 'usbasploader' bootloader for 'plaid' keyboards..."
	@wget "https://raw.githubusercontent.com/hsgw/USBaspLoader/plaid/firmware/main.hex" -O bootloader.hex
	@echo "done!"

bootloader: bootloader.hex
	@echo "Preparing '.hex' file..."
	@sed -i 's#:00000001FF##g' "$(qmk_repo_path)/$(project_name)_$(keymap).hex"
	@sed -i "#^\s*$#d" "$(qmk_repo_path)/$(project_name)_$(keymap).hex"
	@cat bootloader.hex >> "$(qmk_repo_path)/$(project_name)_$(keymap).hex"
	@echo "done!"

hex: compile bootloader

compile:
	@echo "Compiling $(project_name) firmware..."
	cd $(qmk_repo_path); qmk compile -kb "$(project_name)" -km "$(keymap)"
	@echo "done!"

flash: hex
	@echo "Flashing $(project_name) firmware to keyboard..."
	cd $(qmk_repo_path); qmk flash -kb "$(project_name)" -km "$(keymap)"
	@echo "done!"

symlink:
	@echo "Creating symbolic link for '$(project_name)' firmware..."
	ln -s "$(current_path)/src" "$(qmk_repo_path)/keyboards/$(project_name)"
	@echo "done!"

check_dependencies:
	@echo "Checking project dependencies..."
	@if [ -z "$(shell which git)" ]; then echo "Please install the 'git' package!"; echo "Run 'sudo apt install git' if you are in a Debian based distro."; exit 1; fi
	@if [ -z "$(shell which qmk)" ]; then echo "Please install the 'qmk' package!"; echo "Run 'python3 -m pip install --user qmk'."; exit 1; fi
	@echo "done!";

qmk_firmware:
	@echo "Cloning 'qmk_firmware' repo..."
	@git clone --recursive -b "$(qmk_version)" "$(qmk_repo_url)" "$(qmk_repo_path)"
	@echo "done!"

clean:
	@echo "Cleaning 'qmk_firmware' repo..."
	@rm -fr "$(qmk_repo_path)"
	@echo "done!"

.POSIX:
.PHONY: init clean check_dependencies symlink compile flash
# end
