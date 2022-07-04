workspace "vstu-trainee"
	architecture "x64"
	startproject "SetDictionary"

configurations
{
	"Debug",
	"Release"
}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

include "SetDictionary"