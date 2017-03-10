includeexternal ("premake-vs-include.lua")

workspace "PhysicsFS-examples"
    language "C++"
    location "build/%{_ACTION}/%{wks.name}"    
    if _ACTION == "vs2015" then
        toolset "v140_xp"
    end

    

    group "PhysicsFS-examples"    

            
        create_console_project("test-physfs", "src")
            includedirs
            {
                "3rdparty/physfs/include"
            }
            links
            {
                "physfs.lib"
            }
            libdirs
            {
                "3rdparty/physfs/lib/Win32/Release"
            }

        