#!/usr/bin/env bash

source /cvmfs/larsoft.opensciencegrid.org/products/setup

setup git
setup mrb
setup cmake  v3_20_0
setup boost  v1_75_0      -q e20:prof
setup root   v6_26_06b    -q e20:p3913:prof
setup geant4 v4_11_1_p01ba -q e20:prof
setup marley v1_2_0e      -q e20:prof


pushd ${MARLEY}/marley-`marley-config --version`/build
source ${MARLEY}/marley-`marley-config --version`/setup_marley.sh
popd
