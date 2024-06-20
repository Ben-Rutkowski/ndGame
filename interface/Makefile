include $(ROOT)/$(CONFIG_FILE)
sub_NAME    =int
sub_DIR     =$(int_DIR)
sub_SRCDIR  =$(int_SRCDIR)
sub_HEADDIR =$(int_HEADDIR)


# === Units ===
c_SRC  =$(call FirstOrderSource,$(sub_SRCDIR),.c) 
c_HEAD =$(call FirstOrderSource,$(sub_HEADDIR),.h) 
c_OBJ  =$(call SourceToObject,$(c_SRC),$(obj_DIR))

cpp_SRC  =$(call FirstOrderSource,$(sub_SRCDIR),.cpp) 
cpp_HEAD =$(call FirstOrderSource,$(sub_HEADDIR),.hpp) 
cpp_OBJ  =$(call SourceToObject,$(cpp_SRC),$(obj_DIR))

objcpp_SRC  =$(call FirstOrderSource,$(sub_SRCDIR),.mm) 
objcpp_HEAD =$(call FirstOrderSource,$(sub_HEADDIR),.h) 
objcpp_OBJ  =$(call SourceToObject,$(objcpp_SRC),$(obj_DIR))


# === Compiler ===
c_comp =$(CC)
c_flag =$(CC_flag) -c
c_inc  =-I$(sub_HEADDIR)

cpp_comp =$(CXX)
cpp_flag =$(CXX_flag) -c
cpp_inc  =-I$(sub_HEADDIR)

objcpp_comp =$(CXX)
objcpp_flag =$(CXX_flag) -c
objcpp_inc  =-I$(sub_HEADDIR) -I$(app_HEADDIR)


# === Build ===
subdirectory: $(obj_DIR) $(c_OBJ) $(cpp_OBJ) $(objcpp_OBJ)

.SECONDEXPANSION:
$(c_OBJ): $(obj_DIR)/%.o: $(call NameToSource,%,$(c_SRC),.c) $(c_HEAD)
	@echo "=== Compiling <$(notdir $<)> in <$(sub_NAME)> ==="
	$(c_comp) $< $(c_flag) $(c_inc) -o $@

$(cpp_OBJ): $(obj_DIR)/%.o: $(call NameToSource,%,$(cpp_SRC),.cpp) $(cpp_HEAD)
	@echo "=== Compiling <$(notdir $<)> in <$(sub_NAME)> ==="
	$(cpp_comp) $< $(cpp_flag) $(cpp_inc) -o $@

$(objcpp_OBJ): $(obj_DIR)/%.o: $(call NameToSource,%,$(objcpp_SRC),.mm) $(objcpp_HEAD)
	@echo "=== Compiling <$(notdir $<)> in <$(sub_NAME)> ==="
	$(objcpp_comp) $< $(objcpp_flag) $(objcpp_inc) -o $@


# --- Directory Management ---
$(obj_DIR):
	@mkdir -p $(obj_DIR)

clean:
	@echo "=== Cleaning <$(sub_NAME)> ==="
	rm -f $(obj_DIR)/*.o

.PHONY: subdirectory clean
