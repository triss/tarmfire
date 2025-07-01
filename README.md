# TArmFire

Author: Tristan Strange

Outputs a trigger from its fire input when armed. It’s armed by a trigger at its arm input and disarms once fired.

### Requirements

- CMake >= 3.5
- SuperCollider source code

### Building

Clone the project:

    git clone https://github.com/triss/tarmfire
    cd tarmfire
    mkdir build
    cd build

Then, use CMake to configure and build it:
    cmake -DSC_PATH=~/sources/supercollider/ -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=~/.local/share/SuperCollider/Extensions ..
    make && make install

`-DCMAKE_INSTALL_PREFIX` should be the path to your SuperColider Extension directory.

`-DSC_PATH` should be set to the path of your SuperCollider source files.

### Developing

This unit generator was developed with the [SuperCollider cookiecutter](https://github.com/cookiecutter/cookiecutter).
Use the command in `regenerate` to update CMakeLists.txt when you add or remove files from the
project. You don't need to run it if you only change the contents of existing files. You may need to
edit the command if you add, remove, or rename plugins, to match the new plugin paths. Run the
script with `--help` to see all available options.
