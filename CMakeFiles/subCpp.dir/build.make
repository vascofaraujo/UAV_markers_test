# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/vasco/Desktop/CODE/UAV_Fiducial_Markers

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/vasco/Desktop/CODE/UAV_Fiducial_Markers

# Include any dependencies generated for this target.
include CMakeFiles/subCpp.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/subCpp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/subCpp.dir/flags.make

CMakeFiles/subCpp.dir/subCpp.cpp.o: CMakeFiles/subCpp.dir/flags.make
CMakeFiles/subCpp.dir/subCpp.cpp.o: subCpp.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vasco/Desktop/CODE/UAV_Fiducial_Markers/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/subCpp.dir/subCpp.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/subCpp.dir/subCpp.cpp.o -c /home/vasco/Desktop/CODE/UAV_Fiducial_Markers/subCpp.cpp

CMakeFiles/subCpp.dir/subCpp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/subCpp.dir/subCpp.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vasco/Desktop/CODE/UAV_Fiducial_Markers/subCpp.cpp > CMakeFiles/subCpp.dir/subCpp.cpp.i

CMakeFiles/subCpp.dir/subCpp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/subCpp.dir/subCpp.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vasco/Desktop/CODE/UAV_Fiducial_Markers/subCpp.cpp -o CMakeFiles/subCpp.dir/subCpp.cpp.s

CMakeFiles/subCpp.dir/subCpp.cpp.o.requires:

.PHONY : CMakeFiles/subCpp.dir/subCpp.cpp.o.requires

CMakeFiles/subCpp.dir/subCpp.cpp.o.provides: CMakeFiles/subCpp.dir/subCpp.cpp.o.requires
	$(MAKE) -f CMakeFiles/subCpp.dir/build.make CMakeFiles/subCpp.dir/subCpp.cpp.o.provides.build
.PHONY : CMakeFiles/subCpp.dir/subCpp.cpp.o.provides

CMakeFiles/subCpp.dir/subCpp.cpp.o.provides.build: CMakeFiles/subCpp.dir/subCpp.cpp.o


# Object files for target subCpp
subCpp_OBJECTS = \
"CMakeFiles/subCpp.dir/subCpp.cpp.o"

# External object files for target subCpp
subCpp_EXTERNAL_OBJECTS =

subCpp: CMakeFiles/subCpp.dir/subCpp.cpp.o
subCpp: CMakeFiles/subCpp.dir/build.make
subCpp: /usr/local/lib/libopencv_stitching.so.4.5.2
subCpp: /usr/local/lib/libopencv_gapi.so.4.5.2
subCpp: /usr/local/lib/libopencv_superres.so.4.5.2
subCpp: /usr/local/lib/libopencv_ccalib.so.4.5.2
subCpp: /usr/local/lib/libopencv_dnn_objdetect.so.4.5.2
subCpp: /usr/local/lib/libopencv_aruco.so.4.5.2
subCpp: /usr/local/lib/libopencv_dnn_superres.so.4.5.2
subCpp: /usr/local/lib/libopencv_xphoto.so.4.5.2
subCpp: /usr/local/lib/libopencv_wechat_qrcode.so.4.5.2
subCpp: /usr/local/lib/libopencv_reg.so.4.5.2
subCpp: /usr/local/lib/libopencv_bioinspired.so.4.5.2
subCpp: /usr/local/lib/libopencv_img_hash.so.4.5.2
subCpp: /usr/local/lib/libopencv_xobjdetect.so.4.5.2
subCpp: /usr/local/lib/libopencv_quality.so.4.5.2
subCpp: /usr/local/lib/libopencv_bgsegm.so.4.5.2
subCpp: /usr/local/lib/libopencv_rapid.so.4.5.2
subCpp: /usr/local/lib/libopencv_face.so.4.5.2
subCpp: /usr/local/lib/libopencv_line_descriptor.so.4.5.2
subCpp: /usr/local/lib/libopencv_surface_matching.so.4.5.2
subCpp: /usr/local/lib/libopencv_dpm.so.4.5.2
subCpp: /usr/local/lib/libopencv_mcc.so.4.5.2
subCpp: /usr/local/lib/libopencv_freetype.so.4.5.2
subCpp: /usr/local/lib/libopencv_structured_light.so.4.5.2
subCpp: /usr/local/lib/libopencv_hfs.so.4.5.2
subCpp: /usr/local/lib/libopencv_stereo.so.4.5.2
subCpp: /usr/local/lib/libopencv_optflow.so.4.5.2
subCpp: /usr/local/lib/libopencv_saliency.so.4.5.2
subCpp: /usr/local/lib/libopencv_intensity_transform.so.4.5.2
subCpp: /usr/local/lib/libopencv_fuzzy.so.4.5.2
subCpp: /usr/local/lib/libopencv_xfeatures2d.so.4.5.2
subCpp: /usr/local/lib/libopencv_videostab.so.4.5.2
subCpp: /usr/local/lib/libopencv_rgbd.so.4.5.2
subCpp: /usr/local/lib/libopencv_shape.so.4.5.2
subCpp: /usr/local/lib/libopencv_ximgproc.so.4.5.2
subCpp: /usr/local/lib/libopencv_objdetect.so.4.5.2
subCpp: /usr/local/lib/libopencv_phase_unwrapping.so.4.5.2
subCpp: /usr/local/lib/libopencv_tracking.so.4.5.2
subCpp: /usr/local/lib/libopencv_highgui.so.4.5.2
subCpp: /usr/local/lib/libopencv_datasets.so.4.5.2
subCpp: /usr/local/lib/libopencv_text.so.4.5.2
subCpp: /usr/local/lib/libopencv_ml.so.4.5.2
subCpp: /usr/local/lib/libopencv_plot.so.4.5.2
subCpp: /usr/local/lib/libopencv_video.so.4.5.2
subCpp: /usr/local/lib/libopencv_videoio.so.4.5.2
subCpp: /usr/local/lib/libopencv_dnn.so.4.5.2
subCpp: /usr/local/lib/libopencv_photo.so.4.5.2
subCpp: /usr/local/lib/libopencv_imgcodecs.so.4.5.2
subCpp: /usr/local/lib/libopencv_calib3d.so.4.5.2
subCpp: /usr/local/lib/libopencv_features2d.so.4.5.2
subCpp: /usr/local/lib/libopencv_flann.so.4.5.2
subCpp: /usr/local/lib/libopencv_imgproc.so.4.5.2
subCpp: /usr/local/lib/libopencv_core.so.4.5.2
subCpp: CMakeFiles/subCpp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/vasco/Desktop/CODE/UAV_Fiducial_Markers/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable subCpp"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/subCpp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/subCpp.dir/build: subCpp

.PHONY : CMakeFiles/subCpp.dir/build

CMakeFiles/subCpp.dir/requires: CMakeFiles/subCpp.dir/subCpp.cpp.o.requires

.PHONY : CMakeFiles/subCpp.dir/requires

CMakeFiles/subCpp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/subCpp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/subCpp.dir/clean

CMakeFiles/subCpp.dir/depend:
	cd /home/vasco/Desktop/CODE/UAV_Fiducial_Markers && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vasco/Desktop/CODE/UAV_Fiducial_Markers /home/vasco/Desktop/CODE/UAV_Fiducial_Markers /home/vasco/Desktop/CODE/UAV_Fiducial_Markers /home/vasco/Desktop/CODE/UAV_Fiducial_Markers /home/vasco/Desktop/CODE/UAV_Fiducial_Markers/CMakeFiles/subCpp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/subCpp.dir/depend

