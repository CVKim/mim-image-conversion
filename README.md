# MIM Converter

**MIM Converter** is a high-performance C++ utility designed to batch convert Matrox Imaging Library (MIL) image files (`.mim`) into standard formats (`.bmp` and `.jpg`).

This tool is particularly useful for processing raw images captured with industrial cameras, offering built-in support for Bayer pattern demosaicing (interpolation) and recursive directory scanning.

## Key Features

* **Batch Processing:** Rapid conversion of large datasets defined in a config file.
* **Recursive Scanning:** Automatically traverses subdirectories in the source path.
* **Directory Mirroring:** Recreates the source directory structure in the output location.
* **Bayer Demosaicing:** Supports converting single-channel raw Bayer images to color using various interpolation algorithms (Adaptive, Bilinear, Average, etc.).
* **Dual Output:** Can generate BMP and JPG files simultaneously.
* **Configurable:** Fully driven by an external `.ini` configuration file.

## Prerequisites

To build and run this project, you need the following environment:

* **OS:** Windows 10/11
* **Compiler:** Visual Studio (MSVC) with **C++17** support (or higher).
* **Frameworks:**
    * MFC (Microsoft Foundation Classes)
    * **Matrox Imaging Library (MIL):** You must have MIL installed and licensed on your machine (headers and libraries required).

## Configuration (`mim_converter_config.ini`)

The application is controlled by an INI file. By default, it looks for `mim_converter_config.ini` in the same directory as the executable.

### Configuration Structure

1.  **[MIM2BMP Information]**: Defines the number of conversion jobs.
2.  **[infoN]**: Settings for the N-th job (image processing parameters).
3.  **[PATHN]**: Paths for the N-th job.

### Example INI File

```ini
[MIM2BMP Information]
type count=2

; ================= Job 1 =================
[info1]
; 1: BG, 2: GB, 3: GR, 4: RG
BAYER_ORDER=1
; 1: Enable, 0: Disable
CONVERT_BMP=1
CONVERT_JPG=1
; 1: Mono/Bayer (Requires Demosaicing), 3: Color
CHANNEL_CNT=1
; 0: Adaptive+ColorCorr (Default), 1: Adaptive Fast, 2: Avg 2x2, 3: Bilinear
BayerInterpolation=0

[PATH1]
Source mim path=C:\Data\Raw_Images
Target img path=D:\Data\Converted_Images

; ================= Job 2 =================
[info2]
BAYER_ORDER=4
CONVERT_BMP=0
CONVERT_JPG=1
CHANNEL_CNT=3
BayerInterpolation=0

[PATH2]
Source mim path=.\Input
Target img path=.\Output
