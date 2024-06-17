include $(ROOT)/$(CONFIG_FILE)
sub_NAME    =shd
sub_DIR     =$(shd_DIR)
sub_SRCDIR  =$(shd_SRCDIR)
sub_HEADDIR =$(shd_HEADDIR)


# === Units ===
# SRC  =$(call FirstOrderSource,$(sub_SRCDIR),.---) 
# HEAD =$(call FirstOrderSource,$(sub_HEADDIR),.---) 
OBJ  =$(call SourceToObject,$(SRC),$(obj_DIR))


# === Compiler ===
comp =$(CXX)
flag =$(CXX_flag) -c
inc  =-I$(sub_HEADDIR)


# === Build ===
subdirectory: $(obj_DIR) $(OBJ)

.SECONDEXPANSION:
# $(OBJ): $(obj_DIR)/%.o: $(call NameToSource,%,$(SRC),.---) $(HEAD)
# 	@echo "=== Compiling <$(notdir $<)> in <$(sub_NAME)> ==="
# 	$(comp) $< $(flag) $(inc) -o $@


# --- Directory Management ---
$(obj_DIR):
	@mkdir -p $(obj_DIR)

clean:
	@echo "=== Cleaning <$(sub_NAME)> ==="
	rm -f $(obj_DIR)/*.o

.PHONY: subdirectory clean
