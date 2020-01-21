
project (AT)

link_libraries(sdl2::sdl2 sdl2_mixer::sdl2_mixer sdl2_image::sdl2_image sdl2_ttf::sdl2_ttf)

add_subdirectory (TeakLibW)
add_subdirectory (SBLib)
add_subdirectory (SSE)

include_directories(${PROJECT_SOURCE_DIR})

if(MSVC)
    add_compile_options("/Zc:forScope-")
else()
    add_compile_options("-fno-for-scope")
endif()

file(GLOB HDRS CONFIGURE_DEPENDS *.h)
# Add source to this project's executable.
add_executable (AT ${HDRS}
    Buero.cpp
    City.cpp
    DataTabl.cpp
    Route.cpp
    Tips.cpp
    Abend.cpp
    AirportView.cpp
    ArabAir.cpp
    Askbrick.cpp
    AtNet.cpp
    Aufsicht.cpp
    Auftrag.cpp
    Bank.cpp
    Block.cpp
    Brick.cpp
    Checkup.cpp
    Colorfx.cpp
    Credits.cpp
    DeltaVid.cpp
    Designer.cpp
    Dialog.cpp
    DutyFree.cpp
    Editor.cpp
    Fracht.cpp
    Gameframe.cpp
    Global.cpp
    Globe.cpp
    HalldiskMenu.cpp
    HLine.cpp
    Init.cpp
    Insel.cpp
    Intro.cpp
    Kiosk.cpp
    Klacker.cpp
    Laptop.cpp
    Lastmin.cpp
    Mainfrm.cpp
    Makler.cpp
    Misc.cpp
    Museum.cpp
    Nasa.cpp
    NewgamePopup.cpp
    Options.cpp
    Outro.cpp
    Person.cpp
    Personal.cpp
    Planer.cpp
    Planetyp.cpp
    PlanProp.cpp
    Player.cpp
    PNet.cpp
    Protect.cpp
    reise.cpp
    Ricks.cpp
    RouteBox.cpp
    Rushmore.cpp
    sabotage.cpp
    SBBM.cpp
    Schedule.cpp
    Security.cpp
    SecurityManager.cpp
    Sim.cpp
    Smackprs.cpp
    Sound.cpp
    Statistk.cpp
    StdAfx.cpp
    Stdraum.cpp
    Synthese.cpp
    Tafel.cpp
    Takeoff.cpp
    Talker.cpp
    Titlepopup.cpp
    WeltAll.cpp
    Werbung.cpp
    Werkstat.cpp
    World.cpp
    Res/Script2.rc
)

if(NOT ${CMAKE_VERSION} VERSION_LESS "3.16.0")
    target_precompile_headers(AT PUBLIC Stdafx.h)
endif()

target_link_libraries(AT
    TeakLibW
    SSE
    SBLib
    libsmacker
    enet
    ${ws2_32_LIBRARY}
    ${Winmm_LIBRARY}
    ws2_32
    Winmm)
