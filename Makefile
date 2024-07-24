include .config.mk
all_OBJDIR =$(mod_OBJDIR) $(int_OBJDIR) $(lib_OBJDIR) $(app_OBJDIR)
all_NAME   =mod int lib app


# === Units ===
OBJ =$(patsubst %,%/*.o,$(all_OBJDIR))

# === Compiler ===
comp =$(CXX)
flag =$(CXX_flag)
link =$(CXX_link)


# === Build ===
$(bld_DIR)/$(bld_NAME): $(all_NAME)
	@mkdir -p $(bld_DIR)
	@echo "=== Linking Build ==="
	$(comp) $(OBJ) $(flag) $(link) -o $(bld_DIR)/$(bld_NAME)

app:
	$(call RecurMake,$(app_DIR),)

int:
	$(call RecurMake,$(int_DIR),)

lib:
	$(call RecurMake,$(lib_DIR),)

mod:
	$(call RecurMake,$(mod_DIR),)

# shd:
# 	$(call RecurMake,$(shd_DIR),)


# === Directory Management ===
clean:
	$(call RecurMake,$(app_DIR),clean)
	$(call RecurMake,$(int_DIR),clean)
	$(call RecurMake,$(lib_DIR),clean)
	$(call RecurMake,$(mod_DIR),clean)
#	$(call RecurMake,$(shd_DIR),clean)

	@echo "--- Cleaning Build ---"
	rm -f $(bld_DIR)/$(bld_NAME)

.PHONY: clean $(all_NAME)
