include $(ROOT)/$(CONFIG_FILE)
sub_NAME    =app
sub_DIR     =$(app_DIR)
sub_SRCDIR  =$(app_SRCDIR)
sub_HEADDIR =$(app_HEADDIR)


# === Units ===
SRC  =$(call FirstOrderSource,$(sub_SRCDIR),.m) 
HEAD =$(call FirstOrderSource,$(sub_HEADDIR),.h) 
OBJ  =$(call SourceToObject,$(SRC),$(obj_DIR))


# === Compiler ===
comp =$(CCOBJ)
flag =$(CCOBJ_flag) -c
inc  =-I$(sub_HEADDIR) -I$(int_HEADDIR)


# === Build ===
subdirectory: $(obj_DIR) $(OBJ)

.SECONDEXPANSION:
$(OBJ): $(obj_DIR)/%.o: $(call NameToSource,%,$(SRC),.m) $(HEAD)
	@echo "=== Compiling <$(notdir $<)> in <$(sub_NAME)> ==="
	$(comp) $< $(flag) $(inc) -o $@


# --- Directory Management ---
$(obj_DIR):
	@mkdir -p $(obj_DIR)

clean:
	@echo "=== Cleaning <$(sub_NAME)> ==="
	rm -f $(obj_DIR)/*.o

.PHONY: subdirectory clean
