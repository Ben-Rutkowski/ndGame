CONFIG_FILE ?=.config.mk
ROOT        ?=$(CURDIR)


# ================ Source Directories ================
# --- app ---
app_DIR     =$(ROOT)/application_macOS
app_SRCDIR  =$(app_DIR)/src
app_HEADDIR =$(app_DIR)/header
app_OBJDIR  =$(app_DIR)/$(obj_DIR)

# --- lib ---
lib_DIR     =$(ROOT)/lib
lib_SRCDIR  =$(lib_DIR)/src
lib_HEADDIR =$(lib_DIR)/header
lib_OBJDIR  =$(lib_DIR)/$(obj_DIR)

# --- mod ---
mod_DIR     =$(ROOT)/modules
mod_SRCDIR  =$(mod_DIR)/src
mod_HEADDIR =$(mod_DIR)/header
mod_OBJDIR  =$(mod_DIR)/$(obj_DIR)

# --- shd ---
shd_DIR     =$(ROOT)/shaders
shd_SRCDIR  =$(shd_DIR)/
shd_HEADDIR =$(shd_DIR)/
shd_OBJDIR  =$(shd_DIR)/$(obj_DIR)

# --- int ---
int_DIR     =$(ROOT)/interface
int_SRCDIR  =$(int_DIR)
int_HEADDIR =$(int_DIR)
int_OBJDIR  =$(int_DIR)/$(obj_DIR)


# ================ Common Variables ================
obj_DIR =objects

tst_DIR  =$(ROOT)/test
bld_DIR  =$(ROOT)/build
bld_NAME =ndGame_DEBUG


# ================ Compiler ================
COMMON_flag =-Wall -fdiagnostics-color=always -g
COMMON_link =-framework AppKit

CXX 	 =clang++
CXX_flag =$(COMMON_flag) -std=c++20
CXX_link =$(COMMON_link)

CC      =clang
CC_flag =$(COMMON_flag)
CC_link =$(COMMON_link)

CCOBJ      =clang
CCOBJ_flag =$(COMMON_flag)
CCOBJ_link  =$(COMMON_link)


# --- Macros ---
#     :Prepend:
# Prepends a directory to every object in a list
define Prepend # $1 prepend directory; $2 object list
	$(patsubst %,$1/%,$2)
endef

#     :RecurMake:
# Recursively call make in a given directory with the given 
# build commands; will carry the proper config file and root path
define RecurMake # $1 subdirectory; $2 build command
	$(MAKE) -C $1 $2 CONFIG_FILE=$(CONFIG_FILE) ROOT=$(ROOT)
endef

#     :RecurObject:
# Recursively calls make from a given object file with 
# full path
define RecurObject # $1 object file (full path)
	$(MAKE) -C \
		$(patsubst %/$(obj_DIR)/,%,$(dir $1)) \
		$(patsubst %,$(obj_DIR)/%,$(notdir $1)) \
		CONFIG_FILE=$(CONFIG_FILE) ROOT=$(ROOT)
endef

#     :FirstOrderSource:
# Finds all the sources in a given directory
define FirstOrderSource # $1 base dir; $2 extension
	$(wildcard $1/*$2)
endef

#     :SecondOrderSource:
# Finds all of the sources in each directory in the given directory
# with the given extension
define SecondOrderSource # $1 base dir; $2 extension
	$(foreach dir,$(wildcard $1/*/), \
		$(wildcard $(dir)*$2) \
	)
endef

#     :NameToSource: (SECONDEXPANSION)
# Takes ONE name of a unit and returns the source file;
# if there are multiple sources with the same name, returns all of them
define NameToSource # $1 name; $2 source list; $3 extension
	$$(foreach dir,$$(dir $2), \
		$$(filter \
			$$(dir)$1$3, \
			$2 \
		) \
	)
endef

#     :SourceToObject:
# Takes a LIST of sources and returns a list of objects with the same name
# but in the given object directory
define SourceToObject # $1 source list; $2 object dir
	$(patsubst %,$2/%.o, \
		$(basename $(notdir $1)) \
	)
endef

#     :GetObjectsFilter:
# Takes a list of subdirectories and returns all of the objects
# in each subdirectory's $(obj_DIR) directory EXECPT those objects
# that have the same name as one in the filter list
# define GetObjectsFilter # $1 list of subdirectories; $2 filtered out objects
define GetObjectsFilter # $1 list of subdirectories; $2 filtered out objects
	$(filter-out \
		$(foreach obj,$2,%/$(notdir $(obj))), \
		$(foreach dr,$1,$(wildcard $(dr)/$(obj_DIR)/*.o)) \
	)
endef
