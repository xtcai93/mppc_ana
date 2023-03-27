# mppcjpAna

An analysis framework for pre-processed data from DT5702. To use it, the raw data must be pre-process by another analysis framework.

# Tutorial
### Setup environment

On `INPAC-cluster`, you can setup Geant4 enviroment with:

```
source  /cvmfs/sft.cern.ch/lcg/views/LCG_101/x86_64-centos7-gcc11-opt/setup.sh
```
### Download and compile the package

```
git clone https://github.com/xtcai93/mppc_ana
cd mppc_ana
mkdir build
cd build
cmake ../
make -j4
```
The executable file `mppcjpAna` can be found in mppc_ana/build
