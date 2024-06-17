include .config.mk
all_OBJDIR =$(mod_OBJDIR)
all_NAME   =mod


# === Units ===
OBJ =$(patsubst %,%/*.o,$(all_OBJDIR))

# === Compiler ===
comp =$(CXX)
flag =$(CXX_flag)
inc  =
link =


# === Build ===
$(bld_DIR)/$(bld_NAME): $(all_NAME)
	@mkdir -p $(bld_DIR)
	@echo "=== Linking Build ==="
	$(comp) $(OBJ) $(flag) $(inc) $(link) -o $(bld_DIR)/$(bld_NAME)

# app:
# 	$(call RecurMake,$(app_DIR),)
# 
# lib:
# 	$(call RecurMake,$(lib_DIR),)

mod:
	$(call RecurMake,$(mod_DIR),)

# shd:
# 	$(call RecurMake,$(shd_DIR),)


# === Directory Management ===
clean:
# 	$(call RecurMake,$(app_DIR),clean)
# 	$(call RecurMake,$(lib_DIR),clean)
	$(call RecurMake,$(mod_DIR),clean)
#	$(call RecurMake,$(shd_DIR),clean)

	@echo "--- Cleaning Build ---"
	rm -f $(bld_DIR)/$(bld_NAME)

.PHONY: clean $(all_NAME)
