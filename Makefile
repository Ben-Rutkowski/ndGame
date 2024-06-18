include .config.mk
all_OBJDIR =$(mod_OBJDIR) $(int_OBJDIR)
all_NAME   =mod int


# === Units ===
OBJ =$(patsubst %,%/*.o,$(all_OBJDIR))

# === Compiler ===
comp =$(CXX)
flag =$(CXX_flag)
link =


# === Build ===
$(bld_DIR)/$(bld_NAME): $(all_NAME)
	@mkdir -p $(bld_DIR)
	@echo "=== Linking Build ==="
	$(comp) $(OBJ) $(flag) $(link) -o $(bld_DIR)/$(bld_NAME)

# app:
# 	$(call RecurMake,$(app_DIR),)
# 
# lib:
# 	$(call RecurMake,$(lib_DIR),)

mod:
	$(call RecurMake,$(mod_DIR),)

# shd:
# 	$(call RecurMake,$(shd_DIR),)

int:
	$(call RecurMake,$(int_DIR),)


# === Directory Management ===
clean:
# 	$(call RecurMake,$(app_DIR),clean)
# 	$(call RecurMake,$(lib_DIR),clean)
	$(call RecurMake,$(mod_DIR),clean)
#	$(call RecurMake,$(shd_DIR),clean)
	$(call RecurMake,$(int_DIR),clean)

	@echo "--- Cleaning Build ---"
	rm -f $(bld_DIR)/$(bld_NAME)

.PHONY: clean $(all_NAME)
