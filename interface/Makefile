include $(ROOT)/$(CONFIG_FILE)
sub_NAME    =int
sub_DIR     =$(int_DIR)
sub_SRCDIR  =$(int_SRCDIR)
sub_HEADDIR =$(int_HEADDIR)


# === Units ===
c_SRC  =$(call FirstOrderSource,$(sub_SRCDIR),.c) 
c_HEAD =$(call FirstOrderSource,$(sub_HEADDIR),.h) 
c_OBJ  =$(call SourceToObject,$(c_SRC),$(obj_DIR))


# === Compiler ===
c_comp =$(CC)
c_flag =$(CC_flag) -c
c_inc  =-I$(sub_HEADDIR)


# === Build ===
subdirectory: $(obj_DIR) $(c_OBJ)

.SECONDEXPANSION:
$(c_OBJ): $(obj_DIR)/%.o: $(call NameToSource,%,$(c_SRC),.c) $(c_HEAD)
	@echo "=== Compiling <$(notdir $<)> in <$(sub_NAME)> ==="
	$(c_comp) $< $(c_flag) $(c_inc) -o $@


# --- Directory Management ---
$(obj_DIR):
	@mkdir -p $(obj_DIR)

clean:
	@echo "=== Cleaning <$(sub_NAME)> ==="
	rm -f $(obj_DIR)/*.o

.PHONY: subdirectory clean
