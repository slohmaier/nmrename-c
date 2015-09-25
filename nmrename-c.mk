##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=nmrename-c
ConfigurationName      :=Debug
WorkspacePath          := "/Users/stefan/Projects"
ProjectPath            := "/Users/stefan/Projects/nmrename-c"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Stefan Lohmaier
Date                   :=25/09/2015
CodeLitePath           :="/Users/stefan/Library/Application Support/codelite"
LinkerName             :=/usr/bin/clang++
SharedObjectLinkerName :=/usr/bin/clang++ -dynamiclib -fPIC
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
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="nmrename-c.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/clang++
CC       := /usr/bin/clang
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/Applications/codelite.app/Contents/SharedSupport/
Objects0=$(IntermediateDirectory)/src_cmd.c$(ObjectSuffix) $(IntermediateDirectory)/src_funcs.c$(ObjectSuffix) $(IntermediateDirectory)/src_msg.c$(ObjectSuffix) $(IntermediateDirectory)/src_nmopt.c$(ObjectSuffix) $(IntermediateDirectory)/src_nmrename.c$(ObjectSuffix) $(IntermediateDirectory)/src_str.c$(ObjectSuffix) 



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
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/src_cmd.c$(ObjectSuffix): src/cmd.c $(IntermediateDirectory)/src_cmd.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/Users/stefan/Projects/nmrename-c/src/cmd.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_cmd.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_cmd.c$(DependSuffix): src/cmd.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_cmd.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_cmd.c$(DependSuffix) -MM "src/cmd.c"

$(IntermediateDirectory)/src_cmd.c$(PreprocessSuffix): src/cmd.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_cmd.c$(PreprocessSuffix) "src/cmd.c"

$(IntermediateDirectory)/src_funcs.c$(ObjectSuffix): src/funcs.c $(IntermediateDirectory)/src_funcs.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/Users/stefan/Projects/nmrename-c/src/funcs.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_funcs.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_funcs.c$(DependSuffix): src/funcs.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_funcs.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_funcs.c$(DependSuffix) -MM "src/funcs.c"

$(IntermediateDirectory)/src_funcs.c$(PreprocessSuffix): src/funcs.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_funcs.c$(PreprocessSuffix) "src/funcs.c"

$(IntermediateDirectory)/src_msg.c$(ObjectSuffix): src/msg.c $(IntermediateDirectory)/src_msg.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/Users/stefan/Projects/nmrename-c/src/msg.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_msg.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_msg.c$(DependSuffix): src/msg.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_msg.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_msg.c$(DependSuffix) -MM "src/msg.c"

$(IntermediateDirectory)/src_msg.c$(PreprocessSuffix): src/msg.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_msg.c$(PreprocessSuffix) "src/msg.c"

$(IntermediateDirectory)/src_nmopt.c$(ObjectSuffix): src/nmopt.c $(IntermediateDirectory)/src_nmopt.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/Users/stefan/Projects/nmrename-c/src/nmopt.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_nmopt.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_nmopt.c$(DependSuffix): src/nmopt.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_nmopt.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_nmopt.c$(DependSuffix) -MM "src/nmopt.c"

$(IntermediateDirectory)/src_nmopt.c$(PreprocessSuffix): src/nmopt.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_nmopt.c$(PreprocessSuffix) "src/nmopt.c"

$(IntermediateDirectory)/src_nmrename.c$(ObjectSuffix): src/nmrename.c $(IntermediateDirectory)/src_nmrename.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/Users/stefan/Projects/nmrename-c/src/nmrename.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_nmrename.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_nmrename.c$(DependSuffix): src/nmrename.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_nmrename.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_nmrename.c$(DependSuffix) -MM "src/nmrename.c"

$(IntermediateDirectory)/src_nmrename.c$(PreprocessSuffix): src/nmrename.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_nmrename.c$(PreprocessSuffix) "src/nmrename.c"

$(IntermediateDirectory)/src_str.c$(ObjectSuffix): src/str.c $(IntermediateDirectory)/src_str.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/Users/stefan/Projects/nmrename-c/src/str.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_str.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_str.c$(DependSuffix): src/str.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_str.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_str.c$(DependSuffix) -MM "src/str.c"

$(IntermediateDirectory)/src_str.c$(PreprocessSuffix): src/str.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_str.c$(PreprocessSuffix) "src/str.c"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


