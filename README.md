This project is an exploration of event driven programming in C++. I recently utilized C#'s built in event support in a Unity project and wanted to explore what this could look like in C++ using std::function.


Care was taken to make this cross-compile on my Ubuntu, and Windows machines. 

### Ubuntu

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
For Windows, to generate a compile_commands.json (for my nvim clangd LSP) I used Ninja. If you don't care about having a compile_commands.json, skip the Install Ninja section as you should be able to build with out of the box CMake on Windows. Also will need to remove the -DCMAKE_EXPORT_COMPILE_COMMANDS flag from CMakeLists.txt.

#### Install Ninja (Not Required):

Download latest `ninja-win.zip`:
```
https://github.com/ninja-build/ninja/releases
```

Extract the `.zip` file to a folder, e.g., `C:\Tools\ninja\`. Inside, find `ninja.exe`.

Add `ninja.exe` to `PATH`: Press `Win + R` and type `sysdm.cpl`, press `Enter`

Under `Advanced` tab, find `Environment Variable`, and click it.

Find and select `Path`, then click `Edit`.

Click `New`, then add the path to the folder where `ninja.exe` is (e.g., `C:\Tools\ninja\`)

Click `OK` to close dialogs.

Verify installation: `ninja --version`

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




