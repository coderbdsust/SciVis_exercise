# Exercise 1 - Stereo

## folder structure

All exercises are independent of each other.

    sci-vis-exercises
        |- build        --> solutions, libs, binaries will be build in this folder
        |- 0-intro
        |- 1-stereo		--> source code of recent exercise
        |- ...
        |- cgv          --> clone of cgv framework repository (you can also rename it to framework)
        |- data 	    --> example data like obj-files


## work-flow for windows

### optional: set up cgv framework

You can skip this step, if you already used the framework for the previous task.

- clone the [cgv framework](https://github.com/sgumhold/cgv.git)
- run *cgv/define_windows_sdk.bat* and select your Windows SDK
- drag *build* directory onto *cgv/define_system_variables.bat* and chose your Visual Studio version from the options under *automatic mode* (for VS2019 use option *i*)


#### create VS solution and compile

- pull recent develop branch from cgv framework (exercise tested with commit e5c086a6d496c2)
- drag *scivis-stereo.pj*-file onto *cgv/bin/generate_makefiles.bat*
- start solution from *build/* directory (e.g. *build/vs141/scivis-stereo/scivis-stereo.sln*) if not started automatically
- in Visual Studio: build solution either as *Debug DLL* or *Release DLL*
	- for loading meshes the Release DLL is the preferred option since it will take very long to load it in Debug mode


### known issues

- for VS2017 either change *Windows SDK-version* in project properties or install Windows SDK-version 10.0.17134.0