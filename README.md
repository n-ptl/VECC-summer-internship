# Triple-GEM Detector Characterization — VECC

## Overview

This repository contains research work carried out during my summer internship at the Variable Energy Cyclotron Centre (VECC), Kolkata.

The project focused on the experimental characterization of a Triple-GEM (Gas Electron Multiplier) detector using an X-ray source, together with ROOT/CBMROOT-based detector simulation and offline analysis of experimental data.

The work involved detector testing, data acquisition, development of an offline reconstruction chain, and analysis of detector-response observables.

## Experimental Work

The detector was characterized using an X-ray source and a dedicated laboratory setup consisting of the Triple-GEM detector, gas system, high-voltage supply, front-end electronics, and GBT-based data acquisition.

The experimental studies included:

- Electrical quality assessment of GEM foils through leakage-current measurements
- High-voltage divider characterization
- X-ray source linearity studies
- Triple-GEM detector response measurements
- Cluster-charge measurements
- Spatial response studies
- Digitized hit-rate measurements
- Cluster-size measurements at different operating conditions

## Data Analysis & Reconstruction

An offline analysis workflow was developed using ROOT and C++ to process the binary data produced by the detector readout system.

The reconstruction chain included:

- Binary data decoding
- FEB-wise channel-to-pad mapping
- Detector geometry visualization
- Timestamp reconstruction and uplink-wise correction
- ADC-to-charge conversion
- Time-based cluster reconstruction
- Cluster-charge and cluster-size extraction
- Occupancy and timing studies
- Validation of reconstructed detector data

## Simulation Studies

CBMROOT simulation data were studied to become familiar with the MuCh detector geometry, addressing scheme, detector response, and ROOT-based data structures.

The simulation analysis included studies of:

- Particle momentum
- Pseudorapidity
- Azimuthal angle
- Radial distributions
- Detector occupancy
- Module-wise hit distributions

## Results

The high-voltage divider exhibited the expected linear voltage-current behaviour over the investigated range, corresponding to an effective resistance of approximately 2.73 MΩ.

The reconstructed cluster-charge measurements showed a relatively uniform response across the detector segments included in the analysis.

The digitized hit rate and average cluster size were also studied as functions of X-ray tube current at different detector high-voltage settings.

The detector module showed unstable behaviour during the measurements, so a reliable linear detector response with X-ray current could not be established from the available dataset.

## Tools & Technologies

- ROOT
- C++
- CBMROOT
- GEM detector instrumentation
- Experimental data acquisition
- Detector data reconstruction
- Data analysis and visualization

## Internship

**Variable Energy Cyclotron Centre (VECC), Kolkata**

**Research area:** Experimental Particle Physics & Detector Instrumentation

**Supervisor:** Dr. Anand Kumar Dubey
