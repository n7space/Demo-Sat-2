# SDL
#Taste::Startup_Priority 1
SEDS_CONVERTER?=spacecreator.AppImage --sedsconverter
OPENGEODE?=opengeode
VISUAL?=kate

all: compile-linux

clean:
	rm -rf obj

edit:
	cd src && $(OPENGEODE) system_structure.pr afechwasdriver.pr

sdl-to-if:
	cd src &&\
	   sdl2if --output-dir ../../../build/modelchecking  ../src/afechwasdriver.pr ../src/system_structure.pr

# Ada
generate-code:
	mkdir -p code && cd code && \
	   $(OPENGEODE) --taste --toAda ../src/afechwasdriver.pr ../src/system_structure.pr && \
	   mv *.gpr ..

compile-linux: generate-code
	   CODE_PATH=code ADA_INCLUDE_PATH=../../../dataview/Ada gprbuild -p -P afechwasdriver_ada.gpr

