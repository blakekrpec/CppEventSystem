This project is an exploration of event driven programming in C++. I recently utilized C#'s built in event support in a Unity project and want to explore what this could look like in C++ using std::function.


Care was taken to make this cross-compile on my Ubuntu, and Windows machines. 

### Ubuntu
I use clangd LSP in nvim, but g++ to compile. So to tell clangd where to find g++ headers, the `.clangd` file in `/config/` of this Project needs to be copied into root of project. The CMakeLists.txt file does this if you are on Linux and pass the flag `-DCMAKE_COPY_CLANGD=ON` (as seen in `scripts/build.sh`). Same for the flag `-DCMAKE_COPY_CLANG_FORMAT=ON` in `scripts/build.sh`. You can remove these flags if you don't want `.clangd` and `.clang-format` copied into porject root on your Linux machine.

#### To build
```
git clone git@github.com:blakekrpec/CppEventSystem.git
```

```
./scripts/build.sh
```

For a clean build:
```
./scripts/build.sh --clean
```

#### To run
```
./build/CppEventSystem
```

### Windows
For Windows, to generate a compile_commands.json (for my nvim clangd LSP) I used Ninja. If you don't care about having a compile_commands.json you should be able to build with out of the box CMake on Windows.

To install Ninja on Windows:

Downlaod latest `ninja-win.zip`:
```
https://github.com/ninja-build/ninja/releases
```

Extract the `.zip` file to a folder, e.g., `C:\Tools\ninja\`. Inside, find `ninja.exa`.

Add `ninja.exe` to `PATH`: Press `Win + R` and type `sysdm.cpl`, press `Enter`

Under `Advanced` tab, find `Environment Variable`, and click it.

Find and select `Path`, then click `Edit`.

Click `New`, then add the path to the folder where `ninja.exe` is (e.g., `C:\Tools\ninja\`)

#### To build

```
git clone git@github.com:blakekrpec/CppEventSystem.git
```

```
./scripts/build.bat
```

For a clean build:
```
./scripts/build.bat --clean
```

#### To run
```
./build/CppEventSystem
```


Click `OK` to close dialogs.

Verify installation: `ninja --version`

