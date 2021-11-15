# Scientific Visualization 2021

SciVis - scientific visualization with CGV framework

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

### Prerequisites

What things you need to install to run project

```
Windows 10
Visual Studio 2019 with Windows SDK Framework
```

### Installing

* Initial system variable setup - Run the `bat` file from the directory `framework\define_windows_sdk.bat`. Press any key, it will choose the latest version.

* Create the `build` folder in root directory of the project.

* Now drag the build folder to the file `framework\define_system_variables.bat`, press `i`

* Generate visual studio solution of your project - Drag the `<FileName>.pj` to the `framework\bin\generate_makefiles.bat`



## Open & Run the Project

* Goto `build` folder created by you, you will find a similar folder like `vs[Random Number]`, `Example: vs142`

* In the folder `vs[Random Number]` you will get the similar project folder (like the root drectory) where you will get the `.sln`
file which can be import as project in visual studio **

* More information about configuration is available on `howToBuild_(fromCG2).pdf`

## Versioning

We use `@Git` for versioning.

## Authors

* [Prof. Dr. rer. nat. Stefan Gumhold](https://tu-dresden.de/ing/informatik/smt/cgv/die-professur/inhaber-in "Prof. Dr. rer. nat. Stefan Gumhold's Profile") - *Initial work*
* [Biswajit Debnath](https://www.linkedin.com/in/coderbd/ "Biswajit Debnath's LinkedIn Profile") - *Assignment work*

## License & Documentation

This project is licensed under the `https://wwwpub.zih.tu-dresden.de/~gumhold/cgv/html/index.html`
