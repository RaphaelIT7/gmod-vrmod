-- Defines which version of the project generator to use, by default
-- (can be overriden by the environment variable PROJECT_GENERATOR_VERSION)
PROJECT_GENERATOR_VERSION = 3

newoption({
	trigger = "gmcommon",
	description = "Sets the path to the garrysmod_common (https://github.com/danielga/garrysmod_common) directory",
	default = "../garrysmod_common"
})

local gmcommon = assert(_OPTIONS.gmcommon or os.getenv("GARRYSMOD_COMMON"),
	"you didn't provide a path to your garrysmod_common (https://github.com/danielga/garrysmod_common) directory")
include(gmcommon)

local rootDir = ""
local sourcePath = "source/"
if MODULE_DEVELOPMENT then
	rootDir = "../../"
	sourcePath = rootDir .. sourcePath
end

CreateWorkspace({name = "vrmod", abi_compatible = false})
	-- Serverside module (gmsv prefix)
	-- Can define "source_path", where the source files are located
	-- Can define "manual_files", which allows you to manually add files to the project,
	-- instead of automatically including them from the "source_path"
	-- Can also define "abi_compatible", for project specific compatibility
	CreateProject({serverside = false, manual_files = false, source_path = sourcePath:sub(0, -2)})
		symbols "On"
		-- Remove some or all of these includes if they're not needed
		IncludeHelpersExtended()
		--IncludeLuaShared()
		IncludeSDKCommon()
		IncludeSDKTier0()
		IncludeSDKTier1()
		--IncludeSDKTier2()
		--IncludeSDKTier3()
		--IncludeSDKMathlib()
		--IncludeSDKRaytrace()
		--IncludeSDKBitmap()
		--IncludeSDKVTF()
		--IncludeSteamAPI()
		IncludeDetouring()
		IncludeScanning()

		defines("PROJECT_NAME=\"vrmod\"")

		files({
			sourcePath .. "openvr/*.h",
			rootDir .. "README.md",
			rootDir .. ".github/workflows/**.yml",
		})

		vpaths({
			["OpenVR"] = sourcePath .. "openvr/*.h",
			["README"] = rootDir .. "README.md",
			["Workflows"] = rootDir .. ".github/workflows/**.yml",
		})

		filter("system:windows")
			links("D3D11")

		filter("system:windows", "platforms:x86")
			libdirs(rootDir .. "libs/win32")
			links("openvr_api_32")

		filter("system:windows", "platforms:x86_64")
			libdirs(rootDir .. "libs/win64")
			links("openvr_api_64")

		filter({"system:linux", "platforms:x86_64"})
			libdirs(rootDir .. "libs/linux64")
			buildoptions({"-mcx16"})
			links("openvr_api")

		filter({"system:linux", "platforms:x86"})
			libdirs(rootDir .. "libs/linux32")
			links("openvr_api")

		filter({"platforms:x86_64"})
			defines("PLATFORM_64BITS")