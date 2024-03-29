# MAKEFILE_PATH   := $(abspath $(lastword $(MAKEFILE_LIST)))
MAKEFILE_PATH   := $(lastword $(MAKEFILE_LIST))
TOOL_INST       := $(shell taste-config --prefix)
OUTDIR          := $(dir $(MAKEFILE_PATH))
TASTE_SHARED_TYPES?=${HOME}/.local/share/QtProject/QtCreator/shared_types
ASN1_FILES      := ../COM-N7SPACE-AFECHWAS.asn ../COM-N7SPACE-HWAS.asn ../COM-N7SPACE-LIDAR.asn ../COM-N7SPACE-MP6500.asn ../COM-N7SPACE-PIOHWAS.asn ../COM-N7SPACE-PROPULSION.asn ../COM-N7SPACE-SUNSENSOR.asn ../COM-N7SPACE-TFLUNA.asn ../COM-N7SPACE-UARTHWAS.asn ../DemoSat2.asn ${TOOL_INST}/share/taste-types/taste-types.asn  system.asn
CP_FILES        :=       # Context parameters
DATAVIEW_PATH   := ${OUTDIR}/dataview
DATAVIEW_UNIQ   := ${DATAVIEW_PATH}/dataview-uniq.asn
DATAVIEW_ACN    := ${DATAVIEW_PATH}/dataview-uniq.acn
DATAVIEW_AADLV1 := ${DATAVIEW_PATH}/dataview_aadlv1.aadl
DATAVIEW_AADLV2 := ${DATAVIEW_PATH}/dataview_aadlv2.aadl
#TASTE_SHARED_TYPES?=${TOOL_INST}/share/SharedTypes  # Ellidiss only

# Project cache folder is used to speed up all ASN.1-related processing
export PROJECT_CACHE=${HOME}/.taste_AST_cache
all:	build-default


# Check that all runtimes used in the system are installed
check_targets:
	$(MAKE) -C build -f Makefile.taste check_targets

# Generate the language-specific data view needed before editing user code
dataview:	dataview/C/built dataview/Ada/built
	# Copy the dataview to SDL/SEDS function AfecHwasDriver (no context parameters)
	cp -u ${DATAVIEW_UNIQ} afechwasdriver/SDL/src
	# Compute MD5 of the dataview, needed to decide if code needs to be re-generated
	md5sum -c "afechwasdriver/SDL/src/dataview.md5"  &> /dev/null || md5sum  "afechwasdriver/SDL/src/dataview-uniq.asn" >  "afechwasdriver/SDL/src/dataview.md5"
	# Copy the dataview to SDL/SEDS function LidarDriver (no context parameters)
	cp -u ${DATAVIEW_UNIQ} lidardriver/SDL/src
	# Compute MD5 of the dataview, needed to decide if code needs to be re-generated
	md5sum -c "lidardriver/SDL/src/dataview.md5"  &> /dev/null || md5sum  "lidardriver/SDL/src/dataview-uniq.asn" >  "lidardriver/SDL/src/dataview.md5"
	# Copy the dataview to SDL/SEDS function MP6500Driver (no context parameters)
	cp -u ${DATAVIEW_UNIQ} mp6500driver/SDL/src
	# Compute MD5 of the dataview, needed to decide if code needs to be re-generated
	md5sum -c "mp6500driver/SDL/src/dataview.md5"  &> /dev/null || md5sum  "mp6500driver/SDL/src/dataview-uniq.asn" >  "mp6500driver/SDL/src/dataview.md5"
	# Copy the dataview to SDL/SEDS function PioHwasDriver (no context parameters)
	cp -u ${DATAVIEW_UNIQ} piohwasdriver/SDL/src
	# Compute MD5 of the dataview, needed to decide if code needs to be re-generated
	md5sum -c "piohwasdriver/SDL/src/dataview.md5"  &> /dev/null || md5sum  "piohwasdriver/SDL/src/dataview-uniq.asn" >  "piohwasdriver/SDL/src/dataview.md5"
	# Copy the dataview to SDL/SEDS function PropulsionDriver (no context parameters)
	cp -u ${DATAVIEW_UNIQ} propulsiondriver/SDL/src
	# Compute MD5 of the dataview, needed to decide if code needs to be re-generated
	md5sum -c "propulsiondriver/SDL/src/dataview.md5"  &> /dev/null || md5sum  "propulsiondriver/SDL/src/dataview-uniq.asn" >  "propulsiondriver/SDL/src/dataview.md5"
	# Copy the dataview to SDL/SEDS function SunSensorDriver (no context parameters)
	cp -u ${DATAVIEW_UNIQ} sunsensordriver/SDL/src
	# Compute MD5 of the dataview, needed to decide if code needs to be re-generated
	md5sum -c "sunsensordriver/SDL/src/dataview.md5"  &> /dev/null || md5sum  "sunsensordriver/SDL/src/dataview-uniq.asn" >  "sunsensordriver/SDL/src/dataview.md5"
	# Copy the dataview to SDL/SEDS function TfLunaDriver (no context parameters)
	cp -u ${DATAVIEW_UNIQ} tflunadriver/SDL/src
	# Compute MD5 of the dataview, needed to decide if code needs to be re-generated
	md5sum -c "tflunadriver/SDL/src/dataview.md5"  &> /dev/null || md5sum  "tflunadriver/SDL/src/dataview-uniq.asn" >  "tflunadriver/SDL/src/dataview.md5"
	# Copy the dataview to SDL/SEDS function UartHwasDriver (no context parameters)
	cp -u ${DATAVIEW_UNIQ} uarthwasdriver/SDL/src
	# Compute MD5 of the dataview, needed to decide if code needs to be re-generated
	md5sum -c "uarthwasdriver/SDL/src/dataview.md5"  &> /dev/null || md5sum  "uarthwasdriver/SDL/src/dataview-uniq.asn" >  "uarthwasdriver/SDL/src/dataview.md5"

# Generate the complete dataview, including Python bindings if there is a GUI
${DATAVIEW_PATH}/built:	dataview dataview/Python/built
	touch $@

# Build based on the deployment view
build-default:	aadl2glueC build/system_config.h ${DATAVIEW_PATH}/built build/deploymentview_final/Makefile
	$(MAKE) -j -C build -f Makefile.taste

# Execute the generated binaries (used in Space Creator when using the Run button)
run: # Space creator will always build before, so no need to depend on build-default
	$(MAKE) -j -C build -f Makefile.taste run

# Run the Concurrency View analysis tool (cheddar/marzhin)
run_cv: build/ConcurrencyView.aadl
	TASTECV --load $^

# The Concurrency View needed by Cheddar is the concatenation of system.aadl and ocarina_components.aadl
build/ConcurrencyView.aadl:	build/system.aadl
	cat $^ $(shell taste-config --prefix)/share/ocarina/AADLv2/ocarina_components.aadl > $@

# Rule to invoke Ocarina (generation of POHI middleware code)
build/deploymentview_final/Makefile:	build/main.aadl ${DATAVIEW_AADLV2}
	$(MAKE) -C build -f Makefile.taste ocarina

# Optionally manage SQL Database (run taste-create-database to enable)
sql_db/DV.py:
	mkdir -p sql_db && touch $@

# Create dataview-uniq.asn by concatenating all asn1 input files
${DATAVIEW_UNIQ}:	${ASN1_FILES}
	mkdir -p ${PROJECT_CACHE} && mkdir -p ${DATAVIEW_PATH}
	sed -e '$$s/$$/\n/' -s $^ > $@

# Create dataview-uniq.acn by concatenating all input files
${DATAVIEW_ACN}:	../COM-N7SPACE-AFECHWAS.acn ../COM-N7SPACE-HWAS.acn ../COM-N7SPACE-LIDAR.acn ../COM-N7SPACE-MP6500.acn ../COM-N7SPACE-PIOHWAS.acn ../COM-N7SPACE-PROPULSION.acn ../COM-N7SPACE-SUNSENSOR.acn ../COM-N7SPACE-TFLUNA.acn ../COM-N7SPACE-UARTHWAS.acn ../DemoSat2.acn
	mkdir -p ${DATAVIEW_PATH}
	sed -e '$$s/$$/\n/' -s $^ > $@

# system_config.h is used to filter out non-needed ASN.1 encoder/decoders
build/system_config.h:	$(wildcard */*/wrappers/*_system_config.h)
	cat $^ > $@

#  Call DMT/aadl2glueC to generate glue code from the mini-cv.aadl files
aadl2glueC:	afechwasdriver/SDL/wrappers/aadl2glueC_built asw_timer_manager/Timer_Manager/wrappers/aadl2glueC_built egse/GUI/wrappers/aadl2glueC_built hwas/C/wrappers/aadl2glueC_built interruptproxy/C/wrappers/aadl2glueC_built lidardriver/SDL/wrappers/aadl2glueC_built manager/C/wrappers/aadl2glueC_built mp6500driver/SDL/wrappers/aadl2glueC_built objectdetector/C/wrappers/aadl2glueC_built piohwasdriver/SDL/wrappers/aadl2glueC_built propulsiondriver/SDL/wrappers/aadl2glueC_built sunsensordriver/SDL/wrappers/aadl2glueC_built sunsensorproxy/C/wrappers/aadl2glueC_built tflunadriver/SDL/wrappers/aadl2glueC_built uarthwasdriver/SDL/wrappers/aadl2glueC_built

# Build dataview.aadl in AADLv1 format, used by DMT to generate glue code
${DATAVIEW_AADLV1}: ${DATAVIEW_UNIQ}
	asn2aadlPlus  $< $@

# Build dataview.aadl in AADLv2 format, used by Ocarina to generate glue code
${DATAVIEW_AADLV2}: ${DATAVIEW_UNIQ}
	asn2aadlPlus --aadlv2  $< $@

afechwasdriver/SDL/wrappers/aadl2glueC_built: afechwasdriver/SDL/wrappers/afechwasdriver_mini_cv.aadl ${DATAVIEW_AADLV1}
	aadl2glueC -allboards -o $(dir $@) $^
	touch $@

asw_timer_manager/Timer_Manager/wrappers/aadl2glueC_built: asw_timer_manager/Timer_Manager/wrappers/asw_timer_manager_mini_cv.aadl ${DATAVIEW_AADLV1}
	aadl2glueC -allboards -o $(dir $@) $^
	touch $@

egse/GUI/wrappers/aadl2glueC_built: egse/GUI/wrappers/egse_mini_cv.aadl ${DATAVIEW_AADLV1}
	aadl2glueC -allboards -o $(dir $@) $^
	touch $@

hwas/C/wrappers/aadl2glueC_built: hwas/C/wrappers/hwas_mini_cv.aadl ${DATAVIEW_AADLV1}
	aadl2glueC -allboards -o $(dir $@) $^
	touch $@

interruptproxy/C/wrappers/aadl2glueC_built: interruptproxy/C/wrappers/interruptproxy_mini_cv.aadl ${DATAVIEW_AADLV1}
	aadl2glueC -allboards -o $(dir $@) $^
	touch $@

lidardriver/SDL/wrappers/aadl2glueC_built: lidardriver/SDL/wrappers/lidardriver_mini_cv.aadl ${DATAVIEW_AADLV1}
	aadl2glueC -allboards -o $(dir $@) $^
	touch $@

manager/C/wrappers/aadl2glueC_built: manager/C/wrappers/manager_mini_cv.aadl ${DATAVIEW_AADLV1}
	aadl2glueC -allboards -o $(dir $@) $^
	touch $@

mp6500driver/SDL/wrappers/aadl2glueC_built: mp6500driver/SDL/wrappers/mp6500driver_mini_cv.aadl ${DATAVIEW_AADLV1}
	aadl2glueC -allboards -o $(dir $@) $^
	touch $@

objectdetector/C/wrappers/aadl2glueC_built: objectdetector/C/wrappers/objectdetector_mini_cv.aadl ${DATAVIEW_AADLV1}
	aadl2glueC -allboards -o $(dir $@) $^
	touch $@

piohwasdriver/SDL/wrappers/aadl2glueC_built: piohwasdriver/SDL/wrappers/piohwasdriver_mini_cv.aadl ${DATAVIEW_AADLV1}
	aadl2glueC -allboards -o $(dir $@) $^
	touch $@

propulsiondriver/SDL/wrappers/aadl2glueC_built: propulsiondriver/SDL/wrappers/propulsiondriver_mini_cv.aadl ${DATAVIEW_AADLV1}
	aadl2glueC -allboards -o $(dir $@) $^
	touch $@

sunsensordriver/SDL/wrappers/aadl2glueC_built: sunsensordriver/SDL/wrappers/sunsensordriver_mini_cv.aadl ${DATAVIEW_AADLV1}
	aadl2glueC -allboards -o $(dir $@) $^
	touch $@

sunsensorproxy/C/wrappers/aadl2glueC_built: sunsensorproxy/C/wrappers/sunsensorproxy_mini_cv.aadl ${DATAVIEW_AADLV1}
	aadl2glueC -allboards -o $(dir $@) $^
	touch $@

tflunadriver/SDL/wrappers/aadl2glueC_built: tflunadriver/SDL/wrappers/tflunadriver_mini_cv.aadl ${DATAVIEW_AADLV1}
	aadl2glueC -allboards -o $(dir $@) $^
	touch $@

uarthwasdriver/SDL/wrappers/aadl2glueC_built: uarthwasdriver/SDL/wrappers/uarthwasdriver_mini_cv.aadl ${DATAVIEW_AADLV1}
	aadl2glueC -allboards -o $(dir $@) $^
	touch $@


# Compile the ASN.1 models in C
dataview/C/built: ${DATAVIEW_UNIQ} ${DATAVIEW_ACN} ${CP_FILES}
	mkdir -p $(dir $@)
	# asn2dataModel does not take the ACN files, and only calls asn1scc
	# asn2dataModel -o $(dir $@) -toC ${DATAVIEW_UNIQ} ${DATAVIEW_ACN}
	asn1scc -typePrefix asn1Scc ${ASN1SCC_FLAGS} -renamePolicy 3 -equal -fp AUTO -o $(dir $@) -c -uPER -ACN $^
	cp ${TOOL_INST}/share/AutoGUI/debug_messages.? dataview/C
	cp ${TOOL_INST}/share/AutoGUI/timeInMS.? dataview/C
	#cd dataview/C && msgPrinter ../dataview-uniq.asn  (disabled: this is not used anywhere)
	cd dataview/C && msgPrinterASN1 ../dataview-uniq.asn
	touch $@

# Compile the ASN.1 models in Python for the autogenerated GUIs
dataview/Python/built:	dataview/C/built egse/GUI/wrappers/aadl2glueC_built sql_db/DV.py
	mkdir -p $(dir $@)
	asn2dataModel -o $(dir $@) -toPython ${DATAVIEW_UNIQ}
	$(MAKE) -C dataview/Python -f Makefile.python
	cp dataview/Python/* egse/GUI/wrappers/python
	cp dataview/C/timeInMS.[ch] dataview/C/debug_messages.c egse/GUI/wrappers/python
	cd egse/GUI/wrappers/python && \
	   gcc -g -fPIC -c  gui_api.c ../../src/queue_manager.c timeInMS.c debug_messages.c -I. -I../../src && \
	   gcc -g -shared -o PythonAccess.so gui_api.o queue_manager.o timeInMS.o debug_messages.o -lrt
	mkdir -p binaries/egse_GUI
	cp -f egse/GUI/wrappers/python/* binaries/egse_GUI
	cp -f egse/GUI/wrappers/*.py binaries/egse_GUI
	cp -f egse/GUI/wrappers/*.ui binaries/egse_GUI
	echo "errCodes = \\" >> binaries/egse_GUI/datamodel.py
	taste-asn1-errCodes binaries/egse_GUI/dataview-uniq.h >> binaries/egse_GUI/datamodel.py
	if [ -f sql_db/db.info ]; then cd binaries/egse_GUI && ln -fs ../../sql_db; fi
	#  Interface view must be placed in the gui folder to allow replaying MSCs
	cp -u ../InterfaceView.aadl binaries/egse_GUI
	touch $@

dataview/Ada/built: ${DATAVIEW_UNIQ} ${CP_FILES}
	mkdir -p $(dir $@)
	asn2dataModel -allboards -o $(dir $@) -toAda $^
	touch $@
	cd dataview/Ada && rm -f gnat.cfg GPS_project.gpr IgnoredExaminerWarnings.wrn runSpark.sh

clean:
	rm -rf binaries dataview
	$(MAKE) -C build -f Makefile.taste clean

.PHONY: clean simu compile-all-linux function-instances-linux function-types-linux build-default dataview build-rtems-ada dataview build/modelchecking modelchecking/subtypes/$(SUBTYPE) obs-to-if aadl-to-if asn-to-if $(PROPERTIES_CONFIG) run_cv

