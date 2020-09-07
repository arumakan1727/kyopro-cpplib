template_base_file := template-prototype.cpp
template_base_file_dir := $(dir ${template_base_file})
template_export_file := template.cpp
template_base_file_dependencies := $(addprefix ${template_base_file_dir}, \
	$(shell egrep -e '#\s*include\s*".+"' ${template_base_file} | sed -r 's|#\s*include\s*"(.+)"|\1|'))

snip_file := snippet.vscode.json
snip_root_dirs := ../Algorithm ../Data-Structure ../Graph ../Math ../String ../Util
snip_ignore_dirs := 
snip_ignore_find_opts := $(patsubst %, -type d -name % -prune -o, ${snip_ignore_dirs})
snip_glob := '*.hpp'
snip_dependencies := $(shell find ${snip_root_dirs} ${snip_ignore_find_opts} -type f -name ${snip_glob} -print)

short_snip_file := short-snippet.vscode.json
short_snip_root_dir := ../short-snip-src
short_snip_glob := '*.cpp'
short_snip_dependencies := $(shell find ${short_snip_root_dir} -type f -name ${short_snip_glob})


.PHONY:	all variables

all:	\
	${template_export_file} \
	${snip_file} \
	${short_snip_file}


${template_export_file}: ${template_base_file} ${template_base_file_dependencies}
	expand-include $< > $@


${snip_file}:	${snip_dependencies}
	gen-snippet -glob ${snip_glob} $(patsubst %, -ignore %, ${snip_ignore_dirs}) ${snip_root_dirs} > $@


${short_snip_file}:	${short_snip_dependencies}
	gen-snippet -glob ${short_snip_glob} -snippet-all-lines ${short_snip_root_dir} > $@


define dump_var
	@echo -e "${1}:\n    $(value ${1})"
endef

variables:
	$(call dump_var,template_base_file)
	$(call dump_var,template_base_file_dir)
	$(call dump_var,template_export_file)
	$(call dump_var,template_base_file_dependencies)
	@echo ""
	$(call dump_var,snip_file)
	$(call dump_var,snip_root_dirs)
	$(call dump_var,snip_ignore_dirs)
	$(call dump_var,snip_ignore_find_opts)
	$(call dump_var,snip_dependencies)
	@echo ""
	$(call dump_var,short_snip_file)
	$(call dump_var,short_snip_root_dir)
	$(call dump_var,short_snip_dependencies)
