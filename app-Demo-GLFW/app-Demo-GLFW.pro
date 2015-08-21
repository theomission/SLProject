##############################################################################
#  File:      app-Demo-GLFW.pro
#  Purpose:   QMake project definition file for demo application with GLFW
#  Author:    Marcus Hudritsch
#  Date:      August 2015
#  Copyright: Marcus Hudritsch, Switzerland
#             THIS SOFTWARE IS PROVIDED FOR EDUCATIONAL PURPOSE ONLY AND
#             WITHOUT ANY WARRANTIES WHETHER EXPRESSED OR IMPLIED.
##############################################################################

TEMPLATE = app
TARGET = app-Demo-GLFW

CONFIG += desktop
CONFIG += console
CONFIG += app_bundle
CONFIG -= qt
CONFIG += glfw
CONFIG += warn_off

DEFINES += "SL_STARTSCENE=cmdSceneRevolver"

include(../SLProjectCommon.pro)

SOURCES += \
    source/glfwMain.cpp


	   