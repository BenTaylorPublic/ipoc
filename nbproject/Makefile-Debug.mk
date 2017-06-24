#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=MinGW-Windows
CND_DLIB_EXT=dll
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Color.o \
	${OBJECTDIR}/Conversions.o \
	${OBJECTDIR}/Debug.o \
	${OBJECTDIR}/FileManager.o \
	${OBJECTDIR}/IPOCDrawable.o \
	${OBJECTDIR}/IPOCFont.o \
	${OBJECTDIR}/IPOCFrame.o \
	${OBJECTDIR}/IPOCSettings.o \
	${OBJECTDIR}/IPOCSprite.o \
	${OBJECTDIR}/IPOCText.o \
	${OBJECTDIR}/IPOCTexture.o \
	${OBJECTDIR}/IPOCWindow.o \
	${OBJECTDIR}/InputController.o \
	${OBJECTDIR}/MasterController.o \
	${OBJECTDIR}/OnscreenButton.o \
	${OBJECTDIR}/OnscreenButtonManager.o \
	${OBJECTDIR}/OutputController.o \
	${OBJECTDIR}/Point2D.o \
	${OBJECTDIR}/ProcessController.o \
	${OBJECTDIR}/Storage.o \
	${OBJECTDIR}/ThreadManager.o \
	${OBJECTDIR}/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-L../../SFML-2.4.2/lib -lsfml-audio-d -lsfml-graphics-d -lsfml-main-d -lsfml-system-d -lsfml-window-d

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/ipoc.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/ipoc.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/ipoc ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/Color.o: Color.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../SFML-2.4.2/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Color.o Color.cpp

${OBJECTDIR}/Conversions.o: Conversions.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../SFML-2.4.2/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Conversions.o Conversions.cpp

${OBJECTDIR}/Debug.o: Debug.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../SFML-2.4.2/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Debug.o Debug.cpp

${OBJECTDIR}/FileManager.o: FileManager.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../SFML-2.4.2/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/FileManager.o FileManager.cpp

${OBJECTDIR}/IPOCDrawable.o: IPOCDrawable.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../SFML-2.4.2/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/IPOCDrawable.o IPOCDrawable.cpp

${OBJECTDIR}/IPOCFont.o: IPOCFont.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../SFML-2.4.2/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/IPOCFont.o IPOCFont.cpp

${OBJECTDIR}/IPOCFrame.o: IPOCFrame.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../SFML-2.4.2/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/IPOCFrame.o IPOCFrame.cpp

${OBJECTDIR}/IPOCSettings.o: IPOCSettings.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../SFML-2.4.2/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/IPOCSettings.o IPOCSettings.cpp

${OBJECTDIR}/IPOCSprite.o: IPOCSprite.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../SFML-2.4.2/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/IPOCSprite.o IPOCSprite.cpp

${OBJECTDIR}/IPOCText.o: IPOCText.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../SFML-2.4.2/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/IPOCText.o IPOCText.cpp

${OBJECTDIR}/IPOCTexture.o: IPOCTexture.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../SFML-2.4.2/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/IPOCTexture.o IPOCTexture.cpp

${OBJECTDIR}/IPOCWindow.o: IPOCWindow.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../SFML-2.4.2/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/IPOCWindow.o IPOCWindow.cpp

${OBJECTDIR}/InputController.o: InputController.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../SFML-2.4.2/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/InputController.o InputController.cpp

${OBJECTDIR}/MasterController.o: MasterController.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../SFML-2.4.2/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/MasterController.o MasterController.cpp

${OBJECTDIR}/OnscreenButton.o: OnscreenButton.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../SFML-2.4.2/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/OnscreenButton.o OnscreenButton.cpp

${OBJECTDIR}/OnscreenButtonManager.o: OnscreenButtonManager.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../SFML-2.4.2/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/OnscreenButtonManager.o OnscreenButtonManager.cpp

${OBJECTDIR}/OutputController.o: OutputController.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../SFML-2.4.2/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/OutputController.o OutputController.cpp

${OBJECTDIR}/Point2D.o: Point2D.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../SFML-2.4.2/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Point2D.o Point2D.cpp

${OBJECTDIR}/ProcessController.o: ProcessController.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../SFML-2.4.2/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ProcessController.o ProcessController.cpp

${OBJECTDIR}/Storage.o: Storage.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../SFML-2.4.2/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Storage.o Storage.cpp

${OBJECTDIR}/ThreadManager.o: ThreadManager.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../SFML-2.4.2/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ThreadManager.o ThreadManager.cpp

${OBJECTDIR}/main.o: main.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../SFML-2.4.2/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
