# Developer Menu
## Building

Clone the git submodules:
`git submodule update --init --recursive --depth 1`

Build everything:
`./task.sh`

## Installing
Copy the built executable `dmenu` to somewhere in your path.
Source the `dm.sh` script in your shell to enable the "dm" command.
Set the `DEV_MENU_PATH` environment variable to the directory where you keep all the code.
