include $(ROOT)/$(CONFIG_FILE)
sub_NAME    =lib
sub_DIR     =$(lib_DIR)
sub_SRCDIR  =$(lib_SRCDIR)
sub_HEADDIR =$(lib_HEADDIR)


# === Units ===
SRC  =$(call FirstOrderSource,$(sub_SRCDIR),.cpp) 
HEAD =$(call FirstOrderSource,$(sub_HEADDIR),.h) $(call FirstOrderSource,$(sub_HEADDIR),.hpp) 
OBJ  =$(call SourceToObject,$(SRC),$(obj_DIR))


# === Compiler ===
comp =$(CXX)
flag =$(CXX_flag) -c
inc  =-I$(sub_HEADDIR) -I$(int_HEADDIR)


# === Build ===
subdirectory: $(obj_DIR) $(OBJ)

.SECONDEXPANSION:
$(OBJ): $(obj_DIR)/%.o: $(call NameToSource,%,$(SRC),.cpp) $(HEAD)
	@echo "=== Compiling <$(notdir $<)> in <$(sub_NAME)> ==="
	$(comp) $< $(flag) $(inc) -o $@


# --- Directory Management ---
$(obj_DIR):
	@mkdir -p $(obj_DIR)

clean:
	@echo "=== Cleaning <$(sub_NAME)> ==="
	rm -f $(obj_DIR)/*.o

.PHONY: subdirectory clean
