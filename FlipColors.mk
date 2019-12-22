##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=FlipColors
ConfigurationName      :=Debug
WorkspacePath          := "C:\Users\Darth\Documents\Workspaces\CodeLite\GitHubWorkspace"
ProjectPath            := "C:\Users\Darth\Documents\Workspaces\CodeLite\GitHubWorkspace\FlipColors"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Darth
Date                   :=11/12/2019
CodeLitePath           :="C:\Program Files\CodeLite"
LinkerName             :=C:/MinGW-2019/bin/g++.exe
SharedObjectLinkerName :=C:/MinGW-2019/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=$(PreprocessorSwitch)UNICODE $(PreprocessorSwitch)_UNICODE 
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="FlipColors.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := $(shell mywx-config --rescomp)
RcCompilerName         :=C:/MinGW-2019/bin/windres.exe
LinkOptions            :=  $(shell mywx-config --libs) $(shell mysdl-config --libs) -mwindows -static-libgcc -static-libstdc++ -lSDL -lSDL_image -lpython37
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)C:/myLibs/SDL_image-1.2.12/include $(IncludeSwitch)C:/Python37-32/include 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)C:/myLibs/SDL_image-1.2.12/lib/x86 $(LibraryPathSwitch)C:/Python37-32/libs 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/MinGW-2019/bin/ar.exe rcu
CXX      := C:/MinGW-2019/bin/g++.exe
CC       := C:/MinGW-2019/bin/gcc.exe
CXXFLAGS :=  -g -O0 -std=c++11 -Wall $(shell mywx-config --cflags) $(shell mysdl-config --cflags) $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/MinGW-2019/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
PATH:=.;../lib;$PATH
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/MainDialog.cpp$(ObjectSuffix) $(IntermediateDirectory)/MainGameArea.cpp$(ObjectSuffix) $(IntermediateDirectory)/MyContext.cpp$(ObjectSuffix) $(IntermediateDirectory)/Sprite.cpp$(ObjectSuffix) $(IntermediateDirectory)/InGameContext.cpp$(ObjectSuffix) $(IntermediateDirectory)/Utils.cpp$(ObjectSuffix) $(IntermediateDirectory)/Graphics.cpp$(ObjectSuffix) $(IntermediateDirectory)/Background.cpp$(ObjectSuffix) $(IntermediateDirectory)/GamePlay.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/AI.cpp$(ObjectSuffix) $(IntermediateDirectory)/PassDialog.cpp$(ObjectSuffix) $(IntermediateDirectory)/MyLog.cpp$(ObjectSuffix) $(IntermediateDirectory)/LogFile.cpp$(ObjectSuffix) $(IntermediateDirectory)/wxformbuilder.cpp$(ObjectSuffix) $(IntermediateDirectory)/LicensesDialog.cpp$(ObjectSuffix) $(IntermediateDirectory)/BSDLicenseDialog.cpp$(ObjectSuffix) $(IntermediateDirectory)/win_resources.rc$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Darth/Documents/Workspaces/CodeLite/GitHubWorkspace/FlipColors/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM "main.cpp"

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) "main.cpp"

$(IntermediateDirectory)/MainDialog.cpp$(ObjectSuffix): MainDialog.cpp $(IntermediateDirectory)/MainDialog.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Darth/Documents/Workspaces/CodeLite/GitHubWorkspace/FlipColors/MainDialog.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/MainDialog.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/MainDialog.cpp$(DependSuffix): MainDialog.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/MainDialog.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/MainDialog.cpp$(DependSuffix) -MM "MainDialog.cpp"

$(IntermediateDirectory)/MainDialog.cpp$(PreprocessSuffix): MainDialog.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/MainDialog.cpp$(PreprocessSuffix) "MainDialog.cpp"

$(IntermediateDirectory)/MainGameArea.cpp$(ObjectSuffix): MainGameArea.cpp $(IntermediateDirectory)/MainGameArea.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Darth/Documents/Workspaces/CodeLite/GitHubWorkspace/FlipColors/MainGameArea.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/MainGameArea.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/MainGameArea.cpp$(DependSuffix): MainGameArea.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/MainGameArea.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/MainGameArea.cpp$(DependSuffix) -MM "MainGameArea.cpp"

$(IntermediateDirectory)/MainGameArea.cpp$(PreprocessSuffix): MainGameArea.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/MainGameArea.cpp$(PreprocessSuffix) "MainGameArea.cpp"

$(IntermediateDirectory)/MyContext.cpp$(ObjectSuffix): MyContext.cpp $(IntermediateDirectory)/MyContext.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Darth/Documents/Workspaces/CodeLite/GitHubWorkspace/FlipColors/MyContext.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/MyContext.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/MyContext.cpp$(DependSuffix): MyContext.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/MyContext.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/MyContext.cpp$(DependSuffix) -MM "MyContext.cpp"

$(IntermediateDirectory)/MyContext.cpp$(PreprocessSuffix): MyContext.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/MyContext.cpp$(PreprocessSuffix) "MyContext.cpp"

$(IntermediateDirectory)/Sprite.cpp$(ObjectSuffix): Sprite.cpp $(IntermediateDirectory)/Sprite.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Darth/Documents/Workspaces/CodeLite/GitHubWorkspace/FlipColors/Sprite.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Sprite.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Sprite.cpp$(DependSuffix): Sprite.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Sprite.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Sprite.cpp$(DependSuffix) -MM "Sprite.cpp"

$(IntermediateDirectory)/Sprite.cpp$(PreprocessSuffix): Sprite.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Sprite.cpp$(PreprocessSuffix) "Sprite.cpp"

$(IntermediateDirectory)/InGameContext.cpp$(ObjectSuffix): InGameContext.cpp $(IntermediateDirectory)/InGameContext.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Darth/Documents/Workspaces/CodeLite/GitHubWorkspace/FlipColors/InGameContext.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/InGameContext.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/InGameContext.cpp$(DependSuffix): InGameContext.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/InGameContext.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/InGameContext.cpp$(DependSuffix) -MM "InGameContext.cpp"

$(IntermediateDirectory)/InGameContext.cpp$(PreprocessSuffix): InGameContext.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/InGameContext.cpp$(PreprocessSuffix) "InGameContext.cpp"

$(IntermediateDirectory)/Utils.cpp$(ObjectSuffix): Utils.cpp $(IntermediateDirectory)/Utils.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Darth/Documents/Workspaces/CodeLite/GitHubWorkspace/FlipColors/Utils.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Utils.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Utils.cpp$(DependSuffix): Utils.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Utils.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Utils.cpp$(DependSuffix) -MM "Utils.cpp"

$(IntermediateDirectory)/Utils.cpp$(PreprocessSuffix): Utils.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Utils.cpp$(PreprocessSuffix) "Utils.cpp"

$(IntermediateDirectory)/Graphics.cpp$(ObjectSuffix): Graphics.cpp $(IntermediateDirectory)/Graphics.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Darth/Documents/Workspaces/CodeLite/GitHubWorkspace/FlipColors/Graphics.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Graphics.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Graphics.cpp$(DependSuffix): Graphics.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Graphics.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Graphics.cpp$(DependSuffix) -MM "Graphics.cpp"

$(IntermediateDirectory)/Graphics.cpp$(PreprocessSuffix): Graphics.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Graphics.cpp$(PreprocessSuffix) "Graphics.cpp"

$(IntermediateDirectory)/Background.cpp$(ObjectSuffix): Background.cpp $(IntermediateDirectory)/Background.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Darth/Documents/Workspaces/CodeLite/GitHubWorkspace/FlipColors/Background.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Background.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Background.cpp$(DependSuffix): Background.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Background.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Background.cpp$(DependSuffix) -MM "Background.cpp"

$(IntermediateDirectory)/Background.cpp$(PreprocessSuffix): Background.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Background.cpp$(PreprocessSuffix) "Background.cpp"

$(IntermediateDirectory)/GamePlay.cpp$(ObjectSuffix): GamePlay.cpp $(IntermediateDirectory)/GamePlay.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Darth/Documents/Workspaces/CodeLite/GitHubWorkspace/FlipColors/GamePlay.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/GamePlay.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/GamePlay.cpp$(DependSuffix): GamePlay.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/GamePlay.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/GamePlay.cpp$(DependSuffix) -MM "GamePlay.cpp"

$(IntermediateDirectory)/GamePlay.cpp$(PreprocessSuffix): GamePlay.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/GamePlay.cpp$(PreprocessSuffix) "GamePlay.cpp"

$(IntermediateDirectory)/AI.cpp$(ObjectSuffix): AI.cpp $(IntermediateDirectory)/AI.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Darth/Documents/Workspaces/CodeLite/GitHubWorkspace/FlipColors/AI.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/AI.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/AI.cpp$(DependSuffix): AI.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/AI.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/AI.cpp$(DependSuffix) -MM "AI.cpp"

$(IntermediateDirectory)/AI.cpp$(PreprocessSuffix): AI.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/AI.cpp$(PreprocessSuffix) "AI.cpp"

$(IntermediateDirectory)/PassDialog.cpp$(ObjectSuffix): PassDialog.cpp $(IntermediateDirectory)/PassDialog.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Darth/Documents/Workspaces/CodeLite/GitHubWorkspace/FlipColors/PassDialog.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/PassDialog.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/PassDialog.cpp$(DependSuffix): PassDialog.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/PassDialog.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/PassDialog.cpp$(DependSuffix) -MM "PassDialog.cpp"

$(IntermediateDirectory)/PassDialog.cpp$(PreprocessSuffix): PassDialog.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/PassDialog.cpp$(PreprocessSuffix) "PassDialog.cpp"

$(IntermediateDirectory)/MyLog.cpp$(ObjectSuffix): MyLog.cpp $(IntermediateDirectory)/MyLog.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Darth/Documents/Workspaces/CodeLite/GitHubWorkspace/FlipColors/MyLog.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/MyLog.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/MyLog.cpp$(DependSuffix): MyLog.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/MyLog.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/MyLog.cpp$(DependSuffix) -MM "MyLog.cpp"

$(IntermediateDirectory)/MyLog.cpp$(PreprocessSuffix): MyLog.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/MyLog.cpp$(PreprocessSuffix) "MyLog.cpp"

$(IntermediateDirectory)/LogFile.cpp$(ObjectSuffix): LogFile.cpp $(IntermediateDirectory)/LogFile.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Darth/Documents/Workspaces/CodeLite/GitHubWorkspace/FlipColors/LogFile.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/LogFile.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/LogFile.cpp$(DependSuffix): LogFile.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/LogFile.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/LogFile.cpp$(DependSuffix) -MM "LogFile.cpp"

$(IntermediateDirectory)/LogFile.cpp$(PreprocessSuffix): LogFile.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/LogFile.cpp$(PreprocessSuffix) "LogFile.cpp"

$(IntermediateDirectory)/wxformbuilder.cpp$(ObjectSuffix): wxformbuilder.cpp $(IntermediateDirectory)/wxformbuilder.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Darth/Documents/Workspaces/CodeLite/GitHubWorkspace/FlipColors/wxformbuilder.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/wxformbuilder.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/wxformbuilder.cpp$(DependSuffix): wxformbuilder.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/wxformbuilder.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/wxformbuilder.cpp$(DependSuffix) -MM "wxformbuilder.cpp"

$(IntermediateDirectory)/wxformbuilder.cpp$(PreprocessSuffix): wxformbuilder.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/wxformbuilder.cpp$(PreprocessSuffix) "wxformbuilder.cpp"

$(IntermediateDirectory)/LicensesDialog.cpp$(ObjectSuffix): LicensesDialog.cpp $(IntermediateDirectory)/LicensesDialog.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Darth/Documents/Workspaces/CodeLite/GitHubWorkspace/FlipColors/LicensesDialog.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/LicensesDialog.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/LicensesDialog.cpp$(DependSuffix): LicensesDialog.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/LicensesDialog.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/LicensesDialog.cpp$(DependSuffix) -MM "LicensesDialog.cpp"

$(IntermediateDirectory)/LicensesDialog.cpp$(PreprocessSuffix): LicensesDialog.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/LicensesDialog.cpp$(PreprocessSuffix) "LicensesDialog.cpp"

$(IntermediateDirectory)/BSDLicenseDialog.cpp$(ObjectSuffix): BSDLicenseDialog.cpp $(IntermediateDirectory)/BSDLicenseDialog.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Darth/Documents/Workspaces/CodeLite/GitHubWorkspace/FlipColors/BSDLicenseDialog.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/BSDLicenseDialog.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/BSDLicenseDialog.cpp$(DependSuffix): BSDLicenseDialog.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/BSDLicenseDialog.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/BSDLicenseDialog.cpp$(DependSuffix) -MM "BSDLicenseDialog.cpp"

$(IntermediateDirectory)/BSDLicenseDialog.cpp$(PreprocessSuffix): BSDLicenseDialog.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/BSDLicenseDialog.cpp$(PreprocessSuffix) "BSDLicenseDialog.cpp"

$(IntermediateDirectory)/win_resources.rc$(ObjectSuffix): win_resources.rc
	$(RcCompilerName) -i "C:/Users/Darth/Documents/Workspaces/CodeLite/GitHubWorkspace/FlipColors/win_resources.rc" $(RcCmpOptions)   $(ObjectSwitch)$(IntermediateDirectory)/win_resources.rc$(ObjectSuffix) $(RcIncludePath)

-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


