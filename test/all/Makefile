include $(ROOT)/$(CONFIG_FILE)
# sub_DIR     =
# sub_HEADDIR =


# === Units ===
test_SRC =$(call FirstOrderSource,$(CURDIR),.cpp) 
test_OBJ =$(call SourceToObject,$(test_SRC),$(obj_DIR))

# sub_OBJ =$(call GetObjectsFilter,$(sub_DIR),$(test_OBJ))


# === Compiler ===
comp_unit =$(CXX)
flag_unit =$(CXX_flag) -c
inc_unit  =-I$(int_HEADDIR)

comp_test =$(CXX)
flag_test =$(CXX_flag)
link_test =


# === Build ===
test: $(obj_DIR) $(test_OBJ) $(sub_OBJ)
	@echo "--- Linking Test Case ---"
	$(comp_test) $(test_OBJ) $(sub_OBJ) $(flag_test) $(inc_test) $(link_test) -o $@

.SECONDEXPANSION:
$(test_OBJ): $(obj_DIR)/%.o: $(call NameToSource,%,$(test_SRC),.cpp)
	@echo "--- Compiling Test Object <$(notdir $<)> ---"
	$(comp_unit) $< $(flag_unit) $(inc_unit) -o $@

# $(sub_OBJ):
# 	$(call RecurObject,$@)


# --- Directory Management ---
$(obj_DIR):
	@mkdir -p $(obj_DIR)
